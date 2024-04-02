#include <FastLED.h>
#define NUM_LEDS 64
#define DATA_PIN 13
#define CLOCK_PIN 13
CRGB leds[NUM_LEDS];

void ledsetup()
{
 FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}
void ledblinkYellow()
{
  for(int i=0 ; i<64 ; i++)
    {
      leds[i] = CRGB::Yellow;
      FastLED.show();
      delay(50);
    }
}
void ledblinkWhite()
{
  for(int i=0 ; i<64 ; i++)
  {
    leds[i] = CRGB::White;
    FastLED.show();
    delay(50);
  }
}
void ledTurnOff()
{
 // Now turn the LED off, then pause
  for(int i=0 ; i<64 ; i++)
  {
    leds[i] = CRGB::Black;
  }
  //leds[0] = CRGB::Black;
  FastLED.show();

}
void ledblink()
{
  int num =10;
  for(int i=0 ; i<num ; i++)
  {
    leds[i] = CRGB::White;
    FastLED.show();
    delay(50);
  }
  for(int i=num ; i<num+10 ; i++)
  {
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(50);
  }
  num=num+10;
    for(int i=num ; i<num+10 ; i++)
  {
    leds[i] = CRGB::Yellow;
    FastLED.show();
    delay(50);
  }
  num=num+10;
     for(int i=num ; i<num+10 ; i++)
  {
    leds[i] = CRGB::Green;
    FastLED.show();
    delay(50);
  } 
  num=num+10;
      for(int i=num ; i<num+10 ; i++)
  {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(50);
  }
   num=num+10;
      for(int i=num; i<num+4; i++)
  {
    leds[i] = CRGB::Purple;
    FastLED.show();
    delay(50);
  } 
   num=num+4;
    for(int i=num ; i<num+10 ; i++)
  {
    leds[i] = CRGB::Pink;
    FastLED.show();
    delay(50);
  }
   
  // Now turn the LED off, then pause
    for(int i=0 ; i<64 ; i++)
  {
    leds[i] = CRGB::Black;
  }
  //leds[0] = CRGB::Black;
  FastLED.show();
  delay(500);

}