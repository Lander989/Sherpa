//Bibliotheken
#include <TinyGPSPlus.h>        //GPS module 
//#include <SoftwareSerial.h>   //Seriele communicatie
#include "AK09918.h"            //magnetometer
#include "ICM20600.h"           //Accelero en gyro
#include <Wire.h>               //i2C
//#include <MadgwickAHRS.h>     //filter om gyro accelo en magneto te combineren madgwick
#include <HardwareSerial.h>     
#include <ESP32Servo.h>         //servolibrary
#include <Arduino.h>      
#include <math.h>
#include <stdint.h>
#include "HapticPattern.h"      //trilmotor patronen
#include "OneButton.h"          //knoppen logica 



Servo Servo;                   //Servo object aanmaken

HapticPattern motor(5);        //trilmotor object aanmaken

static const int RXPin = 8, TXPin = 9;  //rx en tx pin voor gps
static const uint32_t GPSBaud = 9600;   //GPSBaud rate


TinyGPSPlus gps; // Het TinyGPSPlus object

// Het filter object
//Madgwick filter;


// The serial connection to the GPS device
//SoftwareSerial ss(); //

//Waar willen we naar toe
double TargetLat; 
double TargetLong;

//waar zijn we nu
double CurrentLat; 
double CurrentLong;

int Bearing = 0;             //Naar waar moeten we 0 360
int Heading;             //Naar waar kijken we 0 360
int SignedHeading;       //Naar waar kijken we 180 -180


//IMU object aanmaken
AK09918 ak09918;
ICM20600 icm20600(true);
AK09918_err_type_t err;

int32_t x, y, z;   //ruwe x,y,z van magnetometer
float  mx, my, mz; //verwerkte x,y,z met offset van calibratie

float   Mag_x_dampened, Mag_y_dampened, Mag_z_dampened;
float   Mag_x_hor, Mag_y_hor;
float   Mag_pitch, Mag_roll;

float ax, ay, az; //ruwe acceleratie in x,y,z
float gx, gy, gz; //ruwe gyro in x,y,z

float gpitch, groll, gyaw, avector, apitch, aroll;
float gpitch_out, groll_out;
double roll, pitch;

// Find the magnetic declination at your location
// http://www.magnetic-declination.com/
double declination_shenzhen = 2.13;

#define Frequency 125                                                   // 8mS sample interval 
#define Sensitivity 32.8                                                // Gyro sensitivity (see data sheet)

#define Sensor_to_deg 1/(Sensitivity*Frequency)                         // Convert sensor reading to degrees
#define Sensor_to_rad Sensor_to_deg*DEG_TO_RAD                          // Convert sensor reading to radians

#define Loop_time 1000000/Frequency                                     // Loop time (uS)
long    Loop_start;                                                     // Loop start time (uS)


OneButton button_1(D3, false); // Pin 2

const int numLatAndLongs= 7;
double LatAndLongs[numLatAndLongs][2] = {
  {50.838779664031804, 3.233811103087599},
  {50.839249188227214, 3.2331139431244202},
  {50.83955922456095, 3.2327022434662727},
  {50.84004582974001, 3.233466992910386},
  {50.840584385901955, 3.2332570448046307},
  {50.840728684618185, 3.2331769056924453},
  {50.84087991788618, 3.233275153105008}
};

bool Gyro_synchronised = false;
//magnetometer calibratiewaarden, bepaald via calibratiesript
bool  Record_data = false; //calibratie uitvoerne JA/NEE
float offset_x = -1;
float offset_y = -10;
float offset_z = 6;
float scale_x = 1.04;
float scale_y = 1.13;
float scale_z = 0.87;

//gyro calibratiewaarden
float gx_cal, gy_cal, gz_cal;

//update snelheid controle a.d.v micros()
float HuidigeTijd = 0, LastUpdate = 0;
float UpdateFrequentie = 1000000/100; //1s in micros / 50 
float ActueleFrequentie = 0;

//servo pos
int pos =0;

