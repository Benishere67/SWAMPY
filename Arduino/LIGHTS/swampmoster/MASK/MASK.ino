#include "FastLED.h"
#include <Wire.h>;
#define NUM_STRIPS 11
#define NUM_LEDS_PER_STRIP 4
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];



int GivenBrightness = 100;
bool adder = false;

void setup() {
  
  FastLED.addLeds<NEOPIXEL, 3>(leds[0], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 4>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 5>(leds[2], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 6>(leds[3], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 7>(leds[4], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 8>(leds[5], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 9>(leds[6], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 10>(leds[7], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 11>(leds[8], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 12>(leds[9], NUM_LEDS_PER_STRIP);

  FastLED.addLeds<NEOPIXEL, A0>(leds[10], 4);

  Wire.begin(9);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600) ;

}

void loop() {
  if(adder == true){
    FullLight();
    adder = false;
  } else if(adder == false){
    IshLight();
    adder = true;
  }
}

void receiveEvent(int howMany) {
  Serial.println("incoming data");
  while (1 < Wire.available()) {
  }
  int x = Wire.read();    // receive byte as an integer
  GivenBrightness = x;
}

void FullLight(){
  for(int i = 0; i <= 9; i++) {
     for(int j = 0;j <= 3;j++){
      leds[i][j] = CHSV(random(0,224),255,GivenBrightness);
      FastLED.show();
      delay(40);
    }
  }
  delay(400);
  for(int i = 0; i <= 4; i++) {
    leds[10][i] = CHSV(random(160,224),255,GivenBrightness/2);
    FastLED.show();
    delay(50);
  }
  for(int i = 3; i >= 0; i--) {
    leds[10][i] = CHSV(200,255,0);
    FastLED.show();
    delay(20);
  }

  for(int i = 0; i <= 4; i++) {
      leds[10][i] = CHSV(random(160,224),255,GivenBrightness);
      FastLED.show();
      delay(120);
    }
  delay(1300);
  
  for(int i = 0; i <= 8; i++) {
    for(int i = 0; i <= 4; i++) {
      leds[10][i] = CHSV(random(160,224),255,GivenBrightness/2);
      FastLED.show();
      delay(120);
      fadeToBlackBy(leds[0], NUM_LEDS_PER_STRIP, 10);
      fadeToBlackBy(leds[1], NUM_LEDS_PER_STRIP, 10);
      fadeToBlackBy(leds[2], NUM_LEDS_PER_STRIP, 10);
      fadeToBlackBy(leds[3], NUM_LEDS_PER_STRIP, 10);
      fadeToBlackBy(leds[4], NUM_LEDS_PER_STRIP, 10);
      fadeToBlackBy(leds[5], NUM_LEDS_PER_STRIP, 10);
      fadeToBlackBy(leds[6], NUM_LEDS_PER_STRIP, 10);
      fadeToBlackBy(leds[7], NUM_LEDS_PER_STRIP, 10);
      fadeToBlackBy(leds[8], NUM_LEDS_PER_STRIP, 10);
      fadeToBlackBy(leds[9], NUM_LEDS_PER_STRIP, 10);
    }
  }
  
  delay(200);



  for(int j = 0;j <= 3;j++){
    for(int i = 0; i <= 9; i++) {
      leds[i][j] = CHSV(200,255,0);
      FastLED.show();
      delay(50);
    }
  }

  for(int i = 3; i >= 0; i--) {
    leds[10][i] = CHSV(200,255,0);
    FastLED.show();
    delay(250);
  }

  delay(1200);
}

void IshLight(){
  for(int i = 0; i <= 6; i++) {
     for(int i = 0; i <= 4; i++) {
       for(int j = 0;j <= 3;j++){
        leds[i][j] = CHSV(random(0,224),255,GivenBrightness);
        leds[i+5][j] = CHSV(random(0,224),255,GivenBrightness);
        FastLED.show();
        delay(70);
        fadeToBlackBy(leds[0], NUM_LEDS_PER_STRIP, 50);
        fadeToBlackBy(leds[1], NUM_LEDS_PER_STRIP, 50);
        fadeToBlackBy(leds[2], NUM_LEDS_PER_STRIP, 50);
        fadeToBlackBy(leds[3], NUM_LEDS_PER_STRIP, 50);
        fadeToBlackBy(leds[4], NUM_LEDS_PER_STRIP, 50);
        fadeToBlackBy(leds[5], NUM_LEDS_PER_STRIP, 50);
        fadeToBlackBy(leds[6], NUM_LEDS_PER_STRIP, 50);
        fadeToBlackBy(leds[7], NUM_LEDS_PER_STRIP, 50);
        fadeToBlackBy(leds[8], NUM_LEDS_PER_STRIP, 50);
        fadeToBlackBy(leds[9], NUM_LEDS_PER_STRIP, 50);
      }
    }
  }
  for(int i = 0; i <= 18; i++) {
    delay(70);
    fadeToBlackBy(leds[0], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[1], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[2], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[3], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[4], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[5], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[6], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[7], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[8], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[9], NUM_LEDS_PER_STRIP, 50);
    FastLED.show();
  }
  delay(800);
}
