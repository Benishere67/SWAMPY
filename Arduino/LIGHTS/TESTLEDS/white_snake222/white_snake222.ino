#include "FastLED.h"

#define NUM_LEDS 50
#define DATA_PIN 6
#define CLOCK_PIN 5
#define BRIGHTNESS 255
#define MODE_DURATION 25000  // Switch modes every 25 seconds

CRGB leds[NUM_LEDS];
uint8_t gHue = 0;  // Rotating base color
unsigned long modeTimer = 0;
int mode = 0; // Track the current mode

void setup() {
  FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  randomSeed(analogRead(0));
  modeTimer = millis();
}

void loop() {
  // Switch modes every MODE_DURATION milliseconds
  if(millis() - modeTimer > MODE_DURATION) {
    mode = (mode + 1) % 3; // Cycle through 3 modes
    modeTimer = millis();
    FastLED.clear();
  }

  if(mode == 0) {
    wildNightDance();
  } else if(mode == 1) {
    cosmicSerenity();
  } else {
    stackingEffect();
  }
  
  FastLED.show();
}

void wildNightDance() {
  // Rapid violet/turquoise flashes with white sparks
  EVERY_N_MILLISECONDS(75) {
    fadeToBlackBy(leds, NUM_LEDS, 50);
    leds[random(NUM_LEDS)] = CRGB::White;  // White spark
    leds[random(NUM_LEDS)] = CHSV(random(160, 224), 255, 255); // Random color
  }
}

void cosmicSerenity() {
  // Smooth color wave effect
  fill_rainbow(leds, NUM_LEDS, gHue, 7);
  gHue += 1;
}

void stackingEffect() {
  static int stackHeight = 0;
  static CRGB stackColor = CRGB::White;
  static unsigned long lastUpdate = 0;

  if (millis() - lastUpdate > 200) {
    if (stackHeight < NUM_LEDS) {
      leds[stackHeight] = stackColor;
      stackHeight++;

      if (stackHeight > NUM_LEDS / 3 && random(6) == 0) {
        stackColor = CHSV(random(0, 255), 255, 255); // 5:1 chance of color change
      }
    } else {
      delay(5000); // Pause for 5 seconds
      for (int i = NUM_LEDS - 1; i >= 0; i--) {
        leds[i].fadeToBlackBy(50);
        FastLED.show();
        delay(100);
      }
      stackHeight = 0;
      stackColor = CRGB::White;
    }
    lastUpdate = millis();
  }
}
