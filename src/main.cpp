/*
 * Adrien Fauconnet - 2018
 * Segment display experiments
 * ------
 * Define _3461AS_ or _5011BS_
 * Include segment.h
 * call setupDisplay() in setup()
 * ------
 */

#define _3461AS_ // 4 digit
// #define _5011BS_ // 1 digit

#include "Arduino.h"
#include "dotmatrix.h"
#include "segment.h"          // segment display
#include "neo.h"              // neopixel
#include "robot.h"            // robot graphics

void setup(){
  setupDisplay(0);
  setupPixels(255);
  setupDots();

  randomMouth();
  randomEyes();
  colorSpeed = 50;
}

void loop(){
  matrix(0, IMAGES[0]);
  matrix(1, IMAGES[1]);
  matrix(2, IMAGES[2]);
  matrix(3, IMAGES[3]);


  if (millis()-now3 >= colorSpeed){
    rainbow();
    now3 = millis();
  }

  if (millis()-now1 >= t1){
    drawEyes();
    body = (body + 1 == 2 ? 0: body + 1);
  }

  if (millis()-now2 >= t2){
    drawMouth();
  }

  delay(1);
}
