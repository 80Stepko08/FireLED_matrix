#include "Control.h"
#include "SButton.h"
#ifdef USE_BUTTON
Sbutton btn(BTN_PIN, BTN_PULL);
#endif
bool changeDir = 1;
void changePower(byte mode = 2){
	switch(mode){
	case 0:ONflag = 0;break;
	case 1:ONflag = 1;break;
	default:ONflag = !ONflag;break;}
    if (ONflag) {
		changeEff(effect);
    } else {
		deleteWPointer();
        FastLED.clear();
    }
    delay(2);
    FastLED.show();
}

void LoadC_Settings(){
}
void Control(){
	btn.tick();
 if(btn.hasSingle()){
	 changePower();
 }
 if(btn.hasDouble()){
	 if(ONflag){
		 effect++;
		 if(effect>=NUM_EFFECTS) effect = 0;
		changeEff(effect);
	 }
 }
  if(btn.hasTriple()){
	 if(ONflag){
		 if(effect<= 0) effect = NUM_EFFECTS-1;
		 else effect--;
		changeEff(effect);
	 }
 }
 if(btn.isHeld()){
 changeDir =! changeDir;}
 if(btn.isHold())
	 switch(btn.hasClicksWithHold()){
		 case 0: Brightness = constrain(Brightness + (Brightness / 25 + 1) * (changeDir * 2 - 1), 1 , 255); FastLED.setBrightness(Brightness); break;
	 case 1: Speed = constrain(Speed + (Speed/ 25 + 1) * (changeDir * 2 - 1), 1 , 255); break;}
}
