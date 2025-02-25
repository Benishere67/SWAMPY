#include "FastLED.h"

#define NUM_LEDS 50
#define DATA_PIN 6
#define CLOCK_PIN 5

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(255);
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[random(NUM_LEDS)] = CHSV(random(160, 224), 255, 100);
    FastLED.show();
    delay(20);
    fadeToBlackBy(leds, NUM_LEDS, 50);
  }
}