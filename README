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

![NodeRed-Flow](./../NodeRed-Flow/Flow1.png)


## ESP32 Default Pin Map

| Pin | Constant |  Device |
|---|---|---|
|  5 | BUZZER |Buzzer that rings on Alarms |
|  15 | LED_1 | LED which lights up on Alarms |
|  34 | PB_CANCEL | Push button input which used for cancellations and to go back |
|  25 | PB_OK | Push button input which is used for confirmations and entering the menu|
|  26 | PB_UP |  Push Button input which is used to go up in menu |
|  35 | PB_DOWN |  Push Button input which is used to go down in menu|
|  4 | DHT_PIN |  DHT11 Temperature & Humidity Sensor input|
|  36, 39 | LDR_1, LDR_2 | Input pins of the two LDRs.|
| 33 | SERVO | PWM Output for the Servo motor |

*	These are defined in the same `constants.h` file mentioned above.


# Calculations

## Light Intensity Calculation in Smart Medibox
*	In this project, we use two LDRs (Light Dependent Resistors) to measure light intensity from two directions. Based on the intensity values, the servo motor adjusts a sliding window to regulate light exposure.

Process:
*	Reading LDR Values: The LDRs are connected to analog pins of the ESP32, and we read their values using analogRead(). Each LDR gives a voltage that corresponds to the intensity of light falling on it.
	```cpp
	float leftLDRValue = analogRead(LEFT_LDR_PIN) * 1.00;
	float rightLDRValue = analogRead(RIGHT_LDR_PIN) * 1.00;
	```
  
*	Calculating Intensity: The raw LDR values are converted to intensity values (I_left and I_right) using a formula. The formula normalizes the readings between 0 and 1, where 0 is the lowest intensity and 1 is the highest.

*	Identifying the Higher Intensity: We compare the two intensities and select the higher one (I_max). The source of the higher intensity is identified (sourceLDR).
  
*	Publishing Data: The highest intensity and the source are published to the MQTT broker for remote monitoring.
  
*	Adjusting Window: The calculated intensity (I_max) is used to adjust the angle of the servo motor, which controls the sliding window to optimize the light exposure.	

	

## Calculating the Motor Angle

$$θ = \min\{\theta_{\text{offset}} \cdot D + (180 - \theta_{\text{offset}}) \cdot I \cdot \gamma, 180\}$$

| Symbol | Description |
|---|---|
| $$θ$$ | Represents the output angle. Motor rotates to this position. |
| $$\theta_{\text{offset}}$$| Represents the minimum angle that the morot will be in. This is a constant value that influences the output angle. |
| $$D$$ | Coificient of effect of LDR which changes the angle of rotation according the fact that which LDR records higher reading. |
| $$I$$ |Maximum light intensity of the two LDRs. |
| $$\gamma$$ | Controlling factor. This value scales the influence of variable "I" on the output angle. |


## Node-Red Dashboard

<img width="2406" alt="Gallery Image" src="./light.png"> |  <img width="2406" alt="Gallery Image" src="./temp.png">
:-------------------------:|:-------------------------:

# About

This project was first developed for the `EN2853 - Embedded Systems & Applications` module in Semester 4, University of Moratuwa, Department of Electrical Engineering.


[go to the top](#Smart-Medibox)


