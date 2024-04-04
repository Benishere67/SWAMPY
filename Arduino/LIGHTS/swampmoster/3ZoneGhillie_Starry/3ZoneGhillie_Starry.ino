#include "FastLED.h"
#define NUM_STRIPS 6
#define NUM_LEDS_PER_STRIP 8
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

int fadeDensity = 1;

int Count = fadeDensity;

void setup() {
  //G5
  FastLED.addLeds<NEOPIXEL, 27>(leds[0], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 29>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 31>(leds[2], NUM_LEDS_PER_STRIP);

  //G6
  FastLED.addLeds<NEOPIXEL, 26>(leds[3], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 28>(leds[4], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 30>(leds[5], NUM_LEDS_PER_STRIP);

}

void loop() {
  if(Count = fadeDensity){
    leds[random(0,6)][random(1,8)] = CHSV(random(160,224),255,100);
        FastLED.show();
        delay(10);
        Count = 0;
  }else{
        delay(60);
//        fadeToBlackBy(leds[0], NUM_LEDS_PER_STRIP, 50);
//        fadeToBlackBy(leds[1], NUM_LEDS_PER_STRIP, 50);
//        fadeToBlackBy(leds[2], NUM_LEDS_PER_STRIP, 50);
    Count++;
  }
}
