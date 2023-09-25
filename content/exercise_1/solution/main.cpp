#include <Arduino.h>

#define LED_PIN 13  // change this to whatever pin is connected to the LED.

void setup() {
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
    digitalWrite(LED_PIN, HIGH);       // turn the LED on (HIGH is the voltage level)
    Serial.println("LED is on!");      // Sends ON message to serial monitor
    delay(500);                        // wait for half a second
    digitalWrite(LED_PIN, LOW);        // turn the LED off by making the voltage LOW
    Serial.println("LED is off!");     // Sends OFF message to serial monitor
    delay(500);                        // wait for half a second
}