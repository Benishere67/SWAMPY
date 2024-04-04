#include <FastLED.h>
#define NUM_LEDS 1
#define DATA_PIN 2


// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
    FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
  
}

void loop() { 
  // Turn the LED on, then pause
  leds[0] = CHSV(50,255,50);
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(500);
}
