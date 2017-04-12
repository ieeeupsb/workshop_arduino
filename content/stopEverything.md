# Stop Everything

You already know how to make some loops, read some sensors and send some information. But there is more to embedded systems than that. Imagine programming a safety critical system, and having something like: 

In Pin 8 of your microcontroller, is a sensor that turns **HIGH** when a hand gets close to a rotating saw. You want to stop the saw, so you do something like:
``` 
if ( digitalRead(8) == HIGH)
  stopSaw();
``` 
Right? **No!** Probably there is a `for()` or a `while()` loop in your code that takes some time to process. What if the processor is to busy running that loop that it doesn't go to the `if()` statement soon enough to check if there is a hand next to the saw? Oops, somebody is going to get damaged and somebody is going to be fired.

An hardware interrupt is nothing more than a signal going to the processor saying something like **"Hey, it happened something and you need to take a look at it, like, right now!!!"**. This is important, because you don't want to miss some kind of events like a push of a button, they might be critical for the performance of your system. Even if you don't use `delay()` (and please don't, in a real application), you might miss some events if you do not use interrupts.
## Let's implement

## More on Interrupts
You might want to have a section of your code not affected by your interrupts, a junk of code that has to run regardless of what happens in the world (usually you use this when you have time sensitive code, and an interrupt might mess up with the time). The way you do that is using the `noInterrupts()` function. To enable interrupts again, you just have to call `interrupts()` . So, your code should look something like this:
```
void loop()
{
  noInterrupts();
  // critical, time-sensitive code here
  interrupts();
  // other code here
}
```

[Main Menu](../README.md) | [Next](./cheapTalk.md)
