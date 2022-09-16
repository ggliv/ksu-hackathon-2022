#define WaterSensor A0
#include "DHT.h"  
#define DHTPIN 2
#define DHTTYPE DHT11


float sensorValue = 0;

// Setup the water pump
int motorPin = 3;

// Setup the buzzer
const int buzzer = 9; // pin 9
DHT dht(DHTPIN,DHTTYPE);

void setup(){
  pinMode(motorPin,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  /* ToDo
  1 -> Get the reading from soil moisture
  2 -> Get the reading from the pH meter
  3 -> Get the reading from the humidity sensor
  4 -> If moisture and humidity are too low, open the pump
  5 -> If they are too high, then do nothing
  6 -> If there is error, notify user by buzzer and led
  */
}
