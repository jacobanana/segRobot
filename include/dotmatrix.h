#include "LedControl.h" // dot matrix controller

#define DOT_DATA 9
#define DOT_CLK 12
#define DOT_CS 10
#define DOT_N 4

LedControl dot=LedControl(DOT_DATA,DOT_CLK,DOT_CS,DOT_N);

uint64_t BODY = 0x734644f8f8444673;
uint64_t LEGS = 0x7fc0809f9f80c07f;
uint64_t P180 = 0x1d2444444444241c;
uint64_t P270 = 0x003c428181ff0001;

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
