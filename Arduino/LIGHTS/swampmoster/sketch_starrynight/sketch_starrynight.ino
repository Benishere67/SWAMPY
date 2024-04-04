#include "FastLED.h"
#include <pixelset.h>

#define NUM_LEDS 144
#define DATA_PIN 7       

CRGB leds[NUM_LEDS];

uint8_t DATA = 0;

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(255);
  Serial.begin(9600);
}

void loop() {

  for(int i = 0; i < NUM_LEDS; i++) {
    
      leds[random(1,255)] = CHSV(random(160,224),255,100);
      FastLED.show();
      delay(20);
      fadeToBlackBy(leds, NUM_LEDS, 50);
 
      
  }


}
