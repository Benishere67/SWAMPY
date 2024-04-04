#include "FastLED.h"
#include <Wire.h>

#define NUM_STRIPS 6
#define NUM_LEDS_PER_STRIP 8

#define VRX_PIN  A5 // Arduino pin connected to VRX pin
#define VRY_PIN  A4 // Arduino pin connected to VRY pin

#define POTENTIOMETER_PIN A0 //POT

//set slave address
#define SLAVE_ADDR 9

//set the bit receiving size
#define ANSWERSIZE 5


CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis
const int buttonPin = 9; //joystick push down
int buttonState = 0;

uint8_t DATA = 1;
bool ToF = true;

void setup() {
  //G5 suit zone
  FastLED.addLeds<NEOPIXEL, 27>(leds[0], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 29>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 31>(leds[2], NUM_LEDS_PER_STRIP);


  //G6 suit zone
  FastLED.addLeds<NEOPIXEL, 26>(leds[3], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 28>(leds[4], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 30>(leds[5], NUM_LEDS_PER_STRIP);

  //Init I2c communication as master
  Wire.begin();

  //Setup serial monitor
  Serial.begin(9600);

  //init button as input
  pinMode(buttonPin, INPUT);

}

void loop() {
  // This outer loop will go over each strip, one at a time

  //read joystick
  buttonState = digitalRead(buttonPin);
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  Serial.print(buttonState);


  

  if(xValue > 800){
    
  } else if(xValue < 400){
    
  }


  if(yValue > 800){
    
  } else if(yValue < 400){
    
  }


  if (buttonState == HIGH) {
    
  } else {
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(0);
    Wire.endTransmission();

    
  } 
}
