#include "DHT.h"
#include "Servo.h"
#include "GravityTDS.h" // https://github.com/DFRobot/GravityTDS
#define DHTTYPE DHT11

// digital pins
const int DHT_PIN = 2;
const int RED_LED_PIN = 9;
const int GREEN_LED_PIN = 8;
const int BUZZER_PIN = 4;
const int SERVO_PIN = 7;

// analog pins
const int TDS_PIN = A0;
const int WATER_LEVEL_PIN = A12;

// set up the dht
DHT dht(DHT_PIN,DHTTYPE);
// set up the servo
Servo servo;
// up the tds
const float TDS_REFERENCE_VOLTAGE = 5.0;
GravityTDS gravityTds;

void setup() {
  Serial.begin(9600);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  servo.attach(SERVO_PIN);
  servo.write(0);
  
  dht.begin();

  gravityTds.setPin(TDS_PIN);
  gravityTds.setAref(TDS_REFERENCE_VOLTAGE);
  gravityTds.setAdcRange(1024);
  gravityTds.begin();
}

void loop() {
  /*SETUP*/
  float humidity, temperature;
  int waterLevel, totalDissolvedSolids;

  // humidity/temperature checking
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  // water level checking
  waterLevel = analogRead(WATER_LEVEL_PIN);

  // total dissolved solids checking
  gravityTds.setTemperature(temperature);
  gravityTds.update();
  totalDissolvedSolids = gravityTds.getTdsValue();

  // sanity checks
  if (isnan(humidity) || isnan(temperature) || isnan(waterLevel) || isnan(totalDissolvedSolids)) {
    error();
  }

  /*MAIN LOOP*/
  if (waterLevel < 50 && humidity < 25) {
    openPump(5000);
  } else {
    // noop
  }
}

void error() {
  Serial.println(F("Something went wrong."));
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, HIGH);
  tone(BUZZER_PIN, 500, 1000);  
}

void openPump(int duration) {
  servo.write(180);
  delay(duration);
  servo.write(0);
}
