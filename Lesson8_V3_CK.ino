/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
//name the pins being used in the circuit
const int notePin = A0;
const int togglePin = 3;
const int buzzerPin = 8;
int rate = 1500;
int frequency = 1000000 / (rate * 2);

int keyVal = 0;
int key = 0;
int switchState = 0;
int note = 0;
int oldNote = 0;

int notes[] = {262, 294, 330, 392, 440, 494, 523};
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(togglePin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Serial.print(frequency);
}

// the loop function runs over and over again forever
void loop() {
  keyVal = analogRead(notePin);
  switchState = digitalRead(togglePin);

  if (keyVal > 1005) {key = 1;}
  else if (keyVal = 900) {key = 2;}
  else if (keyVal = 800) {key = 3;}
  else if (keyVal = 700) {key = 4;}
  else {key = 0;}

  switch (switchState) {
    case 0:
      note = key - 1;
    break;

    case 1:
      note = key + 3;
    break;
  }
  if (key > 0) {
    tone(buzzerPin, notes[note]);
  }
  else {
    noTone(buzzerPin);
  }

  if (note != oldNote) {
    Serial.println("toggle state : analog value : note");
    Serial.print(switchState);
    Serial.print(" : ");
    Serial.print(keyVal);
    Serial.print(" : ");
    Serial.println(note);
  }
}