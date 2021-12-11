/*
  Скетч создан на основе FASTSPI2 EFFECTS EXAMPLES автора teldredge (www.funkboxing.com)
  А также вот этой статьи https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/#cylon
  Доработан, переведён и разбит на файлы 2017 AlexGyver
  Отправляем в монитор порта номер режима, он активируется
*/

#include "FastLED.h"          // библиотека для работы с лентой

#define LED_COUNT 170         // 170 - max number of leds for Arduino Nano v3
#define LED_DT 13             // пин, куда подключен DIN ленты

int max_bright = 200;
// максимальная яркость (0 - 255)
int ledMode = 1;
/*
  Стартовый режим
  0 - все выключены
  1 - все включены
  3 - кольцевая радуга
  888 - демо-режим
*/

// цвета мячиков для режима
//byte ballColors[3][3] = {
//  {0xff, 0, 0},
//  {0xff, 0xff, 0xff},
//  {0   , 0   , 0xff},
//};

// ---------------СЛУЖЕБНЫЕ ПЕРЕМЕННЫЕ-----------------
int BOTTOM_INDEX = 0;        // светодиод начала отсчёта
int TOP_INDEX = int(LED_COUNT / 2);
int EVENODD = LED_COUNT % 2;
struct CRGB leds[LED_COUNT];
int ledsX[LED_COUNT][3];     //-ARRAY FOR COPYING WHATS IN THE LED STRIP CURRENTLY (FOR CELL-AUTOMATA, MARCH, ETC)

int thisdelay = 50;          //-FX LOOPS DELAY VAR
int thisstep = 10;           //-FX LOOPS DELAY VAR
int thishue = 0;             //-FX LOOPS DELAY VAR
int thissat = 255;           //-FX LOOPS DELAY VAR

int thisindex = 0;
int thisRED = 0;
int thisGRN = 0;
int thisBLU = 0;

int idex = 0;                //-LED INDEX (0 to LED_COUNT-1
int ihue = 0;                //-HUE (0-255)
int ibright = 0;             //-BRIGHTNESS (0-255)
int isat = 0;                //-SATURATION (0-255)
int bouncedirection = 0;     //-SWITCH FOR COLOR BOUNCE (0-1)
float tcount = 0.0;          //-INC VAR FOR SIN LOOPS
int lcount = 0;              //-ANOTHER COUNTING VAR

unsigned long timing = 0;

// ---------------СЛУЖЕБНЫЕ ПЕРЕМЕННЫЕ-----------------

