# Stop Everything

You already know how to make some loops, read some analog values and send some information over cooper cables. But there is more to embedded systems than that. Imagine programming a safety critical, and having something like: 
In Pin 8 of your microcontroller, is a sensor that turns **HIGH** when a hand gets close to a saw. You want to stop a saw, so you do something like
´´´ if ( digitalRead(8) == true){
  stopSaw();
} ´´´ , right? No! Probaly there is a ´´´for()´´´ loop or a ´´´while()´´´ in your code that takes some time to analyse. What if the processor is to busy running that loop that it forgots to check if there is a hand next to the saw? Oops, somebody is going to get damaged and somebody is going to be fired.

An hardware interrupt (there are also software interrupts, but we are not talking about that here, since most microcontroller don't even support software interrupts) is nothing more than a signal going to the processor saying something like "Hey, it happened something and you need to take a look at it, like, right now!!!". This is important, because you don't want to miss some kind of events like a push of a button, they might be critical for the performance of your system. Even if you don't use **delay()** (and please don't, in a real application), you might miss some events if you do not use interrupts.
## Let's implement

## More on Interrupts

[Main Menu](../README.md) | [Next](./cheapTalk.md)
