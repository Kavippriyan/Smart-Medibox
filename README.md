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


*   This was developed using Platform IO with Arduino Framework. (You can use the code in branch [`Wokwi`]([https://github.com/chathura-de-silva/Smart-Medibox/tree/Wokwi](https://github.com/Kavippriyan/Smart-Medibox)), if you are looking forward for a simulation. But note that it lack some newly added features including Node-Red connectivity.)
