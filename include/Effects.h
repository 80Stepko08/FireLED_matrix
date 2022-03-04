#ifndef _EFFECTS_H
#define _EFFECTS_H
#include "DrawFunctions.h"
class Routine
{
public:
  virtual void run();
protected:
  bool loadingFlag = true;
};

class EffFire:public Routine
{
private:
 uint32_t t;
public:
void run() override;	
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
void run() override;	
};
void changeEff(byte eff);
void DrawEffect();

#endif