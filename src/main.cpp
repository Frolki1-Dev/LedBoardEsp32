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
  _leds->LEDOff();
}