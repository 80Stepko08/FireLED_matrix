#include "Effects.h"
void EffFire::run(){
		  EffFire::t += Speed;
  for (byte x = 0; x < WIDTH; x++) {
    for (byte y = 0; y < HEIGHT; y++) {
     
      int16_t Bri = inoise8(x * 64, (y * 64) - t) - (y * (255 / HEIGHT));
      byte Col = Bri;// inoise8(x * scale, (y * scale) - t) - (y * (255 / LED_ROWS));
       if (Bri < 0) Bri = 0; if(Bri != 0) Bri = 256 - (Bri * 0.2);
      nblend(leds[XY(x, y)], ColorFromPalette(HeatColors_p, Col, Bri), Speed);}
  }
};

void EffWCube::run()
{
  if (loadingFlag)
  {
    loadingFlag = false;
    Dot.PosX = WIDTH / 2 * 10;
    Dot.PosY = HEIGHT / 2 * 10;
    Dot.SpeedX = random(4, 10);
    Dot.SpeedY = random(4, 10);

    deltaValue = map(random(), 0, 255, 1, (uint8_t)min(WIDTH, HEIGHT)-2);
    Dot.Color = random(0, 9) * 28;
  }
    for (uint8_t i = 0U; i < deltaValue; i++)
      for (uint8_t j = 0U; j < deltaValue; j++)
        leds[XY(Dot.PosX / 10 + i, Dot.PosY / 10 + j)] = _pulse_color;
  Dot.PosX += Dot.SpeedX;

  if (Dot.PosX < 0)
  {
    Dot.PosX = 0;
    Dot.SpeedX = -Dot.SpeedX;
	Dot.Color = random(0, 9) * 28;
  }
  Dot.PosY += Dot.SpeedY;
  if (Dot.PosY < 0)
  {
    Dot.PosY = 0;
    Dot.SpeedY = -Dot.SpeedY;
    Dot.Color = random(0, 9) * 28;
  }

  if (Dot.PosX > (int16_t)((WIDTH - deltaValue) * 10))
  {
    Dot.PosX = (WIDTH - deltaValue) * 10;
    Dot.SpeedX = -Dot.SpeedX;
    Dot.Color = random(0, 9) * 28;
  }
  if (Dot.PosY > (int16_t)((HEIGHT - deltaValue) * 10))
  {
    Dot.PosY = (HEIGHT - deltaValue) * 10;
    Dot.SpeedY = -Dot.SpeedY;
    Dot.Color = random(0, 9) * 28;
  }
  else
    FastLED.clear();

  for (uint8_t i = 0U; i < deltaValue; i++)
    for (uint8_t j = 0U; j < deltaValue; j++)
      drawPixelXY(Dot.PosX / 10 + i, Dot.PosY / 10 + j, CHSV(Dot.Color, 255, 255));
};

void EffNEXUS::DotReload(byte id) {
  Dot[id].SpeedY = random(0, 4); //Direction
  Dot[id].Color = random();
  switch (Dot[id].SpeedY) {
    case 0:   // вверх
      Dot[id].PosX = random(0, (WIDTH - 1) * 10); // Разбрасываем капли по ширине
      Dot[id].PosY = 0;  // и по высоте
      break;
    case 1:   //  вниз
      Dot[id].PosX = random(0, (WIDTH - 1) * 10); // Разбрасываем капли по ширине
      Dot[id].PosY = (HEIGHT - 1) * 10; // и по высоте
      break;
    case 2:   // вправо
      Dot[id].PosX = 0; // Разбрасываем капли по ширине
      Dot[id].PosY = random(0, (HEIGHT - 1) * 10); // и по высоте
      break;
    case 3:   // влево
      Dot[id].PosX = (WIDTH - 1) * 10; // Разбрасываем капли по ширине
      Dot[id].PosY = random(0, (HEIGHT - 1) * 10); // и по высоте
      break;
    default:
      break;
  }
}

