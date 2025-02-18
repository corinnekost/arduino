#include "arduino_secrets.h"
#include "thingProperties.h"   //AUTOMATICALLY GENERATED to read your added Variables
#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;

void setup() {

  Serial.begin(9600);   //AUTOMATICALLY GENERATE1D to handle the serial monitor

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

  screenColor = 0;
}

void loop() {

  ArduinoCloud.update(); // AUTOMATICALLY GENERATED keep updating the Cloud with new data

  switch (screenColor) {     //Switch the cloud screenColor variable to change the screen background color.
    case 0:
      carrier.display.fillScreen(0xFFFF);     //set the screen color as white
      Serial.println("Screen color: white");
      break;
    case 1:
      carrier.display.fillScreen(0xBDF7);     //set the screen color as grey
      Serial.println("Screen color: grey");
      break;
    case 2:
      carrier.display.fillScreen(0xF800);     //set the screen color as red
      Serial.println("Screen color: red");
      break;
    case 3:
      carrier.display.fillScreen(0x1F);       //set the screen color as blue
      Serial.println("Screen color: blue");
      break;
    case 4:
      carrier.display.fillScreen(0xF81F);     //set the screen color as pink
      Serial.println("Screen color: pink");
      break;
    case 5:
      carrier.display.fillScreen(0xFBE0);     //set the screen color as orange
      Serial.println("Screen color: orange");
      break;
    case 6:
      carrier.display.fillScreen(0x7E0);      //set the screen color as green
      Serial.println("Screen color: green");
      break;
  }

  carrier.display.setTextSize(2);
  carrier.display.setTextColor(0x0000);  //set the text color as black
  carrier.display.setCursor(50, 100); //set the cursor at position x=50, y=100
  carrier.display.print("Hello There!"); //display "Hello There!" on the screen

  delay(500); 
}

/*
  Since ScreenColor is READ_WRITE variable, onScreenColorChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onScreenColorChange()  {
  // Add your code here to act upon ScreenColor change
  
}
