![Banner](./repoBanner.png)


# Smart Medibox

Smart medibox is a smart device that,
1. Remind the user to take medicine at time through alarms.
2. Help to keep medicine in the required conditions via monitoring temperature and humidity continously and notifying the user if there is a bad condition.
3. Controlling the light entering the Medibox through a motorized curtain.

# Technologies and Components

*   This project is developed to use
    *   ADAFRUIT SSD 1306 OLED Monochrome Display (128x64)
    *   ESP32 Devkit V1
    *   DHT11 Temperature and Humidity Sensor. (Easily configurable for DHT22 aswell.)
	*	SG90 Micro Server Motor
	*	LDRs and 10kΩ Resistors 

	out of the box.

If the components change, you may have to change some parameters accordingly. 


## platform.ini

```ini
[env:esp32doit-devkit-v1]
platform = espressif32
board = esp32doit-devkit-v1
framework = arduino
lib_deps = 
	adafruit/Adafruit GFX Library@^1.11.9
	adafruit/Adafruit SSD1306@^2.5.9
	adafruit/DHT sensor library@^1.4.6
	roboticsbrno/ServoESP32@1.0.3
	knolleary/PubSubClient@^2.8
	bblanchon/ArduinoJson@^7.0.4
```


*   This was developed using Platform IO with Arduino Framework. (You can use the code in branch [`Wokwi`]](https://github.com/Kavippriyan/Smart-Medibox), if you are looking forward for a simulation. But note that it lack some newly added features including Node-Red connectivity.)

# Getting Started

## Prerequisites
*   Git
*   Platform I/O with Arduino Framework Set up.
*   Relevant hardware for testing if you are not intended to do simulations.
*	Node-Red Installed Environment and an MQTT Broker (Both optional)


## Node-Red Dashboard

*	After completing the above step, all the basic and the major functionalities of will work except for the Node-Red based functionalities. Use following instructions for successfully deploy an instance of the Node-Red Dashboard.

*	Import the `./Nodered Flows/flows.json` to the Node-Red canvas.
*	Setup required parameters of the flows including the MQTT server and then deploy. (This is defaulted to the Mosquito testing server.)


# Configuration and Structure

## Codebase
* Three seperate header files inside `./include` directory :
	*	`Constants.h` : Contains all constants.
	*	`Functions.h` : Contains declarations of all global functions.
	*	`Globals.h` : Contains declarations of all the global constants.
*	The initialisation and definitions of variables and functions are done in the relavant `.cpp` files.

*	`main.cpp` contains the arduino *loop()* and *setup()* functions.

* The device code is developed in such a way that it's actively listening(polling) for user inputs and for collecting sensor data from the DHT sensor. 
*	For an instance the three function calls in loop() function is responsible for,
	1.	`update_time_with_check_alarm()` - Updates the the time on the display. Checks whether there are any alarms to be rung at the moment. Calls `ring_alarm()` inside it if there is any.

	2.	`go_to_menu()` - Activelly listening for button presses and then keeps track of the selected mode by user via an abstract variable. When user confirms a menu item via pressing OK button, the `run_mode(mode)` is called. `run_mode(mode)` handles the rest via somr another nested function calls.

	3.	`check_temp()` - Reads the data from the `DHT11` sensor, prints a warning in the display if there is any parameter that is out of the specified limits. If there isn't any, plays an animation on the screen indicating it is actively monitoring those parameters.


## Node-Red Dashboard Flow

![Node-Red Flow](./../NodeRed-Flow/Flow1.png)

*	`defmedConfig()` node includes the default parameters for preset light control parameters. In it's "On Start" tab, you can adjust them accordingly.
*	`Default Starting Parameters Trigger` includes Default values for above parameters on startup. 

*	Medibox sends Temperature and Light Data to the Dashboard through broker and this MQTT requests are generated only when those parameters get a considerable change in their value.

*	On the otherhand, the Dashboard sends the required motor angle to the Medibox. This is also done only when there is a considerable change pending.

*	Sensivity of gauges, Plots, and even the change in parameters needed for triggering MQTT Requests can be configured easily.
	```cpp
		#define EPSILON 0.03
		#define TEMPSILON 0.01
	```
	*	`EPSILON` and `TEMPSILON` is the minimum difference needed in previous and current values of the readings of two LDRs and of the Temparature Sensor respectively to Medibox to generate and send an MQTT Request. 



