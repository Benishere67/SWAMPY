String command;
#include <FastLED.h>
#define NUM_LEDS 1
#define DATA_PIN 2

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);


  leds[0] = CRGB::Black;
  FastLED.show();

}

void loop() {


  Serial.println("hello"); 
  if (Serial.available()) {
    command = Serial.readStringUntil('\n');
    command.trim();
    if (command.equals("on")) {
      leds[0] = CHSV(50,255,50);
      FastLED.show();
    }

    else if (command.equals("off")) {
      leds[0] = CRGB::Black;
      FastLED.show();
    }
  }

  delay(1000);
}
