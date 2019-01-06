#include "characters.h"
#include "devices.h"

uint8_t j, k = 0;
uint8_t brightness = 0;

void setDigit(int digit, int value){
  noInterrupts(); // stop interrupts in order to update value
  values[digit] = value;
  interrupts();
}

void setDisplay(int value[]){
  for (uint8_t i=0; i<N_DIGIT; i++){
    setDigit(i, value[i]);
  }
}

void setDisplayU(int v){
  for (uint8_t i=0; i<N_DIGIT; i++){
    setDigit(i, v);
  }
}

void setupDisplay(uint8_t b){
    // Setup Timer2 to update segment display
    noInterrupts();           // disable all interrupts
    TCCR2A = 0;
    TCCR2B = 0;
    TCNT2  = 0;
    OCR2A = 12;
    TCCR2B |= (1 << WGM22);   // CTC mode
    TCCR2B |= (1 << CS21);    // prescaler
    TIMSK2 |= (1 << OCIE2A);  // enable timer compare interrupt
    interrupts();             // enable all interrupts

    for(uint8_t i=0; i<N_SEG; i++){
      pinMode(segments[i], OUTPUT);
    }
    for(uint8_t i=0; i<N_DIGIT; i++){
      pinMode(digits[i], OUTPUT);
    }
    setDisplayU(0);
    brightness = b;

    pinMode(13, OUTPUT);
}

// Each time the timer interrupts, we update the next digit
ISR (TIMER2_COMPA_vect) {
  // turn of all segments before changing digit - this is to avoid bleed between digits
  if (N_DIGIT > 1){
    for(uint8_t i=0; i<N_SEG; i++){
      #ifdef COMMON_CATHODE
      digitalWrite(segments[i], 0);
      #else
      digitalWrite(segments[i], 1);
      #endif
    }
  }

  if(k == 0){
    // turn on target digit, turn off all others
    for(uint8_t i=0; i<N_DIGIT; i++){
      #ifdef COMMON_CATHODE
      digitalWrite(digits[i], j != i);
      #else
      digitalWrite(digits[i], j == i);
      #endif
    }

    // set segments
    for(uint8_t i=0; i<N_SEG; i++){
      #ifdef COMMON_CATHODE
      digitalWrite(segments[i], values[j] & (1 << i));
      #else
      digitalWrite(segments[i], (values[j] ^ 255) & (1 << i));
      #endif
    }

    // increment digit index
    j += 1;
    j %= N_DIGIT;

    if(j==0){
      k += 1;
      k %= brightness+1;
    }
  } else {
    k += 1;
    k %= brightness+1;
  }
}
