int ledPin = 13; // LED connected to pin 13
int buttonPin = 2; // Push button connected to pin 2

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin 13 to output mode
  pinMode(buttonPin, INPUT); // Set pin 2 to input mode
}

void loop() {
  // Read the state of the push button
  int buttonState = digitalRead(buttonPin);

  // If the push button is pressed, turn on the LED
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    // Otherwise, turn off the LED
    digitalWrite(ledPin, LOW);
  }
}