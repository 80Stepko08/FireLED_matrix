#ifndef __CONSTANTS_H
#define __CONSTANTS_H
// ============================== SETTINGS ==================================
// ---------------- MATRIX --------------
//__________ BRIGHTNESS AND POWER ________
#define BRIGHTNESS 50        // Brightness limit (0-255)
#define CURRENT_LIMIT 2000    // mA (0 - off) 
//_____________________ SIZE _____________
#define WIDTH 8
#define HEIGHT 8
#define NUM_LEDS WIDTH * HEIGHT
//_____________________ COLOR ______________
#define COLOR_ORDER GRB
//_______________ TYPE AND DIRECTION ______
#define MATRIX_TYPE 1         // 0 - zigzag, 1 - paralel
#define CONNECTION_ANGLE 2    // 0 - bottom left, 1 - top left, 2 - top right, 3 - bottom right
#define STRIP_DIRECTION 3     // 0 - right, 1 - up, 2 - left, 3 - down
//___________________ OTHER _____________
#define SEGMENTS 1
//#define XY_MAPPING
// ----------------- CONNECTING AND CONTROL ------------
#define LED_PIN 4
//___________________ BUTTON _____________
#define USE_BUTTON
#define BTN_PIN 6
#define BTN_PULL 0
#define NUM_EFFECTS 3
//________________________________________
#endif
