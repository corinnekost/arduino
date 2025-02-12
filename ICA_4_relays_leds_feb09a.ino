#include "arduino_secrets.h"

#include "thingProperties.h"   //AUTOMATICALLY GENERATED to read your added Variables
#include <Arduino_MKRIoTCarrier.h>

MKRIoTCarrier carrier;


void setup() {

  Serial.begin(9600);   //AUTOMATICALLY GENERATED to handle the serial monitor

  initProperties();  // AUTOMATICALLY GENERATED Defined in thingProperties.h
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);  // AUTOMATICALLY GENERATED Connect to Arduino IoT Cloud
  setDebugMessageLevel(2); // AUTOMATICALLY GENERATED set the amount of details in debug message 0-4
  ArduinoCloud.printDebugInfo(); // AUTOMATICALLY GENERATED print out the debug message

  while (ArduinoCloud.connected() != 1) {     //This while function verifies that the board is connected to the cloud
    ArduinoCloud.update();
    delay(500);
  }
  delay(2000);

  carrier.noCase(); //If using the case, change this line to: carrier.withCase();
  carrier.begin();  //Initializing the IoT carrier
}

void loop() {
  ArduinoCloud.update();
  // Your code here
  uint8_t r, g, b;
  control_RGB.getValue().getRGB(r, g, b);   //Getting the RGB color values from the dashboard

  if (blink_RGB == true) {
    lightsOn();
    delay(200);
    lightsOff();
    delay(200);
  }

  if (switch_RGB == true) {
    lightsOn();
  } else {
    lightsOff();
  }

  if (relay_1 == true) {
    carrier.Relay1.open();
  } else {
    carrier.Relay1.close();
  }

  if (relay_2 == true) {
    carrier.Relay2.open();
  } else {
    carrier.Relay2.close();
  }

  delay(300);
}

void lightsOn() {     
  uint8_t r, g, b;
  control_RGB.getValue().getRGB(r, g, b);
  carrier.leds.setPixelColor(0, r, g, b);
  carrier.leds.setPixelColor(1, r, g, b);
  carrier.leds.setPixelColor(2, r, g, b);
  carrier.leds.setPixelColor(3, r, g, b);
  carrier.leds.setPixelColor(4, r, g, b);
  carrier.leds.show();
}

void lightsOff() {
  carrier.leds.setPixelColor(0, 0, 0, 0);
  carrier.leds.setPixelColor(1, 0, 0, 0);
  carrier.leds.setPixelColor(2, 0, 0, 0);
  carrier.leds.setPixelColor(3, 0, 0, 0);
  carrier.leds.setPixelColor(4, 0, 0, 0);
  carrier.leds.show();
}

/*
  Since BlinkRGB is READ_WRITE variable, onBlinkRGBChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onBlinkRGBChange()  {
  // Add your code here to act upon BlinkRGB change
}
/*
  Since SwitchRGB is READ_WRITE variable, onSwitchRGBChange() is
  executed every time a new value is received from Cloud.
*/
void onSwitchRGBChange()  {
  // Add your code here to act upon SwitchRGB change
}
/*
  Since ControlRGB is READ_WRITE variable, onControlRGBChange() is
  executed every time a new value is received from Cloud.
*/

void onControlRGBChange()  {
  // Add your code here to act upon ControlRGB change
}
/*
  Since Relay1 is READ_WRITE variable, onRelay1Change() is
  executed every time a new value is received from Cloud.
*/
void onRelay1Change()  {
  // Add your code here to act upon Relay1 change
}
/*
  Since Relay2 is READ_WRITE variable, onRelay2Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onRelay2Change()  {
  // Add your code here to act upon Relay2 change
}