#include <Arduino.h>

int buttonPin = 2; // Button connected to pin 2
int counter = 0; // Counter variable

void setup() {
  // Set the button pin to input mode with a pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);

  // Attach an interrupt to the button pin
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, FALLING);

  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  // Print the counter value to the serial monitor
  Serial.print("Counter: ");
  Serial.println(counter);

  // Delay for 1 second
  delay(1000);
}

void buttonISR() {
  // Increment the counter
  counter++;
}