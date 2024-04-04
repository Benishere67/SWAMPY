#include <Wire.h>
#include "FastLED.h"


#define NUM_STRIPS 6
#define NUM_LEDS_PER_STRIP 8

#define DRED_SLAVE_ADDR 9
#define MASK_SLAVE_ADDR 8


int GlobalB = 255;
int DelayDelay = 0;

CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

uint8_t DATA = 1;
bool ToF = true;

void setup() {

  Serial.begin(9600);

  //G5
  FastLED.addLeds<NEOPIXEL, 27>(leds[0], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 29>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 31>(leds[2], NUM_LEDS_PER_STRIP);


  //G6
  FastLED.addLeds<NEOPIXEL, 26>(leds[3], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 28>(leds[4], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 30>(leds[5], NUM_LEDS_PER_STRIP);


  Wire.begin();
}

void shootingStar(){
    if(DATA == 224){
      ToF = false;
    }
    else if(DATA == 0){
      ToF = true;
    }
    if(ToF == true){
      DATA++;
    }else if(ToF == false){
      DATA--;
    }
}

void loop() {

  if(DelayDelay >= 10){
    Wire.beginTransmission(DRED_SLAVE_ADDR);
    Wire.write(GlobalB);
    Wire.endTransmission();

    Wire.beginTransmission(MASK_SLAVE_ADDR);
    Wire.write(GlobalB);
    Wire.endTransmission();
    DelayDelay = 0;
  }else{
    DelayDelay++;
  }
 

    leds[random(0,NUM_STRIPS)][random(0,NUM_LEDS_PER_STRIP)] = CHSV(random(160,224),255,GlobalB);
    FastLED.show();
    fadeToBlackBy(leds[0], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[1], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[2], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[3], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[4], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[5], NUM_LEDS_PER_STRIP, 50);
    delay(50);

  
  DelayDelay++;
}
