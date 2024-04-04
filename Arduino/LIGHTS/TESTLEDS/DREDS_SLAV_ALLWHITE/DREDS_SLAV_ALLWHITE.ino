#include "FastLED.h"
#include <Wire.h>;
#define NUM_STRIPS 10
#define NUM_LEDS_PER_STRIP 8
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];


int LEDBRIGHTNESS = 100;
int GivenBrightness = 100;

int foreight = 0;
int fornine = 0;
int RFM = 3;
int MR = 0;
bool LIT = false;

uint8_t DATA = 1;
bool ToF = true;


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

  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600) ;


}

void loop() {
  DATA += 20;
  shootingStar();
  if(fornine < 10){
    if(foreight < 8){
      if(LIT == true){
        leds[fornine][foreight] = CHSV(random(145,210),255,LEDBRIGHTNESS);
      }else{
        leds[fornine][foreight] = CHSV(random(145,210),255,GivenBrightness);
      }
      FastLED.show();
//      fadeToBlackBy(leds[0], NUM_LEDS_PER_STRIP, 50);
//      fadeToBlackBy(leds[1], NUM_LEDS_PER_STRIP, 50);
//      fadeToBlackBy(leds[2], NUM_LEDS_PER_STRIP, 50);
//      fadeToBlackBy(leds[3], NUM_LEDS_PER_STRIP, 50);
//      fadeToBlackBy(leds[4], NUM_LEDS_PER_STRIP, 50);
//      fadeToBlackBy(leds[5], NUM_LEDS_PER_STRIP, 50);
//      fadeToBlackBy(leds[6], NUM_LEDS_PER_STRIP, 50);
//      fadeToBlackBy(leds[7], NUM_LEDS_PER_STRIP, 50);
//      fadeToBlackBy(leds[8], NUM_LEDS_PER_STRIP, 50);
//      fadeToBlackBy(leds[9], NUM_LEDS_PER_STRIP, 50);
      fornine++;
      delay(100);
    }else{
      if(MR < RFM){
        LIT = true;
        foreight = foreight - 2;
        LEDBRIGHTNESS = LEDBRIGHTNESS / 2;
        MR++;
      }else{
      foreight = 0;
      fornine = 0;
      LIT = false;
      MR = 0;
      LEDBRIGHTNESS = GivenBrightness;
      }
    }
  }else{
    fornine = 0;
    foreight++;
  }
}


void receiveEvent(int howMany) {
  Serial.println("incoming data");
  while (1 < Wire.available()) {
  }
  int x = Wire.read();    // receive byte as an integer
  GivenBrightness = x;
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
