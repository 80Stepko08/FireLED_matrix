#ifndef _EFFECTS_H
#define _EFFECTS_H
#include "main.h"
#include "DrawFunctions.h" 
class Routine
{
public:
  virtual bool run();
protected:
  bool loadingFlag = true;
};

Routine* worker = nullptr;

class EffFire:public Routine
{
private:
 uint32_t t;
public:
bool run() override;	
};

class EffWCube:public Routine
{
private:
byte deltaValue;
CRGB _pulse_color;
struct {
  int16_t PosX, PosY;
  int8_t SpeedX, SpeedY;
  uint8_t Color;
} Dot;
public:
bool run() override;	
};

#endif