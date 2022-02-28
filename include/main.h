/*
  FireLED_matrix
*/
#ifndef _MAIN_H
#define _MAIN_H

// ----------------- LIBRARES -----------------
#include "Arduino.h"
#include "FastLED.h"
#include "Constants.h"
#include "DrawFunctions.h"
#include "Effects.h"
#include "MatrixRunner.h"

// ----------------- VARIABLES ------------------
#define NUM_LEDS WIDTH * HEIGHT
static CRGB leds[NUM_LEDS];
static byte effect = 0;
static boolean ONflag = 1;
static boolean Ch_Eff_flag = 1;
//-------------------------------------------------------------
// ----------- START ------------------
const byte maxDim = max(WIDTH,HEIGHT);
#endif // _MAIN_H