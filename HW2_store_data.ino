#include "thingProperties.h"   //AUTOMATICALLY GENERATED to read your added Variables
#include <Arduino_MKRIoTCarrier.h>
#include <Arduino_LSM6DSOX.h>

MKRIoTCarrier carrier;

void setup() {

  Serial.begin(9600);   //AUTOMATICALLY GENERATED to handle the serial monitor

  initProperties();  // AUTOMATICALLY GENERATED Defined in thingProperties.h
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);  // AUTOMATICALLY GENERATED Connect to Arduino IoT Cloud
  setDebugMessageLevel(2); // AUTOMATICALLY GENERATED set the amount of details in debug message 0-4
  ArduinoCloud.printDebugInfo(); // AUTOMATICALLY GENERATED print out the debug message

  while (ArduinoCloud.connected() != 1) {
    ArduinoCloud.update();
    delay(500);
  }
  delay(2000);

  carrier.noCase();
  carrier.begin();

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println("Hz");
}

void loop() {

  ArduinoCloud.update(); // AUTOMATICALLY GENERATED keep updating the Cloud with new data
  
// To monitor the *_raw variables, define them in the Thing Setup as float variables and modify the code below to NOT define the *_raw variables but merely call them
  pressure_raw = carrier.Pressure.readPressure();
  altitude_raw = 44330 * ( 1 - pow(pressure_raw / 101.325, 1 / 5.255) );
  pressure = "Pressure = "+ String(pressure_raw) + " KPa";
  altitude = "Altitude according to KPa is approximately=" + String(altitude_raw) + " m";

  // print the sensor value
  Serial.println(pressure);  
  Serial.println(altitude);  //The altitude value is not very accurate, it is only an approximation.

  // print an empty line
  Serial.println();

  delay(500);

}