//------------------------LED EFFECT FUNCTIONS------------------------

void rainbow_fade() {                         //-m2-FADE ALL LEDS THROUGH HSV RAINBOW
  ihue++;
  if (ihue > 255) {
    ihue = 0;
  }
  for (int idex = 0 ; idex < LED_COUNT; idex++ ) {
    leds[idex] = CHSV(ihue, thissat, 255);
  }
  LEDS.show();
  delay(thisdelay);
}

void fade_out(byte time) {                         //-m2-FADE OUT within time ms
  
  for (int idex = 0 ; idex < LED_COUNT; idex++ ) {
    leds[idex] = CHSV(thishue, thissat, 255);
  }
  LEDS.show();
  delay(thisdelay);
}

void rainbow_loop() {                        //-m3-LOOP HSV RAINBOW
  idex++;
  ihue = ihue + thisstep;
  if (idex >= LED_COUNT) {
    idex = 0;
  }
  if (ihue > 255) {
    ihue = 0;
  }
  leds[idex] = CHSV(ihue, thissat, 255);
  LEDS.show();
  delay(thisdelay);
}

void random_burst() {                         //-m4-RANDOM INDEX/COLOR
  idex = random(0, LED_COUNT);
  ihue = random(0, 255);
  leds[idex] = CHSV(ihue, thissat, 255);
  LEDS.show();
  delay(thisdelay);
  leds[idex] = CHSV(0, 0, 0);
}

void color_bounce() {                        //-m5-BOUNCE COLOR (SINGLE LED)
  if (bouncedirection == 0) {
    idex = idex + 1;
    if (idex == LED_COUNT) {
      bouncedirection = 1;
      idex = idex - 1;
    }
  }
  if (bouncedirection == 1) {
    idex = idex - 1;
    if (idex == 0) {
      bouncedirection = 0;
    }
  }
  for (int i = 0; i < LED_COUNT; i++ ) {
    if (i == idex) {
      leds[i] = CHSV(thishue, thissat, 255);
    }
    else {
      leds[i] = CHSV(0, 0, 0);
    }
  }
  LEDS.show();
  delay(thisdelay);
}

//void russian_flag() {
//  int white[] = { 8,9,10,11,12,     35,36,37,38,39,  60,61,62,63,64,        86,87,88,89,90 };
//  int blue[] = { 5,6,7,13,14,15,  32,33,34,  40,41,  58,59,   65,66,   83,84,85,   91,92,93 };
//  int red[] = {};
//
//  for (int i = 0; i < (sizeof(white) / sizeof(white[0])); i++ ) {
//    setPixel(white[i], 255, 255, 255);
//  }
//  for (int i = 0; i < (sizeof(blue) / sizeof(blue[0])); i++ ) {
//    setPixel(blue[i], 0, 0, 255);
//  }
//  LEDS.show();
//}

void color_bounceFADE() {                    //-m6-BOUNCE COLOR (SIMPLE MULTI-LED FADE)
  if (bouncedirection == 0) {
    idex = idex + 1;
    thishue = thishue + 3;
    if (idex == LED_COUNT) {
      bouncedirection = 1;
      idex = idex - 1;
      thishue = thishue - 3;
    }
  }
  if (bouncedirection == 1) {
    idex = idex - 1;
    thishue = thishue - 3;
    if (idex == 0) {
      bouncedirection = 0;
    }
  }
  int iL1 = adjacent_cw(idex);
  int iL2 = adjacent_cw(iL1);
  int iL3 = adjacent_cw(iL2);
  int iL4 = adjacent_cw(iL3);
  int iL5 = adjacent_cw(iL4);
  int iL6 = adjacent_cw(iL5);
  int iL7 = adjacent_cw(iL6);
  int iL8 = adjacent_cw(iL7);
  int iL9 = adjacent_cw(iL8);
  int iL10 = adjacent_cw(iL9);

  int iR1 = adjacent_ccw(idex);
  int iR2 = adjacent_ccw(iR1);
  int iR3 = adjacent_ccw(iR2);
  int iR4 = adjacent_ccw(iR3);
  int iR5 = adjacent_ccw(iR4);
  int iR6 = adjacent_ccw(iR5);
  int iR7 = adjacent_ccw(iR6);
  int iR8 = adjacent_ccw(iR7);
  int iR9 = adjacent_ccw(iR8);
  int iR10 = adjacent_ccw(iR9);

  for (int i = 0; i < LED_COUNT; i++ ) {
    if (i == idex) {
      leds[i] = CHSV(thishue, thissat, 255);
    }
    else if (i == iL1) {
      leds[i] = CHSV(thishue, thissat, 230);
    }
    else if (i == iL2) {
      leds[i] = CHSV(thishue, thissat, 205);
    }
    else if (i == iL3) {
      leds[i] = CHSV(thishue, thissat, 180);
    }
    else if (i == iL4) {
      leds[i] = CHSV(thishue, thissat, 155);
    }
    else if (i == iL5) {
      leds[i] = CHSV(thishue, thissat, 130);
    }
    else if (i == iL6) {
      leds[i] = CHSV(thishue, thissat, 105);
    }
    else if (i == iL7) {
      leds[i] = CHSV(thishue, thissat, 80);
    }
    else if (i == iL8) {
      leds[i] = CHSV(thishue, thissat, 55);
    }
    else if (i == iL9) {
      leds[i] = CHSV(thishue, thissat, 30);
    }
    else if (i == iL10) {
      leds[i] = CHSV(thishue, thissat, 15);
    }

    else if (i == iR1) {
      leds[i] = CHSV(thishue, thissat, 230);
    }
    else if (i == iR2) {
      leds[i] = CHSV(thishue, thissat, 205);
    }
    else if (i == iR3) {
      leds[i] = CHSV(thishue, thissat, 180);
    }
    else if (i == iR4) {
      leds[i] = CHSV(thishue, thissat, 155);
    }
    else if (i == iR5) {
      leds[i] = CHSV(thishue, thissat, 130);
    }
    else if (i == iR6) {
      leds[i] = CHSV(thishue, thissat, 105);
    }
    else if (i == iR7) {
      leds[i] = CHSV(thishue, thissat, 80);
    }
    else if (i == iR8) {
      leds[i] = CHSV(thishue, thissat, 55);
    }
    else if (i == iR9) {
      leds[i] = CHSV(thishue, thissat, 30);
    }
    else if (i == iR10) {
      leds[i] = CHSV(thishue, thissat, 15);
    }
    else {
      leds[i] = CHSV(0, 0, 0);
    }
  }
  LEDS.show();
  delay(thisdelay);
}

