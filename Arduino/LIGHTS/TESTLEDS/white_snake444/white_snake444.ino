#include "FastLED.h"

#define NUM_LEDS 50
#define DATA_PIN 6
#define CLOCK_PIN 5
#define BRIGHTNESS 255
#define MODE_DURATION 25000  // Switch modes every 10 seconds

CRGB leds[NUM_LEDS];
uint8_t gHue = 0;  // Rotating base color
bool fastMode = true;
unsigned long modeTimer = 0;

void setup() {
  FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  randomSeed(analogRead(0));
  modeTimer = millis();
}

void loop() {
  // Switch modes every MODE_DURATION milliseconds
  if(millis() - modeTimer > MODE_DURATION) {
    fastMode = !fastMode;
    modeTimer = millis();
    FastLED.clear();
  }

  if(fastMode) {
    wildNightDance();
  } else {
    cosmicSerenity();
  }
  
  FastLED.show();
}

void wildNightDance() {
  // Rapid violet/turquoise flashes with white sparks
  EVERY_N_MILLISECONDS(75) {
    fadeToBlackBy(leds, NUM_LEDS, 50);
    leds[random(NUM_LEDS)] = CRGB::White;  // White spark
    leds[random(NUM_LEDS)] = CHSV(random(160, 224), 255, 255);  // Violet
    leds[random(NUM_LEDS)] = CHSV(random(96, 128), 255, 200);    // Turquoise
  }
}

void cosmicSerenity() {
  // Slow color waves with gentle pulses
  EVERY_N_MILLISECONDS(30) {
    fadeToBlackBy(leds, NUM_LEDS, 5);  // Gentle fading

    // Update the rotating base color
    gHue = gHue + 1;  // Slow hue rotation

    // Create overlapping color waves
    for(int i = 0; i < NUM_LEDS; i++) {
      // Purpleish (Hue 192-224)
      leds[i] = CHSV(gHue + 192 + (i * 3), 255, sin8(i * 10 + millis()/20) / 2 + 128);

      // Blueish (Hue 160-192)
      leds[(i + 12) % NUM_LEDS] = CHSV(gHue + 160 + (i * 3), 255, cos8(i * 10 + millis()/15) / 2 + 128);

      // Greenish (Hue 96-128)
      leds[(i + 25) % NUM_LEDS] = CHSV(gHue + 96 + (i * 3), 200, sin8(i * 15 + millis()/25) / 2 + 128);

      // Reddish (Hue 0-32)
      leds[(i + 37) % NUM_LEDS] = CHSV(gHue + 0 + (i * 3), 255, cos8(i * 20 + millis()/30) / 2 + 128);
    }
  }
}