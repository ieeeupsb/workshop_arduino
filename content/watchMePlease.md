# Watchdog Timers
A watchdog timer is used a lot in embedded systems programming. Imagine you have an arduino reading the temperature every hour and storing it in a DB. You go check the DB some months after, to realize that only some values were recorded. What a bummer, your Arduino got stuck, when you appeared and did a reset, it was already too late.

## How a watchdog timer works

A watchdog is basically a timer that is set to a certain value, and starts decreasing. So you put a line amid your `void loop()` to reset the timer to the desaired value. If everything goes well, the watchdog is reset everytime and nevers reaches 0. But if, for whatever reason, the Arduino freezes and gets stuck at any point, the watchdog won't be reset. At some point, it will reach 0 and when that happens it will reset the Arduino, so the code will start running again. 

## Code stuck? Never again

First, let's make a code that will get stuck so you can see the watchdog in action. Wire a led to pin 13, you already have done that in a previous example.
```c++
int past_time;
int i;
void setup(){
    pinMode(13,OUTPUT);
   
    for(i=0;i < 5; i++){     // blynks 5 times at startup
        digitalWrite(13,HIGH);
        delay(250);
        digitalWrite(13,LOW);
        delay(250);
    } 
    past_time = milis();
}

void loop(){
  if(milis() - past_time < 5000){
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
  }
  else{
      while(1);
  }
}  
```
This code should turn the LED on and off a couple of times until more than 5 seconds passed since the beginning of the program. When that happens, the code will get stuck in the `while(1)` statement and nothing will happen anymore. And that's where the watchdog enters.

```c++
#include <avr/wdt.h> // include the watchdog library from Atmel

int past_time;
int i;
void setup(){   

    wdt_enable(WDTO_8S); // sets the timer to 8s (there is a range of values that you can choose)
    pinMode(13,OUTPUT);
   
    for(i=0;i < 5; i++){     // blynks 5 times at startup
        digitalWrite(13,HIGH);
        delay(250);
        digitalWrite(13,LOW);
        delay(250);
    } 
    past_time = milis();
}
void loop(){

wdt_reset(); // resets the watchdog timer
if(milis() - past_time < 5000){
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
  }
  else{
      while(1);
  }
}

```

So there you have it. You are now able to design a system that is able of restarting if something bad happens, both in software or in hardware.

[Main Menu](../README.md) | [Next](./broadenYourHorizons.md)
