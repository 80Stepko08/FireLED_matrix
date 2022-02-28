#include "MatrixRunner.h"
void changeEff(){
	if(worker){
	}
	switch(effect){
		case 0: worker = std::unique_ptr<EffFire>(new EffFire());
		case 1: worker = std::unique_ptr<EffWCube>(new EffWCube());
}}

void MatrixRun(){
	if(Ch_Eff_flag){
		changeEff();
	}
	if(ONflag){worker->run();}
		
	FastLED.show();
}