void ems_lightsONE() {                    //-m7-EMERGENCY LIGHTS (TWO COLOR SINGLE LED)
  idex++;
  if (idex >= LED_COUNT) {
    idex = 0;
  }
  int idexR = idex;
  int idexB = antipodal_index(idexR);
  int thathue = (thishue + 160) % 255;
  for (int i = 0; i < LED_COUNT; i++ ) {
    if (i == idexR) {
      leds[i] = CHSV(thishue, thissat, 255);
    }
    else if (i == idexB) {
      leds[i] = CHSV(thathue, thissat, 255);
    }
    else {
      leds[i] = CHSV(0, 0, 0);
    }
  }
  LEDS.show();
  delay(thisdelay);
}

void ems_lightsALL() {                  //-m8-EMERGENCY LIGHTS (TWO COLOR SOLID)
  idex++;
  if (idex >= LED_COUNT) {
    idex = 0;
  }
  int idexR = idex;
  int idexB = antipodal_index(idexR);
  int thathue = (thishue + 160) % 255;
  leds[idexR] = CHSV(thishue, thissat, 255);
  leds[idexB] = CHSV(thathue, thissat, 255);
  LEDS.show();
  delay(thisdelay);
}

void flicker() {                          //-m9-FLICKER EFFECT
  int random_bright = random(0, 255);
  int random_delay = random(10, 100);
  int random_bool = random(0, random_bright);
  if (random_bool < 10) {
    for (int i = 0 ; i < LED_COUNT; i++ ) {
      leds[i] = CHSV(thishue, thissat, random_bright);
    }
    LEDS.show();
    delay(random_delay);
  }
}

void pulse_one_color_all() {              //-m10-PULSE BRIGHTNESS ON ALL LEDS TO ONE COLOR
  if (bouncedirection == 0) {
    ibright++;
    if (ibright >= 255) {
      bouncedirection = 1;
    }
  }
  if (bouncedirection == 1) {
    ibright = ibright - 1;
    if (ibright <= 1) {
      bouncedirection = 0;
    }
  }
  for (int idex = 0 ; idex < LED_COUNT; idex++ ) {
    leds[idex] = CHSV(thishue, thissat, ibright);
  }
  LEDS.show();
  delay(thisdelay);
}

void pulse_one_color_all_rev() {           //-m11-PULSE SATURATION ON ALL LEDS TO ONE COLOR
  if (bouncedirection == 0) {
    isat++;
    if (isat >= 255) {
      bouncedirection = 1;
    }
  }
  if (bouncedirection == 1) {
    isat = isat - 1;
    if (isat <= 1) {
      bouncedirection = 0;
    }
  }
  for (int idex = 0 ; idex < LED_COUNT; idex++ ) {
    leds[idex] = CHSV(thishue, isat, 255);
  }
  LEDS.show();
  delay(thisdelay);
}

void fade_vertical() {                    //-m12-FADE 'UP' THE LOOP
  idex++;
  if (idex > TOP_INDEX) {
    idex = 0;
  }
  int idexA = idex;
  int idexB = horizontal_index(idexA);
  ibright = ibright + 10;
  if (ibright > 255) {
    ibright = 0;
  }
  leds[idexA] = CHSV(thishue, thissat, ibright);
  leds[idexB] = CHSV(thishue, thissat, ibright);
  LEDS.show();
  delay(thisdelay);
}

void random_red() {                       //QUICK 'N DIRTY RANDOMIZE TO GET CELL AUTOMATA STARTED
  int temprand;
  for (int i = 0; i < LED_COUNT; i++ ) {
    temprand = random(0, 100);
    if (temprand > 50) {
      leds[i].r = 255;
    }
    if (temprand <= 50) {
      leds[i].r = 0;
    }
    leds[i].b = 0; leds[i].g = 0;
  }
  LEDS.show();
}

void rule30() {                          //-m13-1D CELLULAR AUTOMATA - RULE 30 (RED FOR NOW)
  if (bouncedirection == 0) {
    random_red();
    bouncedirection = 1;
  }
  copy_led_array();
  int iCW;
  int iCCW;
  int y = 100;
  for (int i = 0; i < LED_COUNT; i++ ) {
    iCW = adjacent_cw(i);
    iCCW = adjacent_ccw(i);
    if (ledsX[iCCW][0] > y && ledsX[i][0] > y && ledsX[iCW][0] > y) {
      leds[i].r = 0;
    }
    if (ledsX[iCCW][0] > y && ledsX[i][0] > y && ledsX[iCW][0] <= y) {
      leds[i].r = 0;
    }
    if (ledsX[iCCW][0] > y && ledsX[i][0] <= y && ledsX[iCW][0] > y) {
      leds[i].r = 0;
    }
    if (ledsX[iCCW][0] > y && ledsX[i][0] <= y && ledsX[iCW][0] <= y) {
      leds[i].r = 255;
    }
    if (ledsX[iCCW][0] <= y && ledsX[i][0] > y && ledsX[iCW][0] > y) {
      leds[i].r = 255;
    }
    if (ledsX[iCCW][0] <= y && ledsX[i][0] > y && ledsX[iCW][0] <= y) {
      leds[i].r = 255;
    }
    if (ledsX[iCCW][0] <= y && ledsX[i][0] <= y && ledsX[iCW][0] > y) {
      leds[i].r = 255;
    }
    if (ledsX[iCCW][0] <= y && ledsX[i][0] <= y && ledsX[iCW][0] <= y) {
      leds[i].r = 0;
    }
  }
  LEDS.show();
  delay(thisdelay);
}