void one_color_all(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 0 ; i < LED_COUNT; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_allHSV(int ahue) {    //-SET ALL LEDS TO ONE COLOR (HSV)
  for (int i = 0 ; i < LED_COUNT; i++ ) {
    leds[i] = CHSV(ahue, thissat, 255);
  }
}

void print_mode(int ledMode) {
  Serial.print("Mode: ");
  Serial.println(ledMode);
  Serial.print("Delay: ");
  Serial.println(thisdelay);
}

void setup()
{
  Serial.begin(9600);              // открыть порт для связи
  LEDS.setBrightness(max_bright);  // ограничить максимальную яркость

  LEDS.addLeds<WS2811, LED_DT, GRB>(leds, LED_COUNT);  // настрйоки для нашей ленты (ленты на WS2811, WS2812, WS2812B)
  one_color_all(0, 0, 0);          // погасить все светодиоды
  LEDS.show();                     // отослать команду

  timing = millis();
  print_mode(ledMode);
}


//void change_mode(int newmode) {
//  thissat = 255;
//  switch (newmode) {
// 
//  }
//  bouncedirection = 0;
//  one_color_all(0, 0, 0);
//  ledMode = newmode;
//}

//void thebest() {
//  int repeat = 1;
//  int bestModes[] = {2, 3, 4};
//  for (int i = 0 ; i < sizeof(bestModes) / sizeof(bestModes[0]); i++ ) {
//    for (int r = 0; r < repeat; r++) {
//      ledMode = bestModes[i];
//    }
//  }
//}

void loop() {

  if (millis() - timing > 1000 * 30 ) { 
    timing = millis();
    ledMode++;
    print_mode(ledMode);
  }
  
  if (Serial.available() > 0) {     // если что то прислали
    ledMode = Serial.parseInt();    // парсим в тип данных int
    timing = millis();
    print_mode(ledMode);
  }
  
  // change_mode(ledMode);
  // print_mode(ledMode);
  
  switch (ledMode) {
    case  1: thisdelay = 20; rainbow_fade(); break;            // плавная смена цветов всей ленты
    case  2: thisdelay = 30; thisstep = 3; rainbow_loop(); break;            // крутящаяся радуга
    case  3: thisdelay = 200; random_burst(); break;            // случайная смена цветов
    case  4: thisdelay = 30; color_bounce(); break;            // бегающий светодиод
    case  5: thisdelay = 70; color_bounceFADE(); break;        // бегающий паровозик светодиодов
    case  6: thisdelay = 50; ems_lightsONE(); break;           // вращаются красный и синий
    case  7: thisdelay = 30; ems_lightsALL(); break;           // вращается половина красных и половина синих
    case  8: ledMode++ ; break; // thisdelay = 50; russian_flag(); break;
    case  9: ledMode++ ; break; // thisdelay = 50; rwb_march(); break;               // белый синий красный бегут по кругу (ПАТРИОТИЗМ!)
    case 11: thisdelay = 20; thishue = 30; pop_horizontal(); break;          // красные вспышки спускаются вниз
    case 12: ledMode++ ; break; // thisdelay = 40; flame(); break;                   // эффект пламени
    case 13: thisdelay = 50; thisstep = 15; rainbow_vertical(); break;        // радуга в вертикаьной плоскости (кольцо)
    case 14: thisdelay = 70; random_color_pop(); break;        // безумие случайных вспышек
    case 15: thisdelay = 50; rgb_propeller(); break;           // RGB пропеллер
    case 16: ledMode++ ; break; //thisdelay = 100; thishue = 10; kitt(); break;                    // случайные вспышки красного в вертикаьной плоскости
    case 17: thisdelay = 50; thishue = 95; matrix(); break;                  // зелёненькие бегают по кругу случайно
    case 18: thisdelay = 5; new_rainbow_loop(); break;        // крутая плавная вращающаяся радуга
    case 19: thisdelay = 50; strip_march_ccw(); break;         // чёт сломалось
    case 20: thisdelay = 50; strip_march_cw(); break;          // чёт сломалось
    case 21: colorWipe(0x00, 0xff, 0x00, thisdelay);
             colorWipe(0x00, 0x00, 0x00, thisdelay); break;   // плавное заполнение цветом
    case 22: thisdelay = 100; CylonBounce(0xff, 0, 0, 4, 10, thisdelay); break;                      // бегающие светодиоды
    case 23: ledMode++ ; break; // thisdelay = 15; Fire(55, 120, thisdelay); break;                                       // линейный огонь
    case 24: thisdelay = 100; NewKITT(0xff, 0, 0, 8, 10, thisdelay); break;                          // беготня секторов круга (не работает)
    case 25: thisdelay = 20; rainbowCycle(thisdelay); break;                                        // очень плавная вращающаяся радуга
    case 26: thisdelay = 30; TwinkleRandom(20, thisdelay, 1); break;                                // случайные разноцветные включения (1 - танцуют все, 0 - случайный 1 диод)
    case 27: thisdelay = 80; RunningLights(0xff, 0xff, 0x00, thisdelay); break;                     // бегущие огни
    case 28: thisdelay = 10; Sparkle(0xff, 0xaa, 0xff, thisdelay); break;                           // случайные вспышки белого цвета
    case 29: thisdelay = 20; SnowSparkle(0x10, 0x10, 0x10, thisdelay, random(100, 1000)); break;    // случайные вспышки белого цвета на белом фоне
    case 30: thisdelay = 150; theaterChase(0xff, 0, 0, thisdelay); break;                            // бегущие каждые 3 (ЧИСЛО СВЕТОДИОДОВ ДОЛЖНО БЫТЬ НЕЧЁТНОЕ)
    case 31: thisdelay = 200; theaterChaseRainbow(thisdelay); break;                                 // бегущие каждые 3 радуга (ЧИСЛО СВЕТОДИОДОВ ДОЛЖНО БЫТЬ КРАТНО 3)
    case 32: ledMode++ ; break; // thisdelay = 10; BouncingBalls(0xff, 0, 0, 3); break;                                   // прыгающие мячики
    case 33: ledMode++ ; break; // thisdelay = 200; BouncingColoredBalls(3, ballColors); break;                            // прыгающие мячики цветные
    case 34: ledMode = 1; break;
  }

}