#ifndef _EFFECTS_H
#define _EFFECTS_H
#include "DrawFunctions.h"
static boolean ONflag = 1;
static byte Brightness = 5;
static byte Speed = 19;
static byte effect = 0;
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

#define LIGHTERS_AM (max(WIDTH, HEIGHT))
class EffNEXUS:public Routine
{
private:
void DotReload(byte id);
struct {
  int16_t PosX, PosY;
  int8_t SpeedX, SpeedY;
  uint8_t Color;
} Dot[LIGHTERS_AM];
public:
void run() override;
};

class EffConfetti:public Routine
{
public:
void run() override;
};

class EffRainbow:public Routine
{
private:
byte hue,mode;
public:
void run() override;
};

#define BALLS_AMOUNT max(WIDTH,HEIGHT)/4
class EffFireflies:public Routine
{
private:
int coord[BALLS_AMOUNT][2];
int8_t vector[BALLS_AMOUNT][2];
uint8_t ballColors[BALLS_AMOUNT];
public:
void run() override;
};

void deleteWPointer();
void changeEff(byte eff);
void DrawEffect();

#endif