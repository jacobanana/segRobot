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
#include "segment.h"

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

void setup(){
  setupDisplay();
  brightness = 0;
}

void loop(){
  int e1 = random() % N_EYES;
  int e2 = random() % N_EYES;
  int m = random() % N_MOUTH;
  int t1 = random() % 600;
  int t2 = random() % 600;
  setDigit(0, eyes[e1]);
  setDigit(3, eyes[e2]);
  delay(t1);
  setDigit(1, mouths[m][0]);
  setDigit(2, mouths[m][1]);
  delay(t2);
}