void random_march() {                   //-m14-RANDOM MARCH CCW
  copy_led_array();
  int iCCW;
  leds[0] = CHSV(random(0, 255), 255, 255);
  for (int idex = 1; idex < LED_COUNT ; idex++ ) {
    iCCW = adjacent_ccw(idex);
    leds[idex].r = ledsX[iCCW][0];
    leds[idex].g = ledsX[iCCW][1];
    leds[idex].b = ledsX[iCCW][2];
  }
  LEDS.show();
  delay(thisdelay);
}

//void rwb_march() {                    //-m15-R,W,B MARCH CCW
//  copy_led_array();
//  int iCCW;
//  idex++;
//  if (idex > 8) {
//    idex = 0;
//  }
//  switch (idex) {
//    case 0:
//      leds[0].r = 255;
//      leds[0].g = 0;
//      leds[0].b = 0;
//      break;
//    case 1:
//      leds[0].r = 255;
//      leds[0].g = 0;
//      leds[0].b = 0;
//      break;
//    case 2:
//      leds[0].r = 255;
//      leds[0].g = 0;
//      leds[0].b = 0;
//      break;
//    case 3:
//      leds[0].r = 255;
//      leds[0].g = 255;
//      leds[0].b = 255;
//      break;
//    case 4:
//      leds[0].r = 255;
//      leds[0].g = 255;
//      leds[0].b = 255;
//      break;
//    case 5:
//      leds[0].r = 255;
//      leds[0].g = 255;
//      leds[0].b = 255;
//      break;
//    case 6:
//      leds[0].r = 0;
//      leds[0].g = 0;
//      leds[0].b = 255;
//      break;
//    case 7:
//      leds[0].r = 0;
//      leds[0].g = 0;
//      leds[0].b = 255;
//      break;
//    case 8:
//      leds[0].r = 0;
//      leds[0].g = 0;
//      leds[0].b = 255;
//      break;
//  }
//  for (int i = 1; i < LED_COUNT; i++ ) {
//    iCCW = adjacent_ccw(i);
//    leds[i].r = ledsX[iCCW][0];
//    leds[i].g = ledsX[iCCW][1];
//    leds[i].b = ledsX[iCCW][2];
//  }
//  LEDS.show();
//  delay(thisdelay);
//}

void radiation() {                   //-m16-SORT OF RADIATION SYMBOLISH-
  int N3  = int(LED_COUNT / 3);
  int N6  = int(LED_COUNT / 6);
  int N12 = int(LED_COUNT / 12);
  for (int i = 0; i < N6; i++ ) {    //-HACKY, I KNOW...
    tcount = tcount + .02;
    if (tcount > 3.14) {
      tcount = 0.0;
    }
    ibright = int(sin(tcount) * 255);
    int j0 = (i + LED_COUNT - N12) % LED_COUNT;
    int j1 = (j0 + N3) % LED_COUNT;
    int j2 = (j1 + N3) % LED_COUNT;
    leds[j0] = CHSV(thishue, thissat, ibright);
    leds[j1] = CHSV(thishue, thissat, ibright);
    leds[j2] = CHSV(thishue, thissat, ibright);
  }
  LEDS.show();
  delay(thisdelay);
}

void color_loop_vardelay() {                    //-m17-COLOR LOOP (SINGLE LED) w/ VARIABLE DELAY
  idex++;
  if (idex > LED_COUNT) {
    idex = 0;
  }
  int di = abs(TOP_INDEX - idex);
  int t = constrain((10 / di) * 10, 10, 500);
  for (int i = 0; i < LED_COUNT; i++ ) {
    if (i == idex) {
      leds[i] = CHSV(0, thissat, 255);
    }
    else {
      leds[i].r = 0; leds[i].g = 0; leds[i].b = 0;
    }
  }
  LEDS.show();
  delay(t);
}

void white_temps() {                            //-m18-SHOW A SAMPLE OF BLACK BODY RADIATION COLOR TEMPERATURES
  int N9 = int(LED_COUNT / 9);
  for (int i = 0; i < LED_COUNT; i++ ) {
    if (i >= 0 && i < N9) {
      leds[i].r = 255;  //-CANDLE - 1900
      leds[i].g = 147;
      leds[i].b = 41;
    }
    if (i >= N9 && i < N9 * 2) {
      leds[i].r = 255;  //-40W TUNG - 2600
      leds[i].g = 197;
      leds[i].b = 143;
    }
    if (i >= N9 * 2 && i < N9 * 3) {
      leds[i].r = 255;  //-100W TUNG - 2850
      leds[i].g = 214;
      leds[i].b = 170;
    }
    if (i >= N9 * 3 && i < N9 * 4) {
      leds[i].r = 255;  //-HALOGEN - 3200
      leds[i].g = 241;
      leds[i].b = 224;
    }
    if (i >= N9 * 4 && i < N9 * 5) {
      leds[i].r = 255;  //-CARBON ARC - 5200
      leds[i].g = 250;
      leds[i].b = 244;
    }
    if (i >= N9 * 5 && i < N9 * 6) {
      leds[i].r = 255;  //-HIGH NOON SUN - 5400
      leds[i].g = 255;
      leds[i].b = 251;
    }
    if (i >= N9 * 6 && i < N9 * 7) {
      leds[i].r = 255;  //-DIRECT SUN - 6000
      leds[i].g = 255;
      leds[i].b = 255;
    }
    if (i >= N9 * 7 && i < N9 * 8) {
      leds[i].r = 201;  //-OVERCAST SKY - 7000
      leds[i].g = 226;
      leds[i].b = 255;
    }
    if (i >= N9 * 8 && i < LED_COUNT) {
      leds[i].r = 64;  //-CLEAR BLUE SKY - 20000
      leds[i].g = 156;
      leds[i].b = 255;
    }
  }
  LEDS.show();
  delay(100);
}