void setup()
{

  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  button_1.attachPress(NextPoint); //knop 1 indrdukken -> nextpoint uitvoeren

  Serial.begin(115200);
  Serial1.begin(GPSBaud, SERIAL_8N1, RXPin, TXPin);
  
  pinMode(2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  Servo.setPeriodHertz(50); 
  Servo.attach(D10, 500, 2400); //ServoPin toekennen
  Servo.write(0); 
  
  // join I2C bus
  Wire.begin();
  
  err = ak09918.initialize();
  //ak09918.switchMode(AK09918_POWER_DOWN);
  ak09918.switchMode(AK09918_CONTINUOUS_100HZ);

  icm20600.initialize();
  icm20600.setAccScaleRange(RANGE_8G);
  icm20600.setGyroScaleRange(RANGE_1K_DPS);

  err = ak09918.isDataReady();
  while (err != AK09918_ERR_OK) {+
     Serial.println("Waiting Sensor");
     delay(100);
     err = ak09918.isDataReady();
    }

  if (Record_data == true)
  {
    calibrate_magnetometer();
  }

  Calibrate_gyro();
  LastUpdate = micros();

}

void loop()
{

  button_1.tick();

  updateGPS();
  GetPosition();

  static int ServoBuffer = 0;
    
  if(++ServoBuffer >= 10)
  {
    ServoBuffer = 0;
    StuurServo();
  }

  Serial.print(" TargetLat:");
  Serial.print(TargetLat,6);
  Serial.print(F(","));
  Serial.print(" TargetLong:");
  Serial.print(TargetLong,6);
  Serial.print(F(","));

  Serial.print(" CurrentLat:");
  Serial.print(CurrentLat,6);
  Serial.print(F(","));
  Serial.print(" CurrentLong:");
  Serial.print(CurrentLong,6);
  Serial.print(F(","));
  
       Serial.print("pos:");

  Serial.print(pos);
  
  Serial.print(F(","));
 
  Serial.print(gps.distanceBetween(CurrentLat, CurrentLong, TargetLat,TargetLong));

   Serial.print(" Bearing:");

    Bearing = TinyGPSPlus::courseTo
    (
    CurrentLat, CurrentLong, 
    TargetLat, TargetLong
    );

  Serial.print(Bearing);
  GetCurrentHeading();

  Serial.print("Heading:");
  Serial.println(Heading);

}

void NextPoint(){

 static int index = 0;

 if (index >= numLatAndLongs){index = 0;}

 TargetLat = LatAndLongs[index][0];
 TargetLong = LatAndLongs[index][1]; 
 index = index +1;

}

void GetCurrentHeading() 
{

  if ((micros() - LastUpdate) >= 8000){
    LastUpdate = micros();

    // get acceleration
    ax =  icm20600.getRawAccelerationX();
    ay =  icm20600.getRawAccelerationY();
    az =  icm20600.getRawAccelerationZ();

    // get gyro
    gx = icm20600.getRawGyroscopeX(); 
    gy = - icm20600.getRawGyroscopeY();
    gz = - icm20600.getRawGyroscopeZ();

    // get magneto
    ak09918.getData(&x, &y, &z); 
    mx = + (x - offset_x) * scale_x;
    my = + (y - offset_y) * scale_y;
    mz = + (z - offset_z) * scale_z;

    //gyro hoeksnelheid omrekening naar hoek (integratie) LET OP!! doorloopsnelheid bepaald dt
    //dit stuk code moet altijd aan 125HZ lopen = 8ms per update
    groll += (gx - gx_cal) * Sensor_to_deg;
    gpitch += (gy - gy_cal) * Sensor_to_deg;
    gyaw += (gz - gz_cal) * Sensor_to_deg;

    float gpitch_temp = gpitch;
    float groll_temp = groll;

      // ----- Compensate pitch and roll for gyro yaw
    gpitch += groll_temp * sin((gz - gz_cal) * Sensor_to_rad);            // Transfer the roll angle to the pitch angle if the Z-axis has yawed
    groll -= gpitch_temp * sin((gz - gz_cal) * Sensor_to_rad);            // Transfer the pitch angle to the roll angle if the Z-axis has yawed

      // ----- Accelerometer angle calculations
    avector = sqrt((ax * ax) + (ay * ay) + (az * az));   // Calculate the total (3D) vector
    apitch = asin((float)ax / avector) * RAD_TO_DEG;                         //Calculate the pitch angle 
    aroll =  asin((float)ay / avector) * RAD_TO_DEG;                         //Calculate the roll angle

    apitch -= -1.0f;                                             //Accelerometer calibration value for pitch
    aroll -= 0.6f;                                               //Accelerometer calibration value for roll


  // ----- Correct for any gyro drift
  if (Gyro_synchronised)
  {
    // ----- Gyro & accel have been synchronised
    gpitch = gpitch * 0.75 + apitch * 0.25;        //Correct the drift of the gyro pitch angle with the accelerometer pitch angle
    groll = groll * 0.75 + aroll * 0.25;           //Correct the drift of the gyro roll angle with the accelerometer roll angle
  }
  else
  {
    // ----- Synchronise gyro & accel
    gpitch = apitch;                                       //Set the gyro pitch angle equal to the accelerometer pitch angle
    groll = aroll;                                         //Set the gyro roll angle equal to the accelerometer roll angle
    Gyro_synchronised = true;                                             //Set the IMU started flag
  }

  // ----- Dampen the pitch and roll angles
  gpitch_out = gpitch_out * 0.9 + gpitch * 0.1;   //Take 90% of the output pitch value and add 10% of the raw pitch value
  groll_out = groll_out * 0.9 + groll * 0.1;      //Take 90% of the output roll value and add 10% of the raw roll value

  
  Mag_pitch = - gpitch * DEG_TO_RAD; 
  Mag_roll = groll * DEG_TO_RAD;


  // ----- Apply the standard tilt formulas
  float p = Mag_pitch; 
  float r = Mag_roll;

   // Bereken de horizontale componenten
  Mag_x_hor = mx * cos(p) + my * sin(r) * sin(p) + mz * cos(r) * sin(p);
  Mag_y_hor = my * cos(r) - mz * sin(r);
 

  // ----- Dampen any data fluctuations
  Mag_x_dampened = Mag_x_dampened * 0.9 + Mag_x_hor * 0.1;
  Mag_y_dampened = Mag_y_dampened * 0.9 + Mag_y_hor * 0.1;

  // ----- Calculate the heading
  Heading = atan2(Mag_y_dampened,Mag_x_dampened ) * RAD_TO_DEG;  // Magnetic North

 
    // Voeg declinatie toe
    Heading += declination_shenzhen;

    SignedHeading = Heading;

    // Normaliseer naar 0-360
  if (Heading > 360.0) Heading -= 360.0;
  if (Heading < 0.0) Heading += 360.0;

  if (SignedHeading > 180) SignedHeading -= 360;
  if (SignedHeading < - 180) SignedHeading += 360;


  }
}







//-------------------------------------------------------------------------

void updateGPS()
{
  while (Serial1.available() > 0) //GPS beschikbaar
  {
    gps.encode(Serial1.read());   // lees GPS data
  }

  if (millis() > 5000 && gps.charsProcessed() < 10) //Doet de gps wat hij moet doen? Nee, geef foutmelding
  {
    Serial.println(F("No GPS detected: check wiring."));
  }
}

//-------------------------------------------------------------------------


void GetPosition()
{
  if (gps.location.isValid())
  {
    CurrentLat = gps.location.lat();
    CurrentLong = gps.location.lng();
  }
  else
  {
    Serial.print("GPS_Location_NOT_Valid"  );
  }
}


float convertRawAcceleration(int aRaw) {
  // since we are using 2 g range
  // -2 g maps to a raw value of -32768
  // +2 g maps to a raw value of 32767
  
  float a = (aRaw * 2.0) / 32768.0;
  return a;
}

float convertRawGyro(int gRaw) {
  // since we are using 500 degrees/seconds range
  // -500 maps to a raw value of -32768
  // +500 maps to a raw value of 32767
  
  float g = (gRaw * 500.0) / 32768.0;
  return g;
}


void Calibrate_gyro()
{
  // ----- Display calibration message

  Serial.print("Calibrating gyro");                        //Print text to screen

  // ----- Calibrate gyro
  for (int counter = 0; counter < 2000 ; counter ++)    //Run this code 2000 times
  {
    Loop_start = micros();
    if (counter % 125 == 0)Serial.print(".");              //Print a dot on the LCD every 125 readings
    
    // get gyro
    gx = icm20600.getRawGyroscopeX(); 
    gy = - icm20600.getRawGyroscopeY();
    gz = - icm20600.getRawGyroscopeZ();    

    gx_cal += gx;                               //Add the gyro x-axis offset to the gyro_x_cal variable
    gy_cal += gy;                               //Add the gyro y-axis offset to the gyro_y_cal variable
    gz_cal += gz;                               //Add the gyro z-axis offset to the gyro_z_cal variable
    while (micros() - Loop_start < Loop_time);           // Wait until "Loop_time" microseconds have elapsed
  }
  gx_cal /= 2000;                                   //Divide the gyro_x_cal variable by 2000 to get the average offset
  gy_cal /= 2000;                                   //Divide the gyro_y_cal variable by 2000 to get the average offset
  gz_cal /= 2000;                                   //Divide the gyro_z_cal variable by 2000 to get the average offset
}





void calibrate_magnetometer()
{
  // ----- Locals
  int mag_x, mag_y, mag_z;
  int status_reg_2;                                               // ST2 status register

  int32_t mag_x_min =  32767;                                         // Raw data extremes
  int32_t mag_y_min =  32767;
  int32_t mag_z_min =  32767;
  int32_t mag_x_max = -32768;
  int32_t mag_y_max = -32768;
  int32_t mag_z_max = -32768;

  float chord_x,  chord_y,  chord_z;                              // Used for calculating scale factors
  float chord_average;

  // ----- Display calibration message
  Serial.print("Rotate Compass");                                    // Print text to screen

  // ----- Record min/max XYZ compass readings
  for (int counter = 0; counter < 16000 ; counter ++)             // Run this code 16000 times
  {
     if (counter % 125 == 0)Serial.print(".");
    Loop_start = micros();                                        // Start loop timer
        // ----- Find max/min xyz values
        ak09918.getData(&x, &y, &z); 

        mag_x_min = min(x, mag_x_min);
        mag_x_max = max(x, mag_x_max);
        mag_y_min = min(y, mag_y_min);
        mag_y_max = max(y, mag_y_max);
        mag_z_min = min(z, mag_z_min);
        mag_z_max = max(z, mag_z_max);
  
    
    delay(2);                                                     // Time interval between magnetometer readings
  }

  // ----- Calculate hard-iron offsets
  offset_x = (mag_x_max + mag_x_min) / 2;                     // Get average magnetic bias in counts
  offset_y = (mag_y_max + mag_y_min) / 2;
  offset_z = (mag_z_max + mag_z_min) / 2;

  // ----- Calculate soft-iron scale factors
  chord_x = ((float)(mag_x_max - mag_x_min)) / 2;                 // Get average max chord length in counts
  chord_y = ((float)(mag_y_max - mag_y_min)) / 2;
  chord_z = ((float)(mag_z_max - mag_z_min)) / 2;

  chord_average = (chord_x + chord_y + chord_z) / 3;              // Calculate average chord length

  scale_x = chord_average / chord_x;                          // Calculate X scale factor
  scale_y = chord_average / chord_y;                          // Calculate Y scale factor
  scale_z = chord_average / chord_z;                          // Calculate Z scale factor

  // ----- Record magnetometer offsets
  /*
     When active this feature sends the magnetometer data
     to the Serial Monitor then halts the program.
  */
  if (Record_data == true)
  {
    // ----- Display data extremes
    Serial.print("XYZ Max/Min: ");
    Serial.print(mag_x_min); Serial.print("\t");
    Serial.print(mag_x_max); Serial.print("\t");
    Serial.print(mag_y_min); Serial.print("\t");
    Serial.print(mag_y_max); Serial.print("\t");
    Serial.print(mag_z_min); Serial.print("\t");
    Serial.println(mag_z_max);
    Serial.println("");

    // ----- Display hard-iron offsets
    Serial.print("Hard-iron: ");
    Serial.print(offset_x); Serial.print("\t");
    Serial.print(offset_y); Serial.print("\t");
    Serial.println(offset_z);
    Serial.println("");

    // ----- Display soft-iron scale factors
    Serial.print("Soft-iron: ");
    Serial.print(scale_x); Serial.print("\t");
    Serial.print(scale_y); Serial.print("\t");
    Serial.println(scale_z);
    Serial.println("");


    // ----- Halt program
    while (true);                                       // Wheelspin ... program halt
  }
}


void StuurServo()
{
  int Delta = Bearing - Heading;

  if (Delta > 180)  Delta -= 360;
  if (Delta < -180) Delta += 360;

  int pos = 90 - Delta;

  pos = constrain(pos, 0, 180);

  Servo.write(pos);
}







