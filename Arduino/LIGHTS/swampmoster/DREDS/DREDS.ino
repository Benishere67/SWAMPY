#include "FastLED.h"
#define NUM_STRIPS 10
#define NUM_LEDS_PER_STRIP 8
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

void setup() {
  
  FastLED.addLeds<NEOPIXEL, 2>(leds[0], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 3>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 4>(leds[2], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 5>(leds[3], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 6>(leds[4], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 7>(leds[5], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 8>(leds[6], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 9>(leds[7], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 10>(leds[8], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 11>(leds[9], NUM_LEDS_PER_STRIP);


}

void loop() {

  for(int i = 0; i <= 9; i++) {
     for(int j = 0;j <= 8;j++){
      leds[i][j] = CHSV(random(0,224),255,50);
      FastLED.show();
      delay(40);
    }
  }

  delay(1000);

  for(int j = 0;j <= 8;j++){
    for(int i = 0; i <= 9; i++) {
      leds[i][j] = CHSV(200,255,0);
      FastLED.show();
      delay(50);
    }
  }

 

  delay(1200);




  
}
