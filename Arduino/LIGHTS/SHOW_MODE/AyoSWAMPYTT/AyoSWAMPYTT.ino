#include <Wire.h>
#include "FastLED.h"


#define NUM_STRIPS 6
#define NUM_LEDS_PER_STRIP 8


int GlobalB = 255;
int DelayDelay = 0;

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

  Serial.begin(9600) ;

  Wire.begin();
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

void loop() {


  if(DelayDelay > 5){
    Wire.beginTransmission(8);
    Wire.write(GlobalB);
    Wire.endTransmission();

    Wire.beginTransmission(9);
    Wire.write(GlobalB);
    Wire.endTransmission();
    DelayDelay = 0;
  }
 

    leds[random(0,5)][random(0,7)] = CHSV(random(160,224),255,GlobalB);
    FastLED.show();
    fadeToBlackBy(leds[0], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[1], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[2], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[3], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[4], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[5], NUM_LEDS_PER_STRIP, 50);
    delay(50);

    // if(MARRC < NUM_LEDS_PER_STRIP) {
    //     shootingStar();
    //     leds[0][MARRC] = CHSV(DATA,255,GlobalB);
    //     leds[1][MARRC] = CHSV(DATA,255,GlobalB);
    //     leds[2][MARRC] = CHSV(DATA,255,GlobalB);
  
    //     leds[3][MARRC] = CHSV(DATA,255,GlobalB);
    //     leds[4][MARRC] = CHSV(DATA,255,GlobalB);
    //     leds[5][MARRC] = CHSV(DATA,255,GlobalB);
        
    //     //leds[random(0,6)][random(1,144)] = CHSV(random(160,224),255,100);
    //     FastLED.show();
    //     delay(100);
    //     fadeToBlackBy(leds[0], NUM_LEDS_PER_STRIP, 50);
    //     fadeToBlackBy(leds[1], NUM_LEDS_PER_STRIP, 50);
    //     fadeToBlackBy(leds[2], NUM_LEDS_PER_STRIP, 50);
    //     fadeToBlackBy(leds[3], NUM_LEDS_PER_STRIP, 50);
    //     fadeToBlackBy(leds[4], NUM_LEDS_PER_STRIP, 50);
    //     fadeToBlackBy(leds[5], NUM_LEDS_PER_STRIP, 50);
    //     DATA += 20;
    //     MARRC++;
    // }else{
    // MARRC = 0;
    // }
  
  DelayDelay++;
}
