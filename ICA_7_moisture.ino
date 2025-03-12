#include "thingProperties.h"   //AUTOMATICALLY GENERATED to read your added Variables
#include <Arduino_MKRIoTCarrier.h>

MKRIoTCarrier carrier;
int moistPin = A0; //This pin depends on the version of your Arduino IoT Carrier

void setup() {

Serial.begin(9600);   //AUTOMATICALLY GENERATED to handle the serial monitor

initProperties();  // AUTOMATICALLY GENERATED Defined in thingProperties.h
 ArduinoCloud.begin(ArduinoIoTPreferredConnection);  // AUTOMATICALLY GENERATED Connect to Arduino Cloud
 setDebugMessageLevel(2); // AUTOMATICALLY GENERATED set the amount of details in debug message 0-4
 ArduinoCloud.printDebugInfo(); // AUTOMATICALLY GENERATED print out the debug message

 while (ArduinoCloud.connected() != 1) {
ArduinoCloud.update();
delay(500);
  }
  delay(2000);

  carrier.noCase();
  carrier.begin();
}

void loop() {

ArduinoCloud.update();

//read raw moisture value
 int raw_moisture = analogRead(moistPin);

 //map raw moisture to a scale of 0 - 100
moisture = map(raw_moisture, 0, 100, 100, 0); //You can adjust the mapping function to obtain more accurate values

 // print the sensor values
 //Serial.print("	 Raw Moisture Value: ");
 //Serial.println(raw_moisture);
Serial.print("	 Moisture: ");
Serial.println(moisture);
//try to add proper messenger variable for Dashboard
//moistureValue = "Moisture: " + (moisture);
 delay(200);

}
/*
Since Moisture is READ_WRITE variable, onMoistureChange() is
executed every time a new value is received from the Cloud.
*/
void onMoistureChange()  {
// Add your code here to act upon Moisture change
}
/*
  Since MoistureValue is READ_WRITE variable, onMoistureValueChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMoistureValueChange()  {
  // Add your code here to act upon MoistureValue change
}