void sin_bright_wave() {        //-m19-BRIGHTNESS SINE WAVE
  for (int i = 0; i < LED_COUNT; i++ ) {
    tcount = tcount + .1;
    if (tcount > 3.14) {
      tcount = 0.0;
    }
    ibright = int(sin(tcount) * 255);
    leds[i] = CHSV(thishue, thissat, ibright);
    LEDS.show();
    delay(thisdelay);
  }
}

void pop_horizontal() {        //-m20-POP FROM LEFT TO RIGHT UP THE RING
  int ix;
  if (bouncedirection == 0) {
    bouncedirection = 1;
    ix = idex;
  }
  else if (bouncedirection == 1) {
    bouncedirection = 0;
    ix = horizontal_index(idex);
    idex++;
    if (idex > TOP_INDEX) {
      idex = 0;
    }
  }
  for (int i = 0; i < LED_COUNT; i++ ) {
    if (i == ix) {
      leds[i] = CHSV(thishue, thissat, 255);
    }
    else {
      leds[i].r = 0; leds[i].g = 0; leds[i].b = 0;
    }
  }
  LEDS.show();
  delay(thisdelay);
}

void quad_bright_curve() {      //-m21-QUADRATIC BRIGHTNESS CURVER
  int ax;
  for (int x = 0; x < LED_COUNT; x++ ) {
    if (x <= TOP_INDEX) {
      ax = x;
    }
    else if (x > TOP_INDEX) {
      ax = LED_COUNT - x;
    }
    int a = 1; int b = 1; int c = 0;
    int iquad = -(ax * ax * a) + (ax * b) + c; //-ax2+bx+c
    int hquad = -(TOP_INDEX * TOP_INDEX * a) + (TOP_INDEX * b) + c;
    ibright = int((float(iquad) / float(hquad)) * 255);
    leds[x] = CHSV(thishue, thissat, ibright);
  }
  LEDS.show();
  delay(thisdelay);
}

void flame() {                                    //-m22-FLAMEISH EFFECT
  int idelay = random(0, 35);
  float hmin = 0.1; float hmax = 45.0;
  float hdif = hmax - hmin;
  int randtemp = random(0, 3);
  float hinc = (hdif / float(TOP_INDEX)) + randtemp;
  int ihue = hmin;
  for (int i = 0; i <= TOP_INDEX; i++ ) {
    ihue = ihue + hinc;
    leds[i] = CHSV(ihue, thissat, 255);
    int ih = horizontal_index(i);
    leds[ih] = CHSV(ihue, thissat, 255);
    leds[TOP_INDEX].r = 255; leds[TOP_INDEX].g = 255; leds[TOP_INDEX].b = 255;
    LEDS.show();
    delay(idelay);
  }
}

void rainbow_vertical() {                        //-m23-RAINBOW 'UP' THE LOOP
  idex++;
  if (idex > TOP_INDEX) {
    idex = 0;
  }
  ihue = ihue + thisstep;
  if (ihue > 255) {
    ihue = 0;
  }
  int idexA = idex;
  int idexB = horizontal_index(idexA);
  leds[idexA] = CHSV(ihue, thissat, 255);
  leds[idexB] = CHSV(ihue, thissat, 255);
  LEDS.show();
  delay(thisdelay);
}

void pacman() {                                  //-m24-REALLY TERRIBLE PACMAN CHOMPING EFFECT
  int s = int(LED_COUNT / 4);
  lcount++;
  if (lcount > 5) {
    lcount = 0;
  }
  if (lcount == 0) {
    for (int i = 0 ; i < LED_COUNT; i++ ) {
      set_color_led(i, 255, 255, 0);
    }
  }
  if (lcount == 1 || lcount == 5) {
    for (int i = 0 ; i < LED_COUNT; i++ ) {
      set_color_led(i, 255, 255, 0);
    }
    leds[s].r = 0; leds[s].g = 0; leds[s].b = 0;
  }
  if (lcount == 2 || lcount == 4) {
    for (int i = 0 ; i < LED_COUNT; i++ ) {
      set_color_led(i, 255, 255, 0);
    }
    leds[s - 1].r = 0; leds[s - 1].g = 0; leds[s - 1].b = 0;
    leds[s].r = 0; leds[s].g = 0; leds[s].b = 0;
    leds[s + 1].r = 0; leds[s + 1].g = 0; leds[s + 1].b = 0;
  }
  if (lcount == 3) {
    for (int i = 0 ; i < LED_COUNT; i++ ) {
      set_color_led(i, 255, 255, 0);
    }
    leds[s - 2].r = 0; leds[s - 2].g = 0; leds[s - 2].b = 0;
    leds[s - 1].r = 0; leds[s - 1].g = 0; leds[s - 1].b = 0;
    leds[s].r = 0; leds[s].g = 0; leds[s].b = 0;
    leds[s + 1].r = 0; leds[s + 1].g = 0; leds[s + 1].b = 0;
    leds[s + 2].r = 0; leds[s + 2].g = 0; leds[s + 2].b = 0;
  }
  LEDS.show();
  delay(thisdelay);
}

void random_color_pop() {                         //-m25-RANDOM COLOR POP
  idex = random(0, LED_COUNT);
  ihue = random(0, 255);
  one_color_all(0, 0, 0);
  leds[idex] = CHSV(ihue, thissat, 255);
  LEDS.show();
  delay(thisdelay);
}

void ems_lightsSTROBE() {                  //-m26-EMERGENCY LIGHTS (STROBE LEFT/RIGHT)
  int thishue = 0;
  int thathue = (thishue + 160) % 255;
  for (int x = 0 ; x < 5; x++ ) {
    for (int i = 0 ; i < TOP_INDEX; i++ ) {
      leds[i] = CHSV(thishue, thissat, 255);
    }
    LEDS.show(); delay(thisdelay);
    one_color_all(0, 0, 0);
    LEDS.show(); delay(thisdelay);
  }
  for (int x = 0 ; x < 5; x++ ) {
    for (int i = TOP_INDEX ; i < LED_COUNT; i++ ) {
      leds[i] = CHSV(thathue, thissat, 255);
    }
    LEDS.show(); delay(thisdelay);
    one_color_all(0, 0, 0);
    LEDS.show(); delay(thisdelay);
  }
}

