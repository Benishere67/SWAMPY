#include <Wire.h>
#include "FastLED.h"
//#include <Adafruit_GFX.h>
//#include <Adafruit_SSD1306.h>

#define NUM_STRIPS 6
#define NUM_LEDS_PER_STRIP 8

//#define SCREEN_WIDTH 128 // OLED display width, in pixels
//#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define POTENTIOMETER_PIN A7
#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A2 // Arduino pin connected to VRY pin



//
//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int buttonPin = A6;

int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis
int currentButtonState = 0;
bool ButtonstateM = false;
bool Bjp = false;
int POTvalue = 0;
int MARRC = 0;
bool Left = false;
bool Right = false;
bool Up = false;
bool Down = false;

int GlobalB = 50;
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


  pinMode(A6, INPUT);

//  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) { // Address 0x3D for 128x64
//    Serial.println(F("SSD1306 allocation failed"));
//    for(;;);
//  }
//  delay(2000);
//  display.clearDisplay();
//  display.setTextSize(1);
//  display.setTextColor(WHITE);
//  display.setCursor(0, 10);
//  // Display static text
//  display.println("RGB_MONSTER");
//  display.display(); 

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
  currentButtonState = digitalRead(buttonPin);
  POTvalue = analogRead(POTENTIOMETER_PIN);
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  GlobalB = ((POTvalue/1023.0)*255);
  byte x = GlobalB;


  if(currentButtonState == 0 && Bjp == false){
    ButtonstateM = !ButtonstateM;
    Bjp=true;
  }else if(currentButtonState == 1){
    Bjp=false;
  }
  
  if(xValue > 800){
    Down = true;
  
  } else if(xValue < 200){
    Up = true;
  }

  if(yValue > 800){
    Left = true;
  } else if(yValue < 200){
    Right = true;
  }

  Serial.println(currentButtonState);

  if(DelayDelay > 5){
    Wire.beginTransmission(8);
    Wire.write(x);
    Wire.endTransmission();

    Wire.beginTransmission(9);
    Wire.write(x);
    Wire.endTransmission();
    DelayDelay = 0;
  }
 
 if (ButtonstateM == true) {
    leds[random(0,5)][random(0,7)] = CHSV(random(160,224),255,GlobalB);
    FastLED.show();
    fadeToBlackBy(leds[0], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[1], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[2], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[3], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[4], NUM_LEDS_PER_STRIP, 50);
    fadeToBlackBy(leds[5], NUM_LEDS_PER_STRIP, 50);
    delay(30);
  }else{
    if(MARRC < NUM_LEDS_PER_STRIP) {
        shootingStar();
        leds[0][MARRC] = CHSV(DATA,255,GlobalB);
        leds[1][MARRC] = CHSV(DATA,255,GlobalB);
        leds[2][MARRC] = CHSV(DATA,255,GlobalB);
  
        leds[3][MARRC] = CHSV(DATA,255,GlobalB);
        leds[4][MARRC] = CHSV(DATA,255,GlobalB);
        leds[5][MARRC] = CHSV(DATA,255,GlobalB);
        
        //leds[random(0,6)][random(1,144)] = CHSV(random(160,224),255,100);
        FastLED.show();
        delay(100);
        fadeToBlackBy(leds[0], NUM_LEDS_PER_STRIP, 50);
        fadeToBlackBy(leds[1], NUM_LEDS_PER_STRIP, 50);
        fadeToBlackBy(leds[2], NUM_LEDS_PER_STRIP, 50);
        fadeToBlackBy(leds[3], NUM_LEDS_PER_STRIP, 50);
        fadeToBlackBy(leds[4], NUM_LEDS_PER_STRIP, 50);
        fadeToBlackBy(leds[5], NUM_LEDS_PER_STRIP, 50);
        DATA += 20;
        MARRC++;
    }else{
    MARRC = 0;
    }
  }
  DelayDelay++;
}
