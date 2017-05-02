# Chep Talk

Ok, by now you must feel you are the best hacker in the neighbourhood, but hang on.

Maybe your roomate has an Arduino making music with a buzzer and you have a robot that walks around the house. How about merging the two?! You would have an annoying robot that not only stalks you but also makes your brains come out with that irritating noise! 

Imagine, that for some reason you find that a fantastic idea, and for some other odd reason you hate your roomate's code and don't want to have nothing to do with it. What if you could make your Arduino communicate with his Arduino and you could program the two Arduinos independently?

Ok, lets dive in.

To communicate you need a channel to make that communication flow. That being said, in Arduino you send data through the TX (Transmit) pin and receive through the RX (Receive) pin. So, as you might guessed it you need to connect one Arduino TX to the other Arduino RX and vice-versa, moreover for stability reasons you should connect the two Ground pins to make sure the two grounds are at the same level, as show bellow:

<div style="text-align:center"><img src ="images/rx_tx.png" /></div>

That on an Arduino would be something like this:

<div style="text-align:center"><img src ="images/serial.png" /></div>

Connecting these cables is like puting two persons infront of each other, but they don't know what to say and what speed can they talk in order to maintain and understandable communication.

For speed you have to define this in your ```void setup()``` like this:

```Arduino
Serial.begin(9600);
```

In general communicatios speed is defined as a baud rate which is the speed that you can transmit a symbol from a certain dictionary. Too giberish? We find knowing this irrelevant at this point but you can read more [here](https://electronics.stackexchange.com/questions/214303/baud-rate-vs-bit-rate).

For now we'll stick to 9600 as the baud rate because it's not too fast but for this example is way more than we actually need, so we can minimize communication errors, since speed isn't really a issue here.

One important thing to note here is that both Arduino's must communicate at the same speed (or baud rate).

To really send the data you just need to print on to it, with:

```Arduino
Serial.println("String to send");
```

# Let's get our hands dirty!

Now to put this all to practise we'll do a calculator! You know some stuff now, lets give you a challenge!

Make a program that sends two integers separated by a space. If you feel a bit confused you can learn more at [Arduino Serial Documentation](https://www.arduino.cc/en/reference/serial) which you can find information about Serial Serial function on Arduino.

Go ahead! When you are done and then call one of the guys from the workshop and ask them for the calculator!

All that his Arduino will do is get your two numbers, add them together and if the result is greater that 10 it will light up a led on his end.

This is their code:

```Arduino
int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  String data = "";

  data = Serial.readStringUntil('\n'); //Read one entire print (until the line break)

  if (!data.equals("")) {
    // Read numbers
    int n1 = data.substring(0, 1).toInt();;
    int n2 = data.substring(2, 3).toInt();;

    // Calculate the result
    int result = n1 + n2;

    // Apply LED status logic
    if (result > 10) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }
}
```

Feeling powerful now? Now you have reasons to, but what come next is promissing!

[Main Menu](../README.md) | [Next](./watchMePlease.md)
