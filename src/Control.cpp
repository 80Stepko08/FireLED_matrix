#include "Control.h"
#ifdef USE_BUTTON
Sbutton btn(BTN_PIN, BTN_PULL);
#endif
void changePower(byte mode = 2){
	switch(mode){
	case 0:ONflag = 0;break;
	case 1:ONflag = 1;break;
	default:ONflag = !ONflag;break;
    if (ONflag) {
        uint8_t brightness = Brightness;
        for (int i = 0; i < brightness; i += 8) {
            FastLED.setBrightness(i);
            delay(1);
            FastLED.show();
        }
        FastLED.setBrightness(brightness);
		
    } else {
        uint8_t brightness = Brightness;
        for (int i = brightness; i > 8; i -= 8) {
            FastLED.setBrightness(i);
            delay(1);
            FastLED.show();
        }
		deleteWPointer();
        FastLED.clear();
    }

    delay(2);
    FastLED.show();
}
}
void LoadC_Settings(){
}
void Control(){
 if(btn.hasSingle()){
	 changePower();
 }
 if(btn.hasDouble()){
	 if(ONflag){
		 effect++;
		 if(effect>NUM_EFFECTS) effect = 0;
		changeEff(effect);
	 }
 }
}

void ButtonTick(){
	btn.tick();
}