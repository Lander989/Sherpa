import java.util.*;
import processing.serial.*;

// --- ARDUINO SETTINGS ---
boolean useArduino = true; 
Serial myPort;

class GPSPoint {
  float lat, lon;
  GPSPoint(float lat, float lon) {
    this.lat = lat;
    this.lon = lon;
  }
}

// We use a standard ArrayList, but we will lock it when reading/writing
ArrayList<GPSPoint> path = new ArrayList<GPSPoint>();

float[][] rawCoordinates = {
  {50.822040450878426, 3.2502464605204984},
  {50.82237933663994,  3.249940688686364},
  {50.822684331722385, 3.2496992898699424}
};

int currentIndex = 0;
float t = 0;
float segmentDuration = 2.5;
int lastTime;
float minLat, maxLat, minLon, maxLon;

HashSet<Integer> markerPoints = new HashSet<Integer>();
int hazardPoint = -1;

boolean isPaused = false;
int pauseStartTime = 0;
int pauseDuration = 5000;

boolean started = false;
int startTime;
boolean arrived = false;
float lastBearing = 0;

ArrayList<PVector> confetti = new ArrayList<PVector>();

void setup() {
  size(900, 700);

  if (useArduino) {
    // 1. CRASH PREVENTION: Safe Port Selection
    String[] ports = Serial.list();
    if (ports.length == 0) {
      println("CRITICAL ERROR: No Arduino found! Plug it in and restart.");
      useArduino = false; // Fall back to simulation safely
    } else {
      try {
        // NOTE: You might need to change ports[0] to ports[1] or ports[2] 
        // depending on where your Arduino is plugged in.
        String portName = ports[0]; 
        myPort = new Serial(this, portName, 9600);
        myPort.bufferUntil('\n'); 
        println("Successfully connected to: " + portName);
      } catch (Exception e) {
        println("ERROR: Could not open port. Is the Serial Monitor open in the Arduino IDE? Close it!");
        useArduino = false;
      }
    }
  } 
  
  if (!useArduino) {
    // Simulation fallback
    for (int i = 0; i < rawCoordinates.length; i++) {
      path.add(new GPSPoint(rawCoordinates[i][0], rawCoordinates[i][1]));
    }
    markerPoints.add(1);
    hazardPoint = 2;
    computeBounds();
  }

  startTime = millis();
  lastTime = millis();
}

// 2. CRASH PREVENTION: Safe Serial Parsing & Thread Locking
void serialEvent(Serial myPort) {
  try {
    String inString = myPort.readStringUntil('\n');
    if (inString != null) {
      inString = trim(inString); 
      
      // Ignore empty strings to prevent array out of bounds
      if (inString.length() < 3) return; 
      
      String[] coords = split(inString, ','); 
      
      if (coords.length == 2) {
        float incomingLat = float(coords[0]);
        float incomingLon = float(coords[1]);
        
        // Prevent NaN (Not a Number) crashes if text was sent instead of numbers
        if (!Float.isNaN(incomingLat) && !Float.isNaN(incomingLon)) {
          
          // LOCK the path array so draw() can't read it while we add to it
          synchronized(path) {
            path.add(new GPSPoint(incomingLat, incomingLon));
            computeBounds();
          }
          println("Live Data: " + incomingLat + ", " + incomingLon);
        }
      }
    }
  } catch (Exception e) {
    // If absolutely anything goes wrong reading the text, catch it silently
    println("Skipped a corrupted data packet from Arduino.");
  }
}

void computeBounds() {
  if (path.size() == 0) return;
  minLat = maxLat = path.get(0).lat;
  minLon = maxLon = path.get(0).lon;
  for(GPSPoint p : path){
    minLat = min(minLat, p.lat);
    maxLat = max(maxLat, p.lat);
    minLon = min(minLon, p.lon);
    maxLon = max(maxLon, p.lon);
  }
  
  if (minLat == maxLat) { minLat -= 0.0001; maxLat += 0.0001; }
  if (minLon == maxLon) { minLon -= 0.0001; maxLon += 0.0001; }
}

PVector gpsToScreen(GPSPoint p) {
  float x = map(p.lon, minLon, maxLon, 50, width - 50);
  float y = map(p.lat, minLat, maxLat, height - 50, 50);
  return new PVector(x, y);
}

float calculateBearing(GPSPoint a, GPSPoint b){
  float lat1 = radians(a.lat), lat2 = radians(b.lat);
  float dLon = radians(b.lon - a.lon);
  float y = sin(dLon) * cos(lat2);
  float x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(dLon);
  return (degrees(atan2(y, x)) + 360) % 360;
}

