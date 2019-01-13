#define N_EYES 4
#define N_MOUTH 4

uint8_t e1, e2, m, colorSpeed;
uint8_t body = 0;
uint16_t t1, t2;
long now1, now2, now3;

// Segment Eyes
uint8_t eyes[N_EYES] = {
  SEG_A+SEG_B+SEG_G+SEG_F,
  SEG_A+SEG_B+SEG_G+SEG_F,
  SEG_G,
  SEG_A};

// Segment mouths
uint8_t mouths[N_MOUTH][2] ={
  {SEG_D, SEG_D},
  {SEG_D+SEG_E+SEG_G, SEG_D+SEG_C+SEG_G},
  {SEG_E+SEG_D, SEG_C+SEG_D},
  {SEG_E+SEG_G, SEG_C+SEG_G}
};

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

// Dot Matrix images
uint64_t BODY[] = {0x734644f8f8444673, 0xc04047f8f84740c0};
uint64_t HEART[] = {0x00387c3e3e7c3800, 0x0038442222443800};
uint64_t HEART2[] = {0xffc783c1c183c7ff, 0xffc7bbddddbbc7ff};
uint64_t IMAGES[] = {0xffe7e78181e7e7ff, 0x980c0603060c1830, 0x010080c163361c08, 0x0c183060c0603019};
