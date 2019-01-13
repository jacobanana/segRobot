#include "LedControl.h" // dot matrix controller

#define DOT_DATA 9
#define DOT_CLK 12
#define DOT_CS 10
#define DOT_N 4

LedControl dot=LedControl(DOT_DATA,DOT_CLK,DOT_CS,DOT_N);

void setupDots(){
  for(int address=0;address<DOT_N;address++) {
    /*The MAX72XX is in power-saving mode on startup*/
    dot.shutdown(address,false);
    /* Set the brightness to a medium values */
    dot.setIntensity(address,8);
    /* and clear the display */
    dot.clearDisplay(address);
  }
}

void matrix(uint8_t address, byte image[]){
  for(uint8_t i=0; i<8; i++){
      dot.setRow(address, i, image[i]);
  }
}

void matrix(uint8_t address, uint64_t image){
  for(uint8_t i=0; i<8; i++){
    byte row = (image >> i * 8) & 0xFF;
    dot.setRow(address, i, row);
  }
}
