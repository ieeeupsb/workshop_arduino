# Hello World
In every programming language, "Hello World" is the most basic program you can write. Now we're going to show you the "Hello World" of Arduino programming.

Every Arduino user agrees that the most basic *sketch* you can make is **Blink**, the example that you find in the IDE (as you saw in the previous topic). Let's try that again, and truly understand what is happening...

Go to **File > Examples > Basics > Blink**. You should now have something like this:
> To place some comment on your code use **"/\*"** at the beggining and **"\*/"** at the end of your comment. The compiler will ignore whatever you write in between, which is helpful to leave some reminders for later.
> <br>Alternatively, you can use **"//"** - everything which comes after this mark is also ignored. **But only in that same line!**

```Arduino
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
```

The portion of code in ```void setup()``` is run only once - when the Arduino turns on or when it is reset.<br>
As you might have guessed, the portion inside the ```loop()``` keeps running in an infinite loop, forever.

```LED_BUILTIN``` represents the LED that is mounted on the board. *(compile it to confirm!)*<br>
But we don't want to use the built-in LED, we have our own! Let's make some connections...

## Pins and using #define
Start by making the following connections:

![Breadboard](../content/images/arduino-led-tcp-sketch.png)

Now, instead of ```LED_BUILTIN```, we could simply use ```2```, but that doesn't seem very elegant.<br>
In the beginning of the code (before the setup) we can use ```#define LED_PIN 2``` and then replace LED_BUILTIN with LED_PIN.

> **#define X Y**, like **#include** is a special command that you use in the beggining of code. It tells the compiler "In this program, everytime you see the word X, replace it with Y".<br>
> In fact, LED_BUILTIN is also defined, and it actually stands for 13 in the Arduino UNO.<br>
> Why is this useful? Imagine you're making a huge program, where you use multiple pins, multiple times. You see how this would become really difficult very fast? If, for some reason, you now need to connect your LED to pin 3, you only need to change **one value** which is far less confusing.

## Serial and debugging
Another important tool when dealing with Arduino is the Serial Monitor that was introduced in the previous topic.<br>
Serial communication allows you to communicate with the Arduino while it is running, check the value of a certain variable, see on which part of the code the Arduino might be "stuck", or simply *Debug*.

In the following topics you will get to use the Serial Communication in a more useful and fun way, but for now let's add this pieces of code to your ```setup``` and ```loop```:
```Arduino
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Hello World! - This example will just print the current LED state...");
  Serial.println("(Note that this info is only shown when the Arduino starts, since it's in setup)");
  Serial.println();
}

// The loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // Turn the LED on (HIGH is the voltage level)
  Serial.println("LED is ON!");
  delay(2000);                       // Wait 2 seconds
  digitalWrite(LED_BUILTIN, LOW);    // Turn the LED off by making the voltage LOW
  Serial.println("LED is OFF!");
  delay(2000);                       // Wait 2 seconds
}
```

Now you're ready for the next topics! :wink:

[Main Menu](../README.md) | [Next](./onOff.md)
