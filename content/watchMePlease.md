# Watchdog Timers
We are not talking about the game here. A watchdog timer is used a lot in embedded systems programming. Imagine you have an arduino reading the temperature every hour and storing it in a DB. You go check the DB some months after, only to realize that only some values were recorded. What a bummer, your Arduino got stuck, when you appeared and did a reset, it was already too late.

## How a watchdog timer works

A watchdog timer is basically a timer that is set to a certain time, and starts decreasing. So you put a line amid your `void loop()` to reset the timer to the desaired value. If everything goes well, the watchdog is reset everytime and nevers reaches 0. But if, for whatever reason, the Arduino freezes and gets stuck at any point, the watchdog won't be reset. At some point, it will reach 0 and when that happens it will reset the Arduino, so the code will start running again. 

## Code stuck? Never again

First, let's make a code that will get stuck so you can see the watchdog in action. Wire a led to pin 13, you already have done that in a previous example.
```
int past_time;

void setup(){
    pinMode(13,OUTPUT);
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
```
This code should turn the LED on and off a couple of times until more than 5 seconds passed since the beginning of the program. When that happens, the code will get stuck in the `while(1)` statement and nothing will happen anymore. And that's where the watchdog enters.

```


```

So there you have it. You are now able to design a system that is able of restarting if something bad happens, both in software or in hardware.