void draw(){
  background(250);

  // 3. CRASH PREVENTION: Lock the path while drawing
  synchronized(path) {
    if (path.size() < 2) {
      fill(0);
      textAlign(CENTER, CENTER);
      text("Waiting for valid GPS data from Arduino...", width/2, height/2);
      return;
    }

    float dt=(millis()-lastTime)/1000.0;
    lastTime=millis();

    if(!started && millis()-startTime>2000) started=true;

    stroke(0);
    noFill();
    beginShape();
    for(GPSPoint p:path){
      PVector v=gpsToScreen(p);
      vertex(v.x,v.y);
    }
    endShape();

    for(int i=0;i<path.size();i++){
      PVector p=gpsToScreen(path.get(i));
      if(markerPoints.contains(i)){
        fill(0,200,0); ellipse(p.x,p.y,10,10);
      }
      if(i==hazardPoint && (millis()/300)%2==0){
        fill(255,0,0); ellipse(p.x,p.y,12,12);
      }
    }

    GPSPoint a=path.get(currentIndex);
    GPSPoint b=path.get(min(currentIndex+1,path.size()-1));

    PVector pa=gpsToScreen(a);
    PVector pb=gpsToScreen(b);

    PVector pos=PVector.lerp(pa,pb,t);

    boolean isMovingNow = started && !isPaused && !arrived;
    drawStickman(pos.x,pos.y,isMovingNow);

    fill(255,140,0);
    ellipse(pb.x,pb.y,10,10);

    if(!isPaused && started){
      lastBearing=calculateBearing(a,b);
    }

    drawArrow(width-100,height-100,lastBearing);

    if(started && !arrived && !isPaused){
      t += dt / segmentDuration;

      if(t>=1){
        t=0;
        if(currentIndex < path.size() - 2) {
          currentIndex++;
          
          if(markerPoints.contains(currentIndex)||currentIndex==hazardPoint){
            isPaused=true;
            pauseStartTime=millis();
          }
        } else if (!useArduino) {
          arrived=true;
          createConfetti();
        }
      }
    }
  } // End of synchronized block

  if(isPaused && millis()-pauseStartTime>pauseDuration){
    isPaused=false;
  }

  drawConfetti();
  drawLegend();
}

// --- UTILITIES (Stickman, Arrow, Legend, Confetti remain unchanged) ---
void drawStickman(float x, float y, boolean isMoving){
  stroke(0); fill(0,120,255); ellipse(x, y-10, 10, 10);
  line(x, y-5, x, y+12); float walk = isMoving ? sin(frameCount*0.1)*8 : 0;
  line(x,y,x-8,y+walk); line(x,y,x+8,y-walk); line(x,y+12,x-6,y+22+walk); line(x,y+12,x+6,y+22-walk);
}

void drawArrow(float x,float y,float angle){
  pushMatrix(); translate(x,y); rotate(radians(angle)); fill(40);
  beginShape(); vertex(0,-30); vertex(-10,10); vertex(10,10); endShape(CLOSE);
  popMatrix(); fill(0); textAlign(CENTER); text(int(angle)+"°",x,y+40);
}

void drawLegend(){
  int x = width - 240; int y = 20; fill(255); stroke(0); rect(x, y, 220, 170, 10);
  textAlign(LEFT, CENTER); textSize(12); int rowY = y + 25; int spacing = 30;
  fill(0,120,255); ellipse(x + 20, rowY, 10, 10); fill(0); text("Person (you)", x + 45, rowY); rowY += spacing;
  fill(255,140,0); ellipse(x + 20, rowY, 10, 10); fill(0); text("Next waypoint", x + 45, rowY); rowY += spacing;
  fill(0,200,0); ellipse(x + 20, rowY, 10, 10); fill(0); text("Marker (pause 5s)", x + 45, rowY); rowY += spacing;
  fill(255,0,0); ellipse(x + 20, rowY, 10, 10); fill(0); text("Hazard (blink + pause)", x + 45, rowY); rowY += spacing;
  fill(50); text("Arrow shows heading (°)", x + 20, rowY);
}

void createConfetti(){
  for(int i=0;i<200;i++) confetti.add(new PVector(random(width),random(-200,0)));
}

void drawConfetti(){
  for(PVector c:confetti){ fill(random(255),random(255),random(255)); rect(c.x,c.y,4,4); c.y+=2; }
}
