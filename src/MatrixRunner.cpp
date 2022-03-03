#include "MatrixRunner.h"
void changeEff(){
	if(worker != nullptr){
		delete worker;
	}
	switch(effect){
		case 0: worker = new EffFire();
		case 1: worker = new EffWCube();
}}

void MatrixRun(){
	if(Ch_Eff_flag){
		changeEff();
	}
	if(ONflag){worker->run();}
		
	FastLED.show();
}