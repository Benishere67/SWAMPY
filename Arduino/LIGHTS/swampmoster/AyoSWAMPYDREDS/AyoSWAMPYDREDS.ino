#include "FastLED.h"
#define NUM_STRIPS 6
#define NUM_LEDS_PER_STRIP 8
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

uint8_t DATA = 1;
bool ToF = true;

void setup() {
  //G5
  FastLED.addLeds<NEOPIXEL, 27>(leds[0], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 29>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 31>(leds[2], NUM_LEDS_PER_STRIP);


  //G6
  FastLED.addLeds<NEOPIXEL, 26>(leds[3], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 28>(leds[4], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 30>(leds[5], NUM_LEDS_PER_STRIP);

  
  //DREDS
  FastLED.addLeds<NEOPIXEL, 7>(leds[6], NUM_LEDS_PER_STRIP);

}

void loop() {
  // This outer loop will go over each strip, one at a time
  

  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
      shootingStar();
      leds[0][i] = CHSV(DATA,255,255);
      leds[1][i] = CHSV(DATA,255,255);
      leds[2][i] = CHSV(DATA,255,255);

      leds[3][i] = CHSV(DATA,255,255);
      leds[4][i] = CHSV(DATA,255,255);
      leds[5][i] = CHSV(DATA,255,255);

      leds[6][i] = CHSV(160,255,255);
      
      //leds[random(0,6)][random(1,144)] = CHSV(random(160,224),255,100);
      FastLED.show();
      delay(50);
      fadeToBlackBy(leds[0], NUM_LEDS_PER_STRIP, 50);
      fadeToBlackBy(leds[1], NUM_LEDS_PER_STRIP, 50);
      fadeToBlackBy(leds[2], NUM_LEDS_PER_STRIP, 50);
      fadeToBlackBy(leds[3], NUM_LEDS_PER_STRIP, 50);
      fadeToBlackBy(leds[4], NUM_LEDS_PER_STRIP, 50);
      fadeToBlackBy(leds[5], NUM_LEDS_PER_STRIP, 50);

      fadeToBlackBy(leds[6], NUM_LEDS_PER_STRIP, 50);
      DATA += 20;
 
      
  }

  for(int i = NUM_LEDS_PER_STRIP - 1; i >= 0; i--) {
      shootingStar();
      leds[0][i] = CHSV(DATA,255,255);
      leds[1][i] = CHSV(DATA,255,255);
      leds[2][i] = CHSV(DATA,255,255);

      leds[3][i] = CHSV(DATA,255,255);
      leds[4][i] = CHSV(DATA,255,255);
      leds[5][i] = CHSV(DATA,255,255);

      leds[6][i] = CHSV(160,255,255);
      
      //leds[random(0,6)][random(1,144)] = CHSV(random(160,224),255,100);
      FastLED.show();
      delay(50);
      fadeToBlackBy(leds[0], NUM_LEDS_PER_STRIP, 50);
      fadeToBlackBy(leds[1], NUM_LEDS_PER_STRIP, 50);
      fadeToBlackBy(leds[2], NUM_LEDS_PER_STRIP, 50);
      fadeToBlackBy(leds[3], NUM_LEDS_PER_STRIP, 50);
      fadeToBlackBy(leds[4], NUM_LEDS_PER_STRIP, 50);
      fadeToBlackBy(leds[5], NUM_LEDS_PER_STRIP, 50);

      fadeToBlackBy(leds[6], NUM_LEDS_PER_STRIP, 50 );
      DATA+= 20;
 
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
