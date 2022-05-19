#include "main.h"
CRGB leds[NUM_LEDS];
// ----------- START ----------------- 
void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(Brightness);
	if (CURRENT_LIMIT > 0) FastLED.setMaxPowerInVoltsAndMilliamps(5, CURRENT_LIMIT);
	randomSeed(analogRead(0));
	FastLED.clear();
	FastLED.show();
	changeEff(effect);
#if defined(MOSFET_PIN) && defined(MOSFET_LEVEL)          // установка сигнала в пин, управляющий MOSFET транзистором, соответственно состоянию вкл/выкл матрицы
  digitalWrite(MOSFET_PIN, ONflag ? MOSFET_LEVEL : !MOSFET_LEVEL);
#endif
}

void loop() {
	MatrixRun();
}
