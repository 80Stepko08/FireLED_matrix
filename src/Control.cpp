#include "Control.h"
static InterruptDrivenButton button(BTN_PIN);
DEFINE_IDB_ISR(button);
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
	#ifdef USE_BUTTON
	button.setup(IDB_ISR(button));
	#endif
}
void Control(){
	
	if (!button.hasEvent()) {
        return;
    }

    InterruptDrivenButtonEvent event = button.pollEvent();
    if (!event.type) {
        return;
    }

    if (event.type == IDB_EVENT_CLICKS) {
        switch (event.clicks) {
            case 1:
                changePower();
                break;

            case 2:
                if (!ONflag) {
                    return;
                }

                // следующий эффект
                if (effect == NUM_EFFECTS - 1) {
                    effect = 0;
                } else {
                    effect++;
                }
                changeEff(effect);
                break;

            case 3:
                if (!ONflag) {
                    return;
                }

                // предыдущий эффект
                if (effect == 0) {
                     effect = NUM_EFFECTS - 1;
                } else {
                     effect--;
                }
				changeEff(effect);
                break;

}}}

void ButtonTick(){
	button.loop();
}