void EffNEXUS::run() {
  if (loadingFlag) {
    for (byte i = 0; i < LIGHTERS_AM; i++) {
      DotReload(i);
    }
    loadingFlag = false;
  }
  fadeToBlackBy(leds, NUM_LEDS, 11);
  for (byte i = 0; i < LIGHTERS_AM; i++) {
    switch (Dot[i].SpeedY)
    {
      case 0:   // вверх
        Dot[i].PosY += 2;
        break;
      case 1:   //  вниз
        Dot[i].PosY -= 2;
        break;
      case 2:   // вправо
        Dot[i].PosX += 2;
        break;
      case 3:   // влево
        Dot[i].PosX -= 2;
        break;
      default:
        break;
    }
    if (Dot[i].PosY < 0) {
      DotReload(i);
    }

    if (Dot[i].PosY > (HEIGHT - 1) * 10) {
      DotReload(i);
    }
    if (Dot[i].PosX < 0) {
      DotReload(i);
    }
    if (Dot[i].PosX > (WIDTH - 1) * 10) {
      DotReload(i);
    }
    drawPixelXY(Dot[i].PosX / 10, Dot[i].PosY / 10, CHSV(Dot[i].Color,255,255));
  }
}

void EffConfetti::run(){
    for (byte i = 0; i < 3; i++) {
      byte x = random(0, WIDTH);
      byte y = random(0, HEIGHT);
      if (!leds[XY(x, y)])
        leds[XY(x, y)] = CHSV(random(0, 255), 255, 255);
}}

  void EffRainbow::run(){
    if (loadingFlag) {
      loadingFlag = false;
      byte mode = random()%3;
    }
    hue += 3;
	switch (mode){
    case 0:
      for (byte i = 0; i < WIDTH; i++) {
        CHSV thisColor = CHSV((byte)(hue + i * float(255 / WIDTH)), 255, 255);
        for (byte j = 0; j < HEIGHT; j++)
          drawPixelXY(i, j, thisColor);
    }
	break;
    case 1:
      for (byte j = 0; j < HEIGHT; j++) {
        CHSV thisColor = CHSV((byte)(hue + j * float(255 / HEIGHT)), 255, 255);
        for (byte i = 0; i < WIDTH; i++)
          drawPixelXY(i, j, thisColor);
    }
    break;
	case 2:
	 for (byte x = 0; x < WIDTH; x++) {
      for (byte y = 0; y < HEIGHT; y++) {
        CHSV thisColor = CHSV((byte)(hue + (float)(WIDTH / HEIGHT * x + y) * (float)(255 / maxDim)), 255, 255);
        drawPixelXY(x, y, thisColor); //leds[getPixelNumber(i, j)] = thisColor;
      }
    }
	break;
	
}}

  void EffFireflies::run() {
    if (loadingFlag) {
      loadingFlag = false;
      for (byte j = 0; j < BALLS_AMOUNT; j++) {
        int sign;

        // забиваем случайными данными
        coord[j][0] = WIDTH / 2 * 10;
        random(0, 2) ? sign = 1 : sign = -1;
        vector[j][0] = random(4, 15) * sign;
        coord[j][1] = HEIGHT / 2 * 10;
        random(0, 2) ? sign = 1 : sign = -1;
        vector[j][1] = random(4, 15) * sign;
        ballColors[j] = random(0, 9) * 28;
      }
    }
    fadeToBlackBy(leds,NUM_LEDS,120);


    // движение шариков
    for (byte j = 0; j < BALLS_AMOUNT; j++) {
      ballColors[j] ++;
      // движение шариков
      for (byte i = 0; i < 2; i++) {
        coord[j][i] += vector[j][i];
        if (coord[j][i] < 0) {
          coord[j][i] = 0;
          vector[j][i] = -vector[j][i];
        }
      }

      if (coord[j][0] > (WIDTH - 1) * 10) {
        coord[j][0] = (WIDTH - 1) * 10;
        vector[j][0] = -vector[j][0];
      }
      if (coord[j][1] > (HEIGHT - 1) * 10) {
        coord[j][1] = (HEIGHT - 1) * 10;
        vector[j][1] = -vector[j][1];
      }
      leds[XY(coord[j][0] / 10, coord[j][1] / 10)] =  CHSV(ballColors[j], 255, 255);
    }
 }

static Routine* worker = nullptr;
void deleteWPointer(){
	if(worker != nullptr){
		delete worker;
	}
}
void changeEff(byte eff){
	deleteWPointer();
	switch(eff){
		case 0: worker = new EffFire();break;
		case 1: worker = new EffWCube();break;
		case 2: worker = new EffNEXUS();break;
		case 3: worker = new EffConfetti();break;
		case 4: worker = new EffRainbow();break;
		case 5: worker = new EffFireflies();break;
}}

void DrawEffect(){
	worker->run();
}