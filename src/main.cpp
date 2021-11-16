#include <Arduino.h>

#include <../lib/led/QwiicLedStick.h>

static LED *_leds;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin();

  Serial.println("Initializing");
  _leds = new LED();
  _leds->begin();
  Serial.println("Starting");
}

void loop() {
  // put your main code here, to run repeatedly:
  _leds->setLEDBrightness(5);
  Serial.println("Red");
  _leds->setLEDColor(255, 0, 0);
  delay(200);
  Serial.println("Green");
  _leds->setLEDColor(0, 255, 0);
  delay(200);
  Serial.println("Blue");
  _leds->setLEDColor(0, 0, 255);
  delay(200);
}