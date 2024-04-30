#include "FastLED.h"
#include <Wire.h>
#define NUM_STRIPS 10
#define NUM_LEDS_PER_STRIP 8
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];



//MAIN DREADLOCK arduino nano code [BENJI]

int currentBrightness = 255; // Current brightness for LEDs
int GivenBrightness = 255;
int currentToBlack = 25;

bool mode1 = true;
bool mode2 = false;

int currentLED = 0; // Tracks the current LED position
bool increasing = true; // Direction indicator: true if forward, false if backward

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

  randomSeed(analogRead(0)); //readpin flux for random gen seed ;)

  Wire.begin(9); // Begin I2C communication on address 8
  Wire.onReceive(receiveEvent); // Register event for receiving data
  Serial.begin(9600); // Begin Serial communication for debugging
}

void loop() {
  for (int strip = 0; strip < NUM_STRIPS; strip++) {
    leds[strip][currentLED] = CHSV(random(145, 210), 255, currentBrightness);
    leds[random(0,NUM_STRIPS)][random(0,NUM_LEDS_PER_STRIP)] = CHSV(random(10, 130), 200, currentBrightness);
    FastLED.show();
    delay(100); // Staggered delay for each strip
    for (int i = 0; i < NUM_STRIPS; i++) {
      fadeToBlackBy(leds[i], NUM_LEDS_PER_STRIP, currentToBlack);
    }
  }

  // Update the currentLED based on the direction
  if (increasing) {
    currentLED++;
    if (currentLED >= NUM_LEDS_PER_STRIP - 1) { // If at the end, switch direction
      increasing = false;
    }
  } else { // Moving backward
    if (currentLED > 0) {
      currentLED--;
    } else {
      increasing = true; // Switch direction once at the start
    }
  }

  currentBrightness = GivenBrightness;
}

// void receiveEvent(int howMany) {
//   //Serial.println("incoming data");
//   while (1 < Wire.available()) {
//   }
//   int x = Wire.read();    // receive byte as an integer
//   GivenBrightness = x;
// }


void receiveEvent(int howMany) {
  if(howMany >= 3) {
    char c = Wire.read(); // Receive byte as a character
    mode1 = (c== '1');
    c = Wire.read();
    mode2 = (c== '1');

    String briStr;
    while (Wire.available()) {
      c = Wire.read();
      briStr+= c;
    }

    GivenBrightness = briStr.toInt();
  }



  //int x = Wire.read(); // Receive byte
  //Serial.println(x); // Print the byte
}
