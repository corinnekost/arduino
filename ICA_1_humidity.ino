#include "thingProperties.h"   //AUTOMATICALLY GENERATED to read your added Variables
    #include <Arduino_MKRIoTCarrier.h>
    MKRIoTCarrier carrier;
    
    void setup() {
    
    Serial.begin(9600);   //AUTOMATICALLY GENERATED to handle the serial monitor
    
    initProperties();  // AUTOMATICALLY GENERATED Defined in thingProperties.
    ArduinoCloud.begin(ArduinoIoTPreferredConnection);  // AUTOMATICALLY GENERATED Connect to Arduino IoT Cloud
    setDebugMessageLevel(2); // AUTOMATICALLY GENERATED set the amount of details in debug message 0-4
    ArduinoCloud.printDebugInfo(); // AUTOMATICALLY GENERATED print out the debug message
    while(ArduinoCloud.connected() !=1 ){
    ArduinoCloud.update();
    delay(500);
  }
    carrier.noCase();
    carrier.begin();
    }
    void loop() {
      
    ArduinoCloud.update();
    // read the sensor values
    humidity = carrier.Env.readHumidity();  //Upload the humidity value to the cloud variable
    // print the sensor values
    Serial.print("	 Humidity: ");
    Serial.println(humidity);
      /* add Yassers code here*/
    carrier.display.setTextColor(ST77XX_WHITE); //set the color of the text to white

    carrier.display.setTextSize(3); //set the size of the text to 3 (medium)

    carrier.display.setCursor(50, 100); //set the cursor at position x=50, y=100

    //carrier.display.print("Humid = "); //display humidity on the screen
    carrier.display.print(humidity); //display humidity on the screen
   
    delay(1000);
    carrier.display.fillScreen(0); // Clear the screen and be ready for next reading update
    delay(500);
    }
/*  Since Humidity is READ_WRITE variable, onHumidityChange() is
  executed every time a new value is received from IoT Cloud.
*/

void onHumidityChange()  {
  // Add your code here to act upon Humidity change
}