#include "arduino_secrets.h"

#include "thingProperties.h"   //AUTOMATICALLY GENERATED to read your added Variables
#include <Arduino_MKRIoTCarrier.h>
#include <Arduino_LSM6DSOX.h>

MKRIoTCarrier carrier;
//float x, y, z;
//int degreesX = 0;
//int degreesY = 0;

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

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
  }

  if (x > 0.1) {
    x = 100 * x;
    degreesX = map(x, 0, 97, 0, 90);
    accelerometer = "Tilting left: " + String(degreesX) + " degrees."; //Update the cloud variable with the sensor value.
    Serial.println(accelerometer);
    //add next two print lines for dashboard tinkering
    Serial.println(x);
    Serial.println(degreesX);
  }
  if (x < -0.1) {
    x = 100 * x;
    degreesX = map(x, 0, -100, 0, 90);
    accelerometer = "Tilting right: " + String(degreesX) + " degrees.";
    Serial.println(accelerometer);
    //add next two print lines for dashboard tinkering
    Serial.println(x);
    Serial.println(degreesX);
  }
  if (y > 0.1) {
    y = 100 * y;
    degreesY = map(y, 0, 97, 0, 90);
    accelerometer = "Tilting down: " + String(degreesY) + " degrees.";
    Serial.println(accelerometer);
    //add next two print lines for dashboard tinkering
    //Serial.println(y);
    //Serial.println(degreesY);
  }
  if (y < -0.1) {
    y = 100 * y;
    degreesY = map(y, 0, -100, 0, 90);
    accelerometer = "Tilting up: " + String(degreesY) + " degrees.";
    Serial.println(accelerometer);
    //add next two print lines for dashboard tinkering
    Serial.println(y);
    Serial.println(degreesY);
  }

  delay(300);

}

/*
  Since Accelerometer is READ_WRITE variable, onAccelerometerChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onAccelerometerChange()  {
  // Add your code here to act upon Accelerometer change
}