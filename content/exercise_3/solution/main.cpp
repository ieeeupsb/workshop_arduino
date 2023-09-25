#include <Arduino.h>

int ledPin = 13; // LED connected to pin 13
int potPin = A0; // Potentiometer connected to analog pin A0

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin 13 to output mode
}

void loop() {
  // Read the voltage from the potentiometer
  int potValue = analogRead(potPin);

  // Scale the potentiometer value to 0-255
  int brightness = potValue / 4;

  // Set the brightness of the LED
  analogWrite(ledPin, brightness);
}