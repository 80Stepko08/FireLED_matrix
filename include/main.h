/*
  FireLED_matrix
*/
#ifndef _MAIN_H
#define _MAIN_H

// ----------------- LIBRARES -----------------
#include "Arduino.h"
#include "FastLED.h"
#include "SButton.h"
#include "Constants.h"
// ----------------- VARIABLES ------------------
#define NUM_LEDS WIDTH * HEIGHT
extern CRGB leds[NUM_LEDS];
//-------------------------------------------------------------
#include "Control.h"
//#include "DrawFunctions.h"
//#include "Effects.h"
#include "MatrixRunner.h"
// ----------- START ------------------
const byte maxDim = max(WIDTH,HEIGHT);
#endif // _MAIN_H