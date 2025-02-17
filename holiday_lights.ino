// Define LED pins
const int led1 = 12; // Green LED
const int led2 = 11; // Red LED
const int led3 = 10; // Green LED
const int led4 = 9; // Red LED

// Define button and potentiometer pins
const int buttonPin = 7; // Push button
const int potPin = A0; // Potentiometer

// Variables for button state
bool ledState = false;
int lastButtonState = HIGH; // Button is pulled HIGH initially

void setup() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP); // Internal pull-up resistor
    Serial.begin(9600); // Debugging
}

void loop() {
    // Read button state
    int buttonState = digitalRead(buttonPin);
   
    // Check if button is pressed (debounce logic)
    if (buttonState == LOW && lastButtonState == HIGH) {
        delay(50); // Debounce delay
        if (digitalRead(buttonPin) == LOW) {
            ledState = !ledState; // Toggle LED state
        }
    }
    lastButtonState = buttonState;

    // Read potentiometer value and map it to a delay time
    int potValue = analogRead(potPin);
    int delayTime = map(potValue, 0, 1023, 100, 1000); // Adjust range

    // Control LEDs based on button state
    if (ledState) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        delay(delayTime);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(delayTime);
    } else {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
    }
}
