# Broaden Your Horizons

Now that you already know how to do some basic things with the arduino, it's time for you to get to know tools that will give you more power and will help you become an embedded systems ninja programmer.

## I like to get under the hood
The Arduino microcontrollers are from Atmel, one of the leading microcontrollers manufacturer. If you want to unleash the full power of your chip, you will want to drop both the Arduino IDE and the Arduino libraries. What you will do is program the micro in pure C, using the AVR libraries and [Atmel Studio](http://www.atmel.com/microsite/atmel-studio/). It uses the Visual Studio interface, which is a pretty good IDE. You will have access to a great software framework and the best debugging features.
Have a look of this two codes, the first is programmed using the Arduino framework, the other is in pure C, using the AVR libraries. <br>
The Arduino code: <br>
```Arduino
 void setup() {
   pinMode(8, OUTPUT);
 }

 void loop() {
   digitalWrite(8, HIGH);
   delay(1000);
   digitalWrite(8, LOW);
   delay(1000);
 }

```
The Embedded C code: <br>
```c
#define F_CPU 16000000UL // Sets the CPU frequency to 16Mhz

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{

    DDRB |= (1<<0); // Set the pin as output
    while (1) 
    {
        PORTB |= (1<<0); // Pull the pin HIGH
        _delay_ms(1000);
        PORTB &= ~(1<<0); // Pull the pin LOW
        _delay_ms(1000);
    }
}
```
As you see, the code is more difficult to comprehend as it is more low-level, but the difference in the clock cycles is enormous, because a <code>digitalWrite()</code> function has a lot more going on than just pulling the passed pin HIGH.
## I live in the command line 
If you are the type of person that never leaves the command line, there is a way of programming your micros using a text editor of your choice (vim, emacs, nano,...) and then doing the build yourself.
As an example, use the code above and save it to a file **yourfile.c**. <br>
Now, let's compile the code. We are going to use the avr-gcc compiler, an target our chip, Atmega328.
<br><code>avr-gcc -Os -mmcu=atmega328p -c yourfile.c </code> <br>
You will get an object file. Then, you will need to insert the command <br><code>avr-gcc -mmcu=atmega328p -o yourfile.elf yourfile.o</code><br> to get an Executable and Linkable Format file, but there's one more step to be done before we upload our code. The final file format will be an Intel HEX, which conveys binary information, machine code, in an ASCII file. <br>
<code>avr-objcopy -O ihex yourfile.elf yourfile.hex</code> <br>
Now, let's burn the code to the Arduino. First, you need to know the Arduino device path. Use <code>dmesg | grep ttyUSB*</code> and find the path for the ch341-UART chip (if its the only thing attached to your computer,probably it will be in dev/ttyUSB0 )
Use <br><code>avrdude -c arduino -p atmega328p -P /dev/ttyUSB0 -U flash:w:yourfile.hex</code><br> to finally send the code to the Arduino.



[Main Menu](../README.md)
