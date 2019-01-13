#include "Adafruit_NeoPixel.h"
#define NEO_PIN 11
#define DEFAULT_PIXEL_MODE 0

Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, NEO_PIN, NEO_GRB + NEO_KHZ800);
uint8_t rainbowCount = 0;
uint8_t pixelMode = 1;

void setupPixels(uint8_t brightness){
  strip.begin(); // initialize the neopixels
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(brightness);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


void rainbow(){
  switch (pixelMode){
    case 0:
      for(uint8_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + rainbowCount) & 255));
      }
    break;

    case 1:
      for(uint8_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, Wheel(rainbowCount));
      }
    break;

    default:
      pixelMode = DEFAULT_PIXEL_MODE;
    break;
  }

  strip.show();
  rainbowCount++;
}
