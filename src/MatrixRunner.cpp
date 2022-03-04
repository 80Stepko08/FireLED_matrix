#include "MatrixRunner.h"
void MatrixRun(){
	if(Ch_Eff_flag){
		changeEff(effect);
		Ch_Eff_flag=0;
	}
	if(ONflag){DrawEffect();
	}
		
	FastLED.show();
}