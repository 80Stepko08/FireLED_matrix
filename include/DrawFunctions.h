#ifndef _DRAWFUNCTIONS_H
#define _DRAWFUNCTIONS_H
#include "Arduino.h"
#include "FastLED.h"
#include "Constants.h"
// ----------------- VARIABLES ----------------
#define NUM_LEDS WIDTH * HEIGHT
extern CRGB leds[NUM_LEDS];
const byte maxDim = max(WIDTH,HEIGHT);
extern uint16_t XY(uint8_t x, uint8_t y);
extern void drawPixelXY(uint8_t x, uint8_t y, CRGB color);
#endif