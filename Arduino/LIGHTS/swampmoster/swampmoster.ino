#include "FastLED.h"
#include <pixelset.h>

#define NUM_LEDS 50
#define DATA_PIN 7       

CRGB leds[NUM_LEDS];

uint8_t DATA = 1;
bool ToF = true;

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(255);
  Serial.begin(9600);
}

void loop() {

  for(int i = 0; i < NUM_LEDS; i++) {
      shootingStar();
      leds[i] = CHSV(DATA,255,255);
      //leds[NUM_LEDS - i] = CHSV(DATA,255,255);
      leds[random(1,NUM_LEDS)] = CHSV(random(160,224),255,100);
      FastLED.show();
      delay(50);
      fadeToBlackBy(leds, NUM_LEDS, 50);
 
      
  }

  for(int i = NUM_LEDS - 1; i >= 0; i--) {
      shootingStar();
      leds[i] = CHSV(DATA,255,255);
      //leds[i - NUM_LEDS] = CHSV(DATA,255,255);
      leds[random(1,NUM_LEDS)] = CHSV(random(160,224),255,100);
      FastLED.show();
      delay(50);
      fadeToBlackBy(leds, NUM_LEDS, 50);
 
  }
}

  void shootingStar(){
    if(DATA == 224){
      ToF == false;
    }
    else if(DATA == 0){
      ToF == true;
    }
    if(ToF == true){
      DATA++;
    }else if(ToF == false){
      DATA--;
    }
}
