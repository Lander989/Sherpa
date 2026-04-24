import java.util.*;

class GPSPoint {
  float lat, lon;
  GPSPoint(float lat, float lon) {
    this.lat = lat;
    this.lon = lon;
  }
}

ArrayList<GPSPoint> path = new ArrayList<GPSPoint>();

int currentIndex = 0;

// smooth movement
float t = 0;
float segmentDuration = 2.5; // slower walking (seconds per segment)

// timing
int lastTime;

// bounds
float minLat, maxLat, minLon, maxLon;

// special points
HashSet<Integer> markerPoints = new HashSet<Integer>();
int hazardPoint = -1;

// pause system
boolean isPaused = false;
int pauseStartTime = 0;
int pauseDuration = 5000;

// start + end
boolean started = false;
int startTime;
boolean arrived = false;

// arrow
float lastBearing = 0;

// confetti
ArrayList<PVector> confetti = new ArrayList<PVector>();

void setup() {
  size(900, 700);

  // --- GPS DATA ---
  path.add(new GPSPoint(50.822040450878426, 3.2502464605204984));
  path.add(new GPSPoint(50.82237933663994, 3.249940688686364));
  path.add(new GPSPoint(50.822684331722385, 3.2496992898699424));
  path.add(new GPSPoint(50.822826662079045, 3.249500806398663));
  path.add(new GPSPoint(50.82285716138475, 3.249586637088946));
  path.add(new GPSPoint(50.82291477113003, 3.2497314763787988));
  path.add(new GPSPoint(50.822962214396306, 3.2498387647416527));
  path.add(new GPSPoint(50.822996102414145, 3.249870951250509));
  path.add(new GPSPoint(50.82309723900426, 3.249898945395055));
  path.add(new GPSPoint(50.82322695195826, 3.2499200053235073));
  path.add(new GPSPoint(50.823293471282085, 3.2499305352877332));
  path.add(new GPSPoint(50.82335500157222, 3.2499410652519596));
  path.add(new GPSPoint(50.82329513426395, 3.2499989800552043));
  path.add(new GPSPoint(50.8232435817981, 3.2500516298763356));
  path.add(new GPSPoint(50.82319369226083, 3.2501358695901454));
  path.add(new GPSPoint(50.82317041045854, 3.2501806219381066));
  path.add(new GPSPoint(50.823113868890296, 3.250238536741351));
  path.add(new GPSPoint(50.82311054291359, 3.2502648616519165));
  path.add(new GPSPoint(50.82309391302635, 3.250267494142973));
  path.add(new GPSPoint(50.823050675291846, 3.250293819053539));
  path.add(new GPSPoint(50.8230224044438, 3.250330673928331));
  path.add(new GPSPoint(50.823055221824674, 3.250352519975319));
  path.add(new GPSPoint(50.82308923937563, 3.2504386789155184));
  path.add(new GPSPoint(50.82307563235823, 3.250527530322598));
  path.add(new GPSPoint(50.82305182006824, 3.250702540669877));
  path.add(new GPSPoint(50.82299228929007, 3.250772544808788));
  path.add(new GPSPoint(50.822990588409574, 3.2508371640139373));
  path.add(new GPSPoint(50.82299228929007, 3.2508910133515614));
  path.add(new GPSPoint(50.82298548576771, 3.2509287078878986));
  path.add(new GPSPoint(50.82298038312531, 3.2509637099573543));
  path.add(new GPSPoint(50.822963374313275, 3.251014866828097));
  path.add(new GPSPoint(50.822888535466696, 3.251090255900771));
  path.add(new GPSPoint(50.82281709827396, 3.2510956408345337));
  path.add(new GPSPoint(50.8227813796366, 3.251049868897553));
  path.add(new GPSPoint(50.82275246452921, 3.250990634626166));
  path.add(new GPSPoint(50.82272865207436, 3.2509448626891855));
  path.add(new GPSPoint(50.82273885741366, 3.2508910133515614));
  path.add(new GPSPoint(50.822735455634145, 3.2508452414145808));
  path.add(new GPSPoint(50.82275416541835, 3.250810239345125));
  path.add(new GPSPoint(50.82272525029411, 3.2507779297425508));
  path.add(new GPSPoint(50.822657214637005, 3.25073215780557));
  path.add(new GPSPoint(50.822631701240034, 3.2507160030042828));
  path.add(new GPSPoint(50.82259258067093, 3.250707925603639));
  path.add(new GPSPoint(50.82257727261324, 3.250705233136758));
  path.add(new GPSPoint(50.822470116068814, 3.250707925603639));
  path.add(new GPSPoint(50.822427593562395, 3.250697155736114));
  path.add(new GPSPoint(50.82234084752921, 3.250734850272451));
  path.add(new GPSPoint(50.82230002581077, 3.250745620139976));
  path.add(new GPSPoint(50.82227111040526, 3.250767159875026));
  path.add(new GPSPoint(50.82225920405662, 3.2507510050737385));
  path.add(new GPSPoint(50.82224219498187, 3.2506756160010646));
  path.add(new GPSPoint(50.82220307408642, 3.2505948419946282));
  path.add(new GPSPoint(50.822167354979356, 3.2505140679881923));

  // markers + hazard
  markerPoints.add(5);
  markerPoints.add(15);
  markerPoints.add(30);
  hazardPoint = 40;

  computeBounds();
  startTime = millis();
  lastTime = millis();
}

