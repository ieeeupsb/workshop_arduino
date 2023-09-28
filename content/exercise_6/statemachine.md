# State Machine Exercise

In this exercise, you have to do the following [LabWork](./Lab0.pdf) and implemtent it in a state machine. It is designed to use on a Raspberry Pi Pico, but is very easy to adapt to the board you are using.
READ THE WHOLE INFO BEFORE STARTING

## Step 1 - What does a State Machine look like?

Here the idea is for you to design a state machine for each exercise. 
It's the best practice to always design a State Machine before implementing it!
For a little more explanation about State Machines refer to this [Github Page](https://github.com/ieeeupsb/workshop_ESP8266/blob/master/content/statemachines.md) from an old workshop

![image](https://github.com/ieeeupsb/workshop_arduino/assets/71400611/371a43ad-d155-4515-b97a-b8e1c0ff4bb1)

## Step 2 -  How do I structure my code to use a State Machine?

Well, first of all, you'll be running inside a loop. That loop is time based.
Then you need to structure the code in the following way:
1. Update your Sensors (Input) variables
2. Read the Sensors (Input)
3. Update state -> check if the transition is True and if you change state
4. Update your output variables related to the state you are currently in
5. Write to your Outputs

Words are easy, and I know it is hard to imagine how this is done, so in the example below you have explained each part of the code!
As there are some parts ommiting because you are supposed to use this code has reference, it's not wrong to check the solution!

## Step 3 - Reference Code

So now you are good to start doing the exercises! Copy the code below to your main.cpp and start implementing it!
With @brief, it is explaining the purpose of the segment below!

```C++
#include <Arduino.h>

/**
 * @brief 	Define your pin connections to each IO
 *
 */
#define LED1_pin 6
#define LED2_pin

#define S1_pin 2
#define S2_pin

/**
 * @brief	THe structure that representes the state machine you are working in.
 * 			This is how you track the current state you are in.
 *			Whenever you change state you update tes to current time and tis to 0.
 *			When you are running the loop, you update tis based on the tes and the current elapsed time
 */
typedef struct
{
	int state, new_state;

	// tes - time entering state
	// tis - time in state
	unsigned long tes, tis;
} fsm_t;

/**
 * @brief	In this example you only have two input variables corresponding to the buttons, but you can have as many as you need.
 * 			There are you variables for each input, to detect falling and rising edges. You can see how it works in the loop. *
 */
// Input variables
uint8_t S1, prevS1;
uint8_t S2, prevS2;

/**
 * @brief 	Not much to say, output variables that keep the state your output is at.
 * 			THESE ARE NOT REFERING TO THE PIN.
 */
// Output variables
uint8_t LED_1, LED_2;

/**
 * @brief 	Initialization of existing state machines
 *
 */
// Our finite state machines
fsm_t fsm1, fsm2;

unsigned long interval, last_cycle;
unsigned long loop_micros;

/**
 * @brief 	Every cycle, before updating writing to your outputs, you update your state.
 * 			When running, if you detected a condition that makes you change state, you update fsm.new_state. fsm.state is only updated inside this funtion.
 *			Here you update tes and tis
 */
// Set new state
void set_state(fsm_t &fsm, int new_state)
{
	if (fsm.state != new_state)
	{ // if the state chnanged tis is reset
		fsm.state = new_state;
		fsm.tes = millis();
		fsm.tis = 0;
	}
}

void setup()
{
	pinMode(LED1_pin, OUTPUT);
	pinMode(LED2_pin, OUTPUT);
	pinMode(S1_pin, INPUT);
	pinMode(S2_pin, INPUT);

	// Start the serial port with 115200 baudrate
	Serial.begin(115200);

	/**
	 * @brief 	Referes to the period you'll be reading your cycle.
	 * 			In this case, you run the loop every 10 milliseconds
	 */
	interval = 10;
	/**
	 * @brief 	Initialize state machine
	 */
	set_state(fsm1, 0);
	set_state(fsm2, 0);
}

/**
 * @brief 	Look into the loop to understand the order in which you execute the state machine
 *			THERE ARE 4 MAIN STEPS
 */
void loop()
{
	// To measure the time between loop() calls
	// unsigned long last_loop_micros = loop_micros;

	// Do this only every "interval" miliseconds
	// It helps to clear the switches bounce effect
	unsigned long now = millis();
	if (now - last_cycle > interval)
	{
		loop_micros = micros();
		last_cycle = now;

		/**
		 * @brief 	FIRST STEP - Update the prev readings and and read the new inputs.
		 */

		// Read the inputs
		prevS1 = S1;
		S1 = !digitalRead(S1_pin);

		// FSM processing

		// Update tis for all state machines
		unsigned long cur_time = millis(); // Just one call to millis()
		fsm1.tis = cur_time - fsm1.tes;
		fsm2.tis = cur_time - fsm2.tes;

		/**
		 * @brief 	SECOND STEP - Depending on your fsm.state, compare with your readings and update the state machine fsm.new_state
		 */

		// Calculate next state for the first state machine
		if (fsm1.state == 0 && S1)
		{
			fsm1.new_state = ...;
		}
		else if (fsm1.state == 1 && !S1)
		{
			fsm1.new_state = ...;
		}
		else if (fsm1.state == 1 && fsm1.tis > 1000)
		{
			fsm1.new_state = ...;
		}
		else if ...

		//
		//	Implement here the second state machine if needed
		//


		/**
		 * @brief Update the states!
		 */
		// Update the states
		set_state(fsm1, fsm1.new_state);
		set_state(fsm2, ...);

		/**
		 * @brief 	THIRD STEP - Update your output variables value depending on the state
		 */
		// Actions set by the current state of the first state machine
		if (fsm1.state == 0)
		{
			LED_1 = 0;
		}
		else if (fsm1.state == 1)
		{
			LED_1 = 1;
		}
		else if (fsm1.state == 2)
		{
			LED_1 = ...
		}


		/**
		 * @brief 	FOURTH STEP - Write to your sensors!
		 */

		// Set the outputs
		digitalWrite(LED1_pin, LED_1);
		digitalWrite(..., LED_2);

		// Debug using the serial port
		Serial.print("S1: ");
		Serial.print(S1);

		Serial.print(" S2: ");#include <Arduino.h>

/**
 * @brief 	Define your pin connections to each IO
 *
 */
#define LED1_pin 6
#define LED2_pin

#define S1_pin 2
#define S2_pin

/**
 * @brief	THe structure that representes the state machine you are working in.
 * 			This is how you track the current state you are in.
 *			Whenever you change state you update tes to current time and tis to 0.
 *			When you are running the loop, you update tis based on the tes and the current elapsed time
 */
typedef struct
{
	int state, new_state;

	// tes - time entering state
	// tis - time in state
	unsigned long tes, tis;
} fsm_t;

/**
 * @brief	In this example you only have two input variables corresponding to the buttons, but you can have as many as you need.
 * 			There are you variables for each input, to detect falling and rising edges. You can see how it works in the loop. *
 */
// Input variables
uint8_t S1, prevS1;
uint8_t S2, prevS2;

/**
 * @brief 	Not much to say, output variables that keep the state your output is at.
 * 			THESE ARE NOT REFERING TO THE PIN.
 */
// Output variables
uint8_t LED_1, LED_2;

/**
 * @brief 	Initialization of existing state machines
 *
 */
// Our finite state machines
fsm_t fsm1, fsm2;

unsigned long interval, last_cycle;
unsigned long loop_micros;

/**
 * @brief 	Every cycle, before updating writing to your outputs, you update your state.
 * 			When running, if you detected a condition that makes you change state, you update fsm.new_state. fsm.state is only updated inside this funtion.
 *			Here you update tes and tis
 */
// Set new state
void set_state(fsm_t &fsm, int new_state)
{
	if (fsm.state != new_state)
	{ // if the state chnanged tis is reset
		fsm.state = new_state;
		fsm.tes = millis();
		fsm.tis = 0;
	}
}

void setup()
{
	pinMode(LED1_pin, OUTPUT);
	pinMode(LED2_pin, OUTPUT);
	pinMode(S1_pin, INPUT);
	pinMode(S2_pin, INPUT);

	// Start the serial port with 115200 baudrate
	Serial.begin(115200);

	/**
	 * @brief 	Referes to the period you'll be reading your cycle.
	 * 			In this case, you run the loop every 10 milliseconds
	 */
	interval = 10;
	/**
	 * @brief 	Initialize state machine
	 */
	set_state(fsm1, 0);
	set_state(fsm2, 0);
}

/**
 * @brief 	Look into the loop to understand the order in which you execute the state machine
 *			THERE ARE 4 MAIN STEPS
 */
void loop()
{
	// To measure the time between loop() calls
	// unsigned long last_loop_micros = loop_micros;

	// Do this only every "interval" miliseconds
	// It helps to clear the switches bounce effect
	unsigned long now = millis();
	if (now - last_cycle > interval)
	{
		loop_micros = micros();
		last_cycle = now;

		/**
		 * @brief 	FIRST STEP - Update the prev readings and and read the new inputs.
		 */

		// Read the inputs
		prevS1 = S1;
		S1 = !digitalRead(S1_pin);

		// FSM processing

		// Update tis for all state machines
		unsigned long cur_time = millis(); // Just one call to millis()
		fsm1.tis = cur_time - fsm1.tes;
		fsm2.tis = cur_time - fsm2.tes;

		/**
		 * @brief 	SECOND STEP - Depending on your fsm.state, compare with your readings and update the state machine fsm.new_state
		 */

		// Calculate next state for the first state machine
		if (fsm1.state == 0 && S1)
		{
			fsm1.new_state = ...;
		}
		else if (fsm1.state == 1 && !S1)
		{
			fsm1.new_state = ...;
		}
		else if (fsm1.state == 1 && fsm1.tis > 1000)
		{
			fsm1.new_state = ...;
		}
		else if ...

		//
		//	Implement here the second state machine if needed
		//


		/**
		 * @brief Update the states!
		 */
		// Update the states
		set_state(fsm1, fsm1.new_state);
		set_state(fsm2, ...);

		/**
		 * @brief 	THIRD STEP - Update your output variables value depending on the state
		 */
		// Actions set by the current state of the first state machine
		if (fsm1.state == 0)
		{
			LED_1 = 0;
		}
		else if (fsm1.state == 1)
		{
			LED_1 = 1;
		}
		else if (fsm1.state == 2)
		{
			LED_1 = ...
		}


		/**
		 * @brief 	FOURTH STEP - Write to your sensors!
		 */

		// Set the outputs
		digitalWrite(LED1_pin, LED_1);
		digitalWrite(..., LED_2);

		// Debug using the serial port
		Serial.print("S1: ");
		Serial.print(S1);

		Serial.print(" S2: ");
		Serial.print(S2);

		Serial.print(" fsm1.state: ");
		Serial.print(fsm1.state);

		Serial.print(" LED_1: ");
		Serial.print(LED_1);

		Serial.print(" LED_2: ");
		Serial.print(LED_2);

		Serial.print(" loop: ");
		Serial.println(micros() - loop_micros);
	}
}

		Serial.print(S2);

		Serial.print(" fsm1.state: ");
		Serial.print(fsm1.state);

		Serial.print(" LED_1: ");
		Serial.print(LED_1);

		Serial.print(" LED_2: ");
		Serial.print(LED_2);

		Serial.print(" loop: ");
		Serial.println(micros() - loop_micros);
	}
}

}
```

DISCLAIMER: This LabWork is used in ACE classes and isn't IEEE property!

[Home](./../../README.md)

[See solution](./solution/main.cpp)
