# Stop Everything

You already know how to make some loops, read some sensors and send some information. But there is more to embedded systems than that. Imagine programming a safety critical system, and having something like: 

In Pin 8 of your microcontroller, is a sensor that turns **HIGH** when a hand gets close to a rotating saw. You want to stop the saw, so you do something like:
```Arduino
if ( digitalRead(8) == HIGH)
  stopSaw();
``` 
Right? **No!** Probably there is a `for()` or a `while()` loop in your code that takes some time to process. What if the processor is to busy running that loop that it doesn't go to the `if()` statement soon enough to check if there is a hand next to the saw? Oops, somebody is going to get damaged and somebody is going to be fired.

An hardware interrupt is nothing more than a signal going to the processor saying something like **"Hey, it happened something and you need to take a look at it, like, right now!!!"**. This is important, because you don't want to miss some kind of events like a push of a button, they might be critical for the performance of your system. Even if you don't use `delay()` (and please don't, in a real application), you might miss some events if you do not use interrupts.
## Let's implement

First, you need to know which pins support the use of interrupts. For your Arduino, these are digital pins 2 and 3. On your `void setup()` function, you need to attach the pin to an interrupt, and that is done using the `attachInterrupt(interruptPin, functionCalled, mode)`. Let's dissect what is happening here:
You can't just use 2 or 3 as your **interruptPin**. Because the **interruptPin 0**  corresponds to the _pin 2_ and the **1** to the _3_, in your particular Arduino (the Uno). You can use the function `digitalPinToInterrupt(2)` which maps the pin 2 to the corresponding interrupt (in this case the 0).
As for the **functionCalled**, that's the function the code calls whenever an interrupt is triggered. Now, about the mode, that can either be **LOW** to trigger the interrupt whenever the pin is low, **CHANGE** to trigger the interrupt whenever the pin changes its value, **RISING** for when the pin goes from low to high, **FALLING** for when the pin goes from high to low.
Let's write a simple example. Whenever the interrupt pin changes state a led will change its state. 
![connection](./images/interrupt.png "Interrupt") </br>
```Arduino
int ledPin = 13;
int interruptPin = 2;
int state = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE); // you could use 0 instead of digitalPinToInterrupt(2)
}

void loop() {
  digitalWrite(ledPin, state);
}

void blink() {
  state = !state;
}

```
And that's how an interrupt works! 
## More on Interrupts
You might want to have a section of your code not affected by your interrupts, a chunk of code that has to run regardless of what happens in the world (usually you use this when you have time sensitive code, and an interrupt might mess up with the time). The way you do that is using the `noInterrupts()` function. To enable interrupts again, you just have to call `interrupts()` . So, your code should look something like this:
```Arduino
void loop()
{
  noInterrupts();
  // critical, time-sensitive code here
  interrupts();
  // other code here
}
```
Maybe you will want to stop using interrupts somewhere in your code. That can be easily done with the `detachInterrupt(interruptPin)` function. Don't forget: the _interruptPin 0_ corresponds to the _Arduino pin 2_, so you can use the `detachInterrupt(digitalPinToInterrupt(2))` if you want to detach an interrupt to pin 2. Otherwise, use `detachInterrupt(0)`

[Main Menu](../README.md) | [Next](./cheapTalk.md)