// --- UTILITIES ---
void computeBounds() {
  minLat=maxLat=path.get(0).lat;
  minLon=maxLon=path.get(0).lon;
  for(GPSPoint p:path){
    minLat=min(minLat,p.lat);
    maxLat=max(maxLat,p.lat);
    minLon=min(minLon,p.lon);
    maxLon=max(maxLon,p.lon);
  }
}

PVector gpsToScreen(GPSPoint p) {
  float x = map(p.lon, minLon, maxLon, 50, width - 50);
  float y = map(p.lat, minLat, maxLat, height - 50, 50);
  return new PVector(x, y);
}

float calculateBearing(GPSPoint a, GPSPoint b){
  float lat1=radians(a.lat), lat2=radians(b.lat);
  float dLon=radians(b.lon-a.lon);
  float y=sin(dLon)*cos(lat2);
  float x=cos(lat1)*sin(lat2)-sin(lat1)*cos(lat2)*cos(dLon);
  return (degrees(atan2(y,x))+360)%360;
}

// --- MAIN DRAW ---
void draw(){
  background(250);

  float dt=(millis()-lastTime)/1000.0;
  lastTime=millis();

  if(!started && millis()-startTime>2000) started=true;

  // path
  stroke(0);
  noFill();
  beginShape();
  for(GPSPoint p:path){
    PVector v=gpsToScreen(p);
    vertex(v.x,v.y);
  }
  endShape();

  // special points
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

  // next waypoint
  fill(255,140,0);
  ellipse(pb.x,pb.y,10,10);

  if(!isPaused && started){
    lastBearing=calculateBearing(a,b);
  }

  drawArrow(width-100,height-100,lastBearing);

  // movement
  if(started && !arrived && !isPaused){
    t += dt / segmentDuration;

    if(t>=1){
      t=0;
      currentIndex++;

      if(currentIndex>=path.size()-1){
        arrived=true;
        createConfetti();
      }

      if(markerPoints.contains(currentIndex)||currentIndex==hazardPoint){
        isPaused=true;
        pauseStartTime=millis();
      }
    }
  }

  if(isPaused && millis()-pauseStartTime>pauseDuration){
    isPaused=false;
  }

  drawConfetti();
  drawLegend();
}

// --- STICKMAN ---
void drawStickman(float x, float y, boolean isMoving){
  stroke(0);

  // head = blue dot
  fill(0,120,255);
  ellipse(x, y-10, 10, 10);

  line(x, y-5, x, y+12);

  float walk = isMoving ? sin(frameCount*0.1)*8 : 0;

  line(x,y,x-8,y+walk);
  line(x,y,x+8,y-walk);

  line(x,y+12,x-6,y+22+walk);
  line(x,y+12,x+6,y+22-walk);
}

// --- ARROW ---
void drawArrow(float x,float y,float angle){
  pushMatrix();
  translate(x,y);
  rotate(radians(angle));
  fill(40);
  beginShape();
  vertex(0,-30);
  vertex(-10,10);
  vertex(10,10);
  endShape(CLOSE);
  popMatrix();

  fill(0);
  textAlign(CENTER);
  text(int(angle)+"°",x,y+40);
}
void drawLegend(){
  int x = width - 240;
  int y = 20;

  // background panel (more breathing space)
  fill(255);
  stroke(0);
  rect(x, y, 220, 170, 10);

  textAlign(LEFT, CENTER);
  textSize(12);

  int rowY = y + 25;
  int spacing = 30;

  // helper layout: dot left, text right

  // PERSON
  fill(0,120,255);
  ellipse(x + 20, rowY, 10, 10);
  fill(0);
  text("Person (you)", x + 45, rowY);
  rowY += spacing;

  // NEXT POINT
  fill(255,140,0);
  ellipse(x + 20, rowY, 10, 10);
  fill(0);
  text("Next waypoint", x + 45, rowY);
  rowY += spacing;

  // MARKER
  fill(0,200,0);
  ellipse(x + 20, rowY, 10, 10);
  fill(0);
  text("Marker (pause 5s)", x + 45, rowY);
  rowY += spacing;

  // HAZARD
  fill(255,0,0);
  ellipse(x + 20, rowY, 10, 10);
  fill(0);
  text("Hazard (blink + pause)", x + 45, rowY);
  rowY += spacing;

  // ARROW INFO
  fill(50);
  text("Arrow shows heading (°)", x + 20, rowY);
}

// --- CONFETTI ---
void createConfetti(){
  for(int i=0;i<200;i++) confetti.add(new PVector(random(width),random(-200,0)));
}

void drawConfetti(){
  for(PVector c:confetti){
    fill(random(255),random(255),random(255));
    rect(c.x,c.y,4,4);
    c.y+=2;
  }
}