void rgb_propeller() {                           //-m27-RGB PROPELLER
  idex++;
  int ghue = (thishue + 80) % 255;
  int bhue = (thishue + 160) % 255;
  int N3  = int(LED_COUNT / 3);
  int N6  = int(LED_COUNT / 6);
  int N12 = int(LED_COUNT / 12);
  for (int i = 0; i < N3; i++ ) {
    int j0 = (idex + i + LED_COUNT - N12) % LED_COUNT;
    int j1 = (j0 + N3) % LED_COUNT;
    int j2 = (j1 + N3) % LED_COUNT;
    leds[j0] = CHSV(thishue, thissat, 255);
    leds[j1] = CHSV(ghue, thissat, 255);
    leds[j2] = CHSV(bhue, thissat, 255);
  }
  LEDS.show();
  delay(thisdelay);
}

void kitt() {                                     //-m28-KNIGHT INDUSTIES 2000
  int rand = random(0, TOP_INDEX);
  for (int i = 0; i < rand; i++ ) {
    leds[TOP_INDEX + i] = CHSV(thishue, thissat, 255);
    leds[TOP_INDEX - i] = CHSV(thishue, thissat, 255);
    LEDS.show();
    delay(thisdelay / rand);
  }
  for (int i = rand; i > 0; i-- ) {
    leds[TOP_INDEX + i] = CHSV(thishue, thissat, 0);
    leds[TOP_INDEX - i] = CHSV(thishue, thissat, 0);
    LEDS.show();
    delay(thisdelay / rand);
  }
}

void matrix() {                                   //-m29-ONE LINE MATRIX
  int rand = random(0, 100);
  if (rand > 90) {
    leds[0] = CHSV(thishue, thissat, 255);
  }
  else {
    leds[0] = CHSV(thishue, thissat, 0);
  }
  copy_led_array();
  for (int i = 1; i < LED_COUNT; i++ ) {
    leds[i].r = ledsX[i - 1][0];
    leds[i].g = ledsX[i - 1][1];
    leds[i].b = ledsX[i - 1][2];
  }
  LEDS.show();
  delay(thisdelay);
}

void strip_march_cw() {                        //-m50-MARCH STRIP CW
  copy_led_array();
  int iCW;
  for (int i = 0; i < LED_COUNT; i++ ) {
    iCW = adjacent_cw(i);
    leds[i].r = ledsX[iCW][0];
    leds[i].g = ledsX[iCW][1];
    leds[i].b = ledsX[iCW][2];
  }
  LEDS.show();
  delay(thisdelay);
}

void strip_march_ccw() {                        //-m51-MARCH STRIP CCW
  copy_led_array();
  int iCCW;
  for (int i = 0; i < LED_COUNT; i++ ) {
    iCCW = adjacent_ccw(i);
    leds[i].r = ledsX[iCCW][0];
    leds[i].g = ledsX[iCCW][1];
    leds[i].b = ledsX[iCCW][2];
  }
  LEDS.show();
  delay(thisdelay);
}

void new_rainbow_loop() {                      //-m88-RAINBOW FADE FROM FAST_SPI2
  ihue -= 1;
  fill_rainbow( leds, LED_COUNT, ihue );
  LEDS.show();
  delay(thisdelay);
}

//void demo_modeA() {
//  int r = 100;
//  thisdelay = 20; thisstep = 10; thishue = 0; thissat = 255;
//  for (int i = 0; i < r * 20; i++) {
//    random_burst();
//  }
//  
//  for (int i = 0; i < r * 12; i++) {
//    color_bounce();
//  }
//  
//  thisdelay = 40;
//  for (int i = 0; i < r * 12; i++) {
//    color_bounceFADE();
//  }
//  
//  for (int i = 0; i < r * 6; i++) {
//    ems_lightsONE();
//  }
//
//  one_color_all(0, 0, 0); LEDS.show();
//  
//  thisdelay = 60; thishue = 180;
//  for (int i = 0; i < r * 5; i++) {
//    fade_vertical();
//  }
//  random_red();
//  thisdelay = 100;
//  for (int i = 0; i < r * 5; i++) {
//    rule30();
//  }
//  thisdelay = 40;
//  for (int i = 0; i < r * 8; i++) {
//    random_march();
//  }
//  thisdelay = 80;
//  for (int i = 0; i < r * 5; i++) {
//    rwb_march();
//  }
//  one_color_all(0, 0, 0); ; LEDS.show();
//  /*thisdelay = 60; thishue = 95;
//  for (int i = 0; i < r * 15; i++) {
//    radiation();
//  }
//  /**/
//  for (int i = 0; i < r * 15; i++) {
//    color_loop_vardelay();
//  }
//  
//  thisdelay = 100; thishue = 0;
//  for (int i = 0; i < r * 5; i++) {
//    pop_horizontal();
//  }
//  
//  thisdelay = 100; thishue = 180;
//  for (int i = 0; i < r * 4; i++) {
//    quad_bright_curve();
//  }
//  one_color_all(0, 0, 0); LEDS.show();
//  for (int i = 0; i < r * 3; i++) {
//    flame();
//  }
//  thisdelay = 50; thisstep = 15;
//  for (int i = 0; i < r * 12; i++) {
//    rainbow_vertical();
//  }
//  thisdelay = 100;
//  for (int i = 0; i < r * 3; i++) {
//    strip_march_ccw();
//  }
//  for (int i = 0; i < r * 3; i++) {
//    strip_march_cw();
//  }
//  
//  demo_modeB();
//  thisdelay = 5;
//  for (int i = 0; i < r * 120; i++) {
//    new_rainbow_loop();
//  }
//}

//void demo_modeB() {
//  int r = 10;
//  one_color_all(0, 0, 0); LEDS.show();
//  thisdelay = 35;
//  for (int i = 0; i < r * 10; i++) {
//    random_color_pop();
//  }
//  thisdelay = 50;
//  for (int i = 0; i < r * 10; i++) {
//    rgb_propeller();
//  }
//  one_color_all(0, 0, 0); LEDS.show();
//  thisdelay = 100; thishue = 0;
//  for (int i = 0; i < r * 3; i++) {
//    kitt();
//  }
//  one_color_all(0, 0, 0); LEDS.show();
//  thisdelay = 30; thishue = 95;
//  for (int i = 0; i < r * 25; i++) {
//    matrix();
//  }
//  one_color_all(0, 0, 0); LEDS.show();
//}

//-----------------------------?????????????? ???????????????????? ????????????-----------------------------------------
void colorWipe(byte red, byte green, byte blue, int SpeedDelay) {
  for (uint16_t i = 0; i < LED_COUNT; i++) {
    setPixel(i, red, green, blue);
    FastLED.show();
    delay(SpeedDelay);
  }
}
//-----------------------------------???????????????? ????????????????????-----------------------------------
void CylonBounce(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {

  for (int i = 0; i < LED_COUNT - EyeSize - 2; i++) {
    setAll(0, 0, 0);
    setPixel(i, red / 10, green / 10, blue / 10);
    for (int j = 1; j <= EyeSize; j++) {
      setPixel(i + j, red, green, blue);
    }
    setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);
    FastLED.show();
    delay(SpeedDelay);
  }

  delay(ReturnDelay);

  for (int i = LED_COUNT - EyeSize - 2; i > 0; i--) {
    setAll(0, 0, 0);
    setPixel(i, red / 10, green / 10, blue / 10);
    for (int j = 1; j <= EyeSize; j++) {
      setPixel(i + j, red, green, blue);
    }
    setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);
    FastLED.show();
    delay(SpeedDelay);
  }

  delay(ReturnDelay);
}

//---------------------------------???????????????? ??????????-------------------------------------
void Fire(int Cooling, int Sparking, int SpeedDelay) {
  static byte heat[LED_COUNT];
  int cooldown;

  // Step 1.  Cool down every cell a little
  for ( int i = 0; i < LED_COUNT; i++) {
    cooldown = random(0, ((Cooling * 10) / LED_COUNT) + 2);

    if (cooldown > heat[i]) {
      heat[i] = 0;
    } else {
      heat[i] = heat[i] - cooldown;
    }
  }

  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for ( int k = LED_COUNT - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' near the bottom
  if ( random(255) < Sparking ) {
    int y = random(7);
    heat[y] = heat[y] + random(160, 255);
    //heat[y] = random(160,255);
  }

  // Step 4.  Convert heat to LED colors
  for ( int j = 0; j < LED_COUNT; j++) {
    setPixelHeatColor(j, heat[j] );
  }

  FastLED.show();
  delay(SpeedDelay);
}

void setPixelHeatColor (int Pixel, byte temperature) {
  // Scale 'heat' down from 0-255 to 0-191
  byte t192 = round((temperature / 255.0) * 191);

  // calculate ramp up from
  byte heatramp = t192 & 0x3F; // 0..63
  heatramp <<= 2; // scale up to 0..252

  // figure out which third of the spectrum we're in:
  if ( t192 > 0x80) {                    // hottest
    setPixel(Pixel, 255, 255, heatramp);
  } else if ( t192 > 0x40 ) {            // middle
    setPixel(Pixel, 255, heatramp, 0);
  } else {                               // coolest
    setPixel(Pixel, heatramp, 0, 0);
  }
}

//-------------------------------newKITT---------------------------------------
void NewKITT(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {
  RightToLeft(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  LeftToRight(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  OutsideToCenter(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  CenterToOutside(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  LeftToRight(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  RightToLeft(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  OutsideToCenter(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  CenterToOutside(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
}

void CenterToOutside(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {
  for (int i = ((LED_COUNT - EyeSize) / 2); i >= 0; i--) {
    setAll(0, 0, 0);

    setPixel(i, red / 10, green / 10, blue / 10);
    for (int j = 1; j <= EyeSize; j++) {
      setPixel(i + j, red, green, blue);
    }
    setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);

    setPixel(LED_COUNT - i, red / 10, green / 10, blue / 10);
    for (int j = 1; j <= EyeSize; j++) {
      setPixel(LED_COUNT - i - j, red, green, blue);
    }
    setPixel(LED_COUNT - i - EyeSize - 1, red / 10, green / 10, blue / 10);

    FastLED.show();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}

void OutsideToCenter(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {
  for (int i = 0; i <= ((LED_COUNT - EyeSize) / 2); i++) {
    setAll(0, 0, 0);

    setPixel(i, red / 10, green / 10, blue / 10);
    for (int j = 1; j <= EyeSize; j++) {
      setPixel(i + j, red, green, blue);
    }
    setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);

    setPixel(LED_COUNT - i, red / 10, green / 10, blue / 10);
    for (int j = 1; j <= EyeSize; j++) {
      setPixel(LED_COUNT - i - j, red, green, blue);
    }
    setPixel(LED_COUNT - i - EyeSize - 1, red / 10, green / 10, blue / 10);

    FastLED.show();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}

void LeftToRight(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {
  for (int i = 0; i < LED_COUNT - EyeSize - 2; i++) {
    setAll(0, 0, 0);
    setPixel(i, red / 10, green / 10, blue / 10);
    for (int j = 1; j <= EyeSize; j++) {
      setPixel(i + j, red, green, blue);
    }
    setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);
    FastLED.show();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}

void RightToLeft(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {
  for (int i = LED_COUNT - EyeSize - 2; i > 0; i--) {
    setAll(0, 0, 0);
    setPixel(i, red / 10, green / 10, blue / 10);
    for (int j = 1; j <= EyeSize; j++) {
      setPixel(i + j, red, green, blue);
    }
    setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);
    FastLED.show();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}

//-------------------------------newKITT---------------------------------------
void rainbowCycle(int SpeedDelay) {
  byte *c;
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < LED_COUNT; i++) {
      c = Wheel(((i * 256 / LED_COUNT) + j) & 255);
      setPixel(i, *c, *(c + 1), *(c + 2));
    }
    FastLED.show();
    delay(SpeedDelay);
  }
}

byte * Wheel(byte WheelPos) {
  static byte c[3];

  if (WheelPos < 85) {
    c[0] = WheelPos * 3;
    c[1] = 255 - WheelPos * 3;
    c[2] = 0;
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    c[0] = 255 - WheelPos * 3;
    c[1] = 0;
    c[2] = WheelPos * 3;
  } else {
    WheelPos -= 170;
    c[0] = 0;
    c[1] = WheelPos * 3;
    c[2] = 255 - WheelPos * 3;
  }

  return c;
}

//-------------------------------TwinkleRandom---------------------------------------
void TwinkleRandom(int Count, int SpeedDelay, boolean OnlyOne) {
  setAll(0, 0, 0);

  for (int i = 0; i < Count; i++) {
    setPixel(random(LED_COUNT), random(0, 255), random(0, 255), random(0, 255));
    FastLED.show();
    delay(SpeedDelay);
    if (OnlyOne) {
      setAll(0, 0, 0);
    }
  }

  delay(SpeedDelay);
}

//-------------------------------RunningLights---------------------------------------
void RunningLights(byte red, byte green, byte blue, int WaveDelay) {
  int Position = 0;

  for (int i = 0; i < LED_COUNT * 2; i++)
  {
    Position++; // = 0; //Position + Rate;
    for (int i = 0; i < LED_COUNT; i++) {
      // sine wave, 3 offset waves make a rainbow!
      //float level = sin(i+Position) * 127 + 128;
      //setPixel(i,level,0,0);
      //float level = sin(i+Position) * 127 + 128;
      setPixel(i, ((sin(i + Position) * 127 + 128) / 255)*red,
               ((sin(i + Position) * 127 + 128) / 255)*green,
               ((sin(i + Position) * 127 + 128) / 255)*blue);
    }

    FastLED.show();
    delay(WaveDelay);
  }
}

//-------------------------------Sparkle---------------------------------------
void Sparkle(byte red, byte green, byte blue, int SpeedDelay) {
  int Pixel = random(LED_COUNT);
  setPixel(Pixel, red, green, blue);
  FastLED.show();
  delay(SpeedDelay);
  setPixel(Pixel, 0, 0, 0);
}

//------------------------------- Pyramid1 -------------------------------------
void Pyramid1(int SpeedDelay, byte red, byte green, byte blue) {
  for (byte l = 0; l < PYRAMID_LEVELS_COUNT; l++) {
    for (int Pixel = PYRAMID_LEVELS[l][0]; Pixel < PYRAMID_LEVELS[l][1]; Pixel++) {
        setPixel(Pixel, red, green, blue);
    }
    FastLED.show();
    delay(SpeedDelay);
    // setAll(0,0,0);
  }

  delay(5*SpeedDelay);
  for (byte l = PYRAMID_LEVELS_COUNT; l > 0; l--) {
    for (int Pixel = PYRAMID_LEVELS[l][0]; Pixel < PYRAMID_LEVELS[l][1]; Pixel++) {
        setPixel(Pixel, 0, 0, 0);
    }
    FastLED.show();
    delay(SpeedDelay);
  }
  setAll(0,0,0);
  delay(5*SpeedDelay);
}
//------------------------------- Pyramid2 -------------------------------------
void Pyramid2(int SpeedDelay, byte red, byte green, byte blue) {      // line by line from the top to the bottom
  #define STEPS 10

  // fade in 1 line
  for (byte l = 0; l <= PYRAMID_LEVELS_COUNT; l++) {
    for (byte step = 1; step <= STEPS; step++) {
      for (int Pixel = PYRAMID_LEVELS[PYRAMID_LEVELS_COUNT-l][0]; Pixel < PYRAMID_LEVELS[PYRAMID_LEVELS_COUNT-l][1]; Pixel++) {
        setPixel(Pixel, (red/STEPS)*(step),(green/STEPS)*(step), (blue/STEPS)*(step));
      }
      FastLED.show();
      delay(SpeedDelay);
    }
    delay(SpeedDelay);    // between lines
  }
  
  // fade out 1 line
  for (byte l = 0; l <= PYRAMID_LEVELS_COUNT; l++) {
    for (byte step = 1; step <= STEPS; step++) {
      for (int Pixel = PYRAMID_LEVELS[PYRAMID_LEVELS_COUNT-l][0]; Pixel < PYRAMID_LEVELS[PYRAMID_LEVELS_COUNT-l][1]; Pixel++) {
        setPixel(Pixel, red - (red/STEPS)*(step), green - (green/STEPS)*(step), blue - (blue/STEPS)*(step));
      }
      FastLED.show();
      delay(SpeedDelay);
    }
    delay(SpeedDelay);    // between lines
  }
  delay(5 * SpeedDelay);
}

//------------------------------- Pyramid3 -------------------------------------
void Pyramid3(int SpeedDelay, byte red, byte green, byte blue) {
  #define STEPS 10

  // fade in 1 line
  for (byte l = 0; l < PYRAMID_LEVELS_COUNT; l++) {
    for (byte step = 0; step < STEPS; step++) {
      for (int Pixel = PYRAMID_LEVELS[l][0]; Pixel < PYRAMID_LEVELS[l][1]; Pixel++) {
        setPixel(Pixel, (red/STEPS)*(step), (green/STEPS)*(step), (blue/STEPS)*(step));
      }
      FastLED.show();
      delay(SpeedDelay);
    }
    delay(SpeedDelay);  // between lines
  }
  
//  delay(2 * SpeedDelay);    // between fade in/out

  // fade out 1 line
  for (byte l = 0; l <= PYRAMID_LEVELS_COUNT; l++) {
    for (byte step = 1; step <= STEPS; step++) {
      for (int Pixel = PYRAMID_LEVELS[PYRAMID_LEVELS_COUNT-l][0]; Pixel < PYRAMID_LEVELS[PYRAMID_LEVELS_COUNT-l][1]; Pixel++) {
        setPixel(Pixel, red - (red/STEPS)*(step), green - (green/STEPS)*(step), blue - (blue/STEPS)*(step));
      }
      FastLED.show();
      delay(SpeedDelay);
    }
    delay(SpeedDelay);    // between lines
  }
  delay(3 * SpeedDelay);
}
//-------------------------------SnowSparkle---------------------------------------
void SnowSparkle(byte red, byte green, byte blue, int SparkleDelay, int SpeedDelay) {
  setAll(red, green, blue);

  int Pixel = random(LED_COUNT);
  setPixel(Pixel, 0xff, 0xff, 0xff);
  FastLED.show();
  delay(SparkleDelay);
  setPixel(Pixel, red, green, blue);
  FastLED.show();
  delay(SpeedDelay);
}

//-------------------------------theaterChase---------------------------------------
void theaterChase(byte red, byte green, byte blue, int SpeedDelay) {
  for (int j = 0; j < 10; j++) { //do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < LED_COUNT; i = i + 3) {
        setPixel(i + q, red, green, blue);  //turn every third pixel on
      }
      FastLED.show();
      delay(SpeedDelay);
      for (int i = 0; i < LED_COUNT; i = i + 3) {
        setPixel(i + q, 0, 0, 0);    //turn every third pixel off
      }
    }
  }
}

//-------------------------------theaterChaseRainbow---------------------------------------
void theaterChaseRainbow(int SpeedDelay) {
  byte *c;

  for (int j = 0; j < 256; j++) {   // cycle all 256 colors in the wheel
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < LED_COUNT; i = i + 3) {
        c = Wheel( (i + j) % 255);
        setPixel(i + q, *c, *(c + 1), *(c + 2)); //turn every third pixel on
      }
      FastLED.show();
      delay(SpeedDelay);
      for (int i = 0; i < LED_COUNT; i = i + 3) {
        setPixel(i + q, 0, 0, 0);    //turn every third pixel off
      }
    }
  }
}

//-------------------------------Strobe---------------------------------------
void Strobe(byte red, byte green, byte blue, int StrobeCount, int FlashDelay, int EndPause) {
  for (int j = 0; j < StrobeCount; j++) {
    setAll(red, green, blue);
    FastLED.show();
    delay(FlashDelay);
    setAll(0, 0, 0);
    FastLED.show();
    delay(FlashDelay);
  }

  delay(EndPause);
}



//-------------------------------BouncingBalls---------------------------------------
void BouncingBalls(byte red, byte green, byte blue, int BallCount) {
  float Gravity = -9.81;
  int StartHeight = 1;

  float Height[BallCount];
  float ImpactVelocityStart = sqrt( -2 * Gravity * StartHeight );
  float ImpactVelocity[BallCount];
  float TimeSinceLastBounce[BallCount];
  int   Position[BallCount];
  long  ClockTimeSinceLastBounce[BallCount];
  float Dampening[BallCount];

  for (int i = 0 ; i < BallCount ; i++) {
    ClockTimeSinceLastBounce[i] = millis();
    Height[i] = StartHeight;
    Position[i] = 0;
    ImpactVelocity[i] = ImpactVelocityStart;
    TimeSinceLastBounce[i] = 0;
    Dampening[i] = 0.90 - float(i) / pow(BallCount, 2);
  }

  while (true) {
    for (int i = 0 ; i < BallCount ; i++) {
      TimeSinceLastBounce[i] =  millis() - ClockTimeSinceLastBounce[i];
      Height[i] = 0.5 * Gravity * pow( TimeSinceLastBounce[i] / 1000 , 2.0 ) + ImpactVelocity[i] * TimeSinceLastBounce[i] / 1000;

      if ( Height[i] < 0 ) {
        Height[i] = 0;
        ImpactVelocity[i] = Dampening[i] * ImpactVelocity[i];
        ClockTimeSinceLastBounce[i] = millis();

        if ( ImpactVelocity[i] < 0.01 ) {
          ImpactVelocity[i] = ImpactVelocityStart;
        }
      }
      Position[i] = round( Height[i] * (LED_COUNT - 1) / StartHeight);
    }

    for (int i = 0 ; i < BallCount ; i++) {
      setPixel(Position[i], red, green, blue);
    }
    FastLED.show();
    setAll(0, 0, 0);
    delay(thisdelay);
  }
}

//-------------------------------BouncingColoredBalls---------------------------------------
void BouncingColoredBalls(int BallCount, byte colors[][3]) {
  float Gravity = -9.81;
  int StartHeight = 1;

  float Height[BallCount];
  float ImpactVelocityStart = sqrt( -2 * Gravity * StartHeight );
  float ImpactVelocity[BallCount];
  float TimeSinceLastBounce[BallCount];
  int   Position[BallCount];
  long  ClockTimeSinceLastBounce[BallCount];
  float Dampening[BallCount];

  for (int i = 0 ; i < BallCount ; i++) {
    ClockTimeSinceLastBounce[i] = millis();
    Height[i] = StartHeight;
    Position[i] = 0;
    ImpactVelocity[i] = ImpactVelocityStart;
    TimeSinceLastBounce[i] = 0;
    Dampening[i] = 0.90 - float(i) / pow(BallCount, 2);
  }

  while (true) {
    for (int i = 0 ; i < BallCount ; i++) {
      TimeSinceLastBounce[i] =  millis() - ClockTimeSinceLastBounce[i];
      Height[i] = 0.5 * Gravity * pow( TimeSinceLastBounce[i] / 1000 , 2.0 ) + ImpactVelocity[i] * TimeSinceLastBounce[i] / 1000;

      if ( Height[i] < 0 ) {
        Height[i] = 0;
        ImpactVelocity[i] = Dampening[i] * ImpactVelocity[i];
        ClockTimeSinceLastBounce[i] = millis();

        if ( ImpactVelocity[i] < 0.01 ) {
          ImpactVelocity[i] = ImpactVelocityStart;
        }
      }
      Position[i] = round( Height[i] * (LED_COUNT - 1) / StartHeight);
    }

    for (int i = 0 ; i < BallCount ; i++) {
      setPixel(Position[i], colors[i][0], colors[i][1], colors[i][2]);
    }
    FastLED.show();
    setAll(0, 0, 0);
  }
}
