#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 64


#define DATA_PIN 13
#define CLOCK_PIN 13


CRGB leds[NUM_LEDS];

void setup() { 
    
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
    
}

void loop() { 

  for(int i=0 ; i<200 ; i++)
  {
    leds[i] = CRGB::White;
    FastLED.show();
    delay(50);
  }

   }

