#include "FastLED.h"
#include <Wire.h>;
#define NUM_STRIPS 6
#define NUM_LEDS_PER_STRIP 8
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];


//set slave address
#define DRED_SLAVE_ADDR 9
#define MASK_SLAVE_ADDR 8

//set the bit receiving size
#define ANSWERSIZE 5

//for shooting start<<>>
uint8_t DATA = 1;
bool ToF = true;

int DelayDelay = 0;
int GlobalB = 100;

void setup() {

  //G5 ZONE
  FastLED.addLeds<NEOPIXEL, 27>(leds[0], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 29>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 31>(leds[2], NUM_LEDS_PER_STRIP);


  //G6 ZONE
  FastLED.addLeds<NEOPIXEL, 26>(leds[3], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 28>(leds[4], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 30>(leds[5], NUM_LEDS_PER_STRIP);


  //Init I2c communication as master
  Wire.begin();

  //Setup serial monitor
  Serial.begin(9600);

  //byte x = 100;

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
  
  // This outer loop will go over each strip, one at a time
  for(int x = 0; x < NUM_STRIPS; x++) {
    // This inner loop will go over each led in the current strip, one at a time
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
      shootingStar();
      leds[x][i] = CHSV(DATA,255,GlobalB);
      FastLED.show();
      leds[x][i] = CRGB::Black;
      delay(100);
    }

    //if(DelayDelay > 5){
      Wire.beginTransmission(DRED_SLAVE_ADDR);
      Wire.write(GlobalB);
      Wire.endTransmission();

      Wire.beginTransmission(MASK_SLAVE_ADDR);
      Wire.write(GlobalB);
      Wire.endTransmission();

      //Serial.println("B="+x);
      
    //  DelayDelay = 0;
    //}else{
    //  DelayDelay++;
    //}
  }
}
