#include "arduino_secrets.h"

#include "thingProperties.h"   //AUTOMATICALLY GENERATED to read your added Variables
#include <Arduino_MKRIoTCarrier.h>

MKRIoTCarrier carrier;


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
  carrier.begin(); //Initializing the IoT carrier
}

void loop() {

  ArduinoCloud.update(); // AUTOMATICALLY GENERATED keep updating the Cloud with new data

  // put your main code here, to run repeatedly:
  carrier.Buttons.update();

  // Verify your thresholds
  if (carrier.Buttons.getTouch(TOUCH0)) {
    Serial.println("touching 0");
    button0++;
    delay(500);
  }

  if (carrier.Buttons.getTouch(TOUCH1)) {
    Serial.println("touching 1");
    button1++;
    delay(500);
  }

  if (carrier.Buttons.getTouch(TOUCH2)) {
    Serial.println("touching 2");
    button2++;
    delay(500);
  }

  if (carrier.Buttons.getTouch(TOUCH3)) {
    Serial.println("touching 3");
    button3++;
    delay(500);
  }

  if (carrier.Buttons.getTouch(TOUCH4)) {
    Serial.println("touching 4");
    button4++;
    delay(500);
  }

}
/*
  Since Button0 is READ_WRITE variable, onButton0Change() is            //AUTOMATICALLY GENERATED when variables are created on the setup section
  executed every time a new value is received from the Cloud.
*/
void onButton0Change()  {
 // Add your code here to act upon Button0 change
}
/*
  Since Button1 is READ_WRITE variable, onButton1Change() is
  executed every time a new value is received from the Cloud.
*/
void onButton1Change()  {
  // Add your code here to act upon Button1 change
}
/*
  Since Button2 is READ_WRITE variable, onButton2Change() is
  executed every time a new value is received from the Cloud.
*/
void onButton2Change()  {
  // Add your code here to act upon Button2 change
}
/*
  Since Button3 is READ_WRITE variable, onButton3Change() is
  executed every time a new value is received from the Cloud.
*/
void onButton3Change()  {
  // Add your code here to act upon Button3 change
}
/*
  Since Button4 is READ_WRITE variable, onButton4Change() is
  executed every time a new value is received from the Cloud.
*/
void onButton4Change()  {
  // Add your code here to act upon Button4 change
}