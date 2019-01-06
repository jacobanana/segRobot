/*
 * Adrien Fauconnet - 2018
 * Segment display experiments
 * ------
 * Display pinouts & configuration
 */

// 4 digit 7 segement + dot common cathode
#ifdef _3461AS_
#define COMMON_CATHODE
#define N_DIGIT 4
#define N_SEG 8

#define PIN_A 5
#define PIN_B 15
#define PIN_C 3
#define PIN_D 0
#define PIN_E 1
#define PIN_F 16
#define PIN_G 8
#define PIN_P 2
#define COM_1 4
#define COM_2 6
#define COM_3 7
#define COM_4 19
const uint8_t segments[] = {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_P};
const uint8_t digits[] = {COM_1, COM_2, COM_3, COM_4};
uint8_t values[] = {0, 0, 0, 0};

#endif

// 1 digit 7 segment + dot common anode
#ifdef _5011BS_
#define COMMON_ANODE
#define N_DIGIT 1
#define N_SEG 8

#define COM 17
#define PIN_A 16
#define PIN_B 8
#define PIN_C 0
#define PIN_D 3
#define PIN_E 4
#define PIN_F 5
#define PIN_G 15
#define PIN_P 1
const uint8_t segments[] = {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_P};
const uint8_t digits[] = {COM};
uint8_t values[] = {0};

#endif
