// name the Arduino Pins
const int tempSensorPin = A0;
 
// declare variables
float tempC = 0;
float tempF = 0;
float sensorVal = 0;
 
void setup() {
  // open a serial connection to display values
  Serial.begin(9600);
}
 
void loop() {
  // read the analog value from the sensor and store it in a variable
  sensorVal = analogRead(tempSensorPin);
  
  tempC = (((sensorVal/1024) * 5) - .5) * 100;    // calculates the temperature in Celsius
  tempF = (tempC * 9) / 5 + 32;                     // calculates the temperature in Fahrenheit
 
  Serial.print("sensor Value: ");
  Serial.print(sensorVal);
  Serial.print(", degrees C: ");
  Serial.print(tempC);
  Serial.print(", degrees F: ");
  Serial.println(tempF);
  delay(2000);
}