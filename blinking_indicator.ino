int readValue = 0;
int writeValue = 0;
void setup() {
  pinMode(9, OUTPUT);             // declare the first LED pin as output
  pinMode(10, OUTPUT);            // declare the second LED pin as output
  pinMode(11, OUTPUT);            // declare the third LED pin as output
  Serial.begin(9600);
}
 
void loop() {
  readValue = analogRead(A0);     // store the value from the potentiometer
  writeValue = readValue / 4;     // divide the readValue by 4 and store as the writeValue
  if (readValue > 1000) {         // if the value from the potentiometer is greater than 1,000 then:
    digitalWrite(9,LOW);          // turn off the first LED
    digitalWrite(10,LOW);         // turn off the second LED
    digitalWrite(11,LOW);         // turn off the third LED
    delay(250);                   // wait 1/4 of a second
    digitalWrite(11,HIGH);        // turn on the third LED
    digitalWrite(10,HIGH);        // turn on the second LED
    digitalWrite(9,HIGH);         // turn on the first LED
    delay(250);                   // wait 1/4 of a second
  }
  else {
    analogWrite(9, writeValue);     // set LED 1 brightness to writeValue
    analogWrite(10, writeValue);    // set LED 2 brightness to writeValue
  analogWrite(11, writeValue);    // set LED 3 brightness to writeValue
  }
  Serial.print(readValue);
  Serial.print(" : ");
  Serial.println(writeValue);
  delay(100);
}