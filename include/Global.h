#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHTesp.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <ESP32Servo.h>

int days = 0;
int hours  =0;
int minutes = 0;
int seconds = 0;

unsigned long timeNow = 0;
unsigned long timeLast = 0;

bool alarm_enabled = false;
int n_alarms = 3;
int alarm_hours[] = {0, 1, 2};
int alarm_minutes[] = {1, 10, 20};
bool alarm_triggered[] = {false, false, false};

int n_notes = 8;
int C = 260;
int D = 290;
int E = 320;
int F = 350;
int G = 260;
int A = 290;
int B = 320; 
int C_H = 350;
int notes[] = {C,D,E,F,G,A,B,C_H};

int current_mode = 0;
int max_modes = 5;
String modes[] = {"1 - Set Time", "2 - Set Alarm 1", "3 - Set Alarm 2", "4 - Set Alarm 3", "5 - Disable Alarms"};

int leftLDRValue = 0;
int rightLDRValue = 0;
float I_left = 0.0;
float I_right = 0.0;
float I_max = 0.0;
String sourceLDR = "";

bool isScheduledON = false;
unsigned long scheduledOnTime;

// D value when LDR gives max intensity
const float D_left = 1.5; 
const float D_right = 0.5; 

// Default value
float minAngle = 30.0; 
float controlFactor = 0.75; 