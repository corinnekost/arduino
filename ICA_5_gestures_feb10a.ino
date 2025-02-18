#include "arduino_secrets.h"

#include "thingProperties.h"   //AUTOMATICALLY GENERATED to read your added Variables
    #include <Arduino_MKRIoTCarrier.h>
    MKRIoTCarrier carrier;
    int gesture=NONE;  //setup the gesture variable as NONE before it starts reading values
    
    void setup() {

  Serial.begin(9600);   //AUTOMATICALLY GENERATED to handle the serial monitor
  initProperties();  // AUTOMATICALLY GENERATED Defined in thingProperties.h
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);  // AUTOMATICALLY GENERATED Connect to Arduino IoT Cloud
  setDebugMessageLevel(2); // AUTOMATICALLY GENERATED set the amount of details in debug message 0-4
  ArduinoCloud.printDebugInfo(); // AUTOMATICALLY GENERATED print out the debug message

  while(ArduinoCloud.connected() !=1 ){
    ArduinoCloud.update();
    delay(500);
  }
  delay(2000);


  carrier.noCase();   //Not using the carrier case, change to carrier.withCase() if you are using it 
  carrier.begin();    //Initialise the carrier

}

void loop() {

  ArduinoCloud.update(); // AUTOMATICALLY GENERATED keep updating the Cloud with new data

  if (carrier.Light.gestureAvailable()) {
    // A gesture was detected, read and print to Serial Monitor.
    gesture = carrier.Light.readGesture();

    switch (gesture) {      //Switch between the diferent gesture detections and update the cloud variable
      case UP:
        gestureDirection = "Detected UP gesture";
        Serial.println(gestureDirection);
        break;
    
      case DOWN:
        gestureDirection = "Detected DOWN gesture";
        Serial.println(gestureDirection);
        break;
    
      case LEFT:
        gestureDirection = "Detected LEFT gesture";
        Serial.println(gestureDirection);
        break;
    
      case RIGHT:
        gestureDirection = "Detected RIGHT gesture";
        Serial.println(gestureDirection);
        break;
    
    }

  }

  delay(200);

}

/*
  Since GestureDirection is READ_WRITE variable, onGestureDirectionChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onGestureDirectionChange()  {
  // Add your code here to act upon GestureDirection change
}