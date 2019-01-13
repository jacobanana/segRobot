#include "LedControl.h" // dot matrix controller

#define DOT_DATA 9
#define DOT_CLK 12
#define DOT_CS 10
#define DOT_N 4

LedControl dot=LedControl(DOT_DATA,DOT_CLK,DOT_CS,DOT_N);

uint64_t BODY[] = {0x734644f8f8444673, 0xc04047f8f84740c0};
uint64_t HEART[] = {0x00387c3e3e7c3800, 0x0038442222443800};
uint64_t HEART2[] = {0xffc783c1c183c7ff, 0xffc7bbddddbbc7ff};
uint64_t IMAGES[] = {0xffe7e78181e7e7ff, 0x980c0603060c1830, 0x010080c163361c08, 0x0c183060c0603019};

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
