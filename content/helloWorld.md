# Hello World
In this topic, you will see a simple Arduino "Hello World" example.
It simply displays "hello world" ate beginning of execuuion and does nothing on loop.

NOTE: pay attention to the code line : "delay(1);". This is a good practice because it makes the microprocessor to wait and not just running as fast as it can. ( There are more theoretical aspects about this note, but that's enough)

```c++

void setup(){
   Serial.begin(9600);
   Serial.println("Hello World");
}

void loop(){
 delay(1);
}  
```
[Main Menu](../README.md) | [Next](./onOff.md)
