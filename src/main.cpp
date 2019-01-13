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
#include "segment.h" // segment display
#include "neo.h" // neopixel

#define N_EYES 4
#define N_MOUTH 4

uint8_t eyes[N_EYES] = {
  SEG_A+SEG_B+SEG_G+SEG_F,
  SEG_A+SEG_B+SEG_G+SEG_F,
  SEG_G,
  SEG_A};
uint8_t mouths[N_MOUTH][2] ={
  {SEG_D, SEG_D},
  {SEG_D+SEG_E+SEG_G, SEG_D+SEG_C+SEG_G},
  {SEG_E+SEG_D, SEG_C+SEG_D},
  {SEG_E+SEG_G, SEG_C+SEG_G}
};

uint8_t e1, e2, m, speed;
uint16_t t1, t2;
long now1, now2, now3;

void randomEyes(){
  e1 = random() % N_EYES;
  e2 = random() % N_EYES;
  t1 = (random() % 600) + 600; // eyes drawing delay
}

void randomMouth(){
  m = random() % N_MOUTH;
  t2 = (random() % 600) + 100; // mouth drawing delay
}

void drawEyes(){
  setDigit(0, eyes[e1]);
  setDigit(3, eyes[e2]);
  randomEyes();
  now1 = millis();
}

void drawMouth(){
  setDigit(1, mouths[m][0]);
  setDigit(2, mouths[m][1]);
  randomMouth();
  now2 = millis();
}


void setup(){
  setupDisplay(0);
  setupPixels(255);
  setupDots();

  randomMouth();
  randomEyes();
  speed = 250;
}

void loop(){
  matrix(3, BODY);
  //matrix(2, LEGS);
  //matrix(2, P180);
  //matrix(3, P270);

  if (millis()-now3 >= speed){
    rainbow();
    now3 = millis();
  }

  if (millis()-now1 >= t1){
    drawEyes();
  }

  if (millis()-now2 >= t2){
    drawMouth();
  }

  delay(1);
}
