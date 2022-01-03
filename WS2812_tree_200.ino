/*
  Скетч создан на основе FASTSPI2 EFFECTS EXAMPLES автора teldredge (www.funkboxing.com)
  А также вот этой статьи https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/#cylon
  Доработан, переведён и разбит на файлы 2017 AlexGyver
  Отправляем в монитор порта номер режима, он активируется
*/

#include "FastLED.h"          // библиотека для работы с лентой

#define LED_COUNT 200         // 170 - max number of leds for Arduino Nano v3
#define LED_DT 13             // pin for пин, куда подключен DIN ленты
#define SWITCH_DT  2           // pin for night mode switcher (brightness)
#define MAX_BRIGHTNESS 200     // maximal brightness
#define NIGHT_BRIGHTNESS 10
#define SECONDS_PER_MODE 30

byte brightness = 200;          // максимальная яркость (0 - 255)
byte ledMode = 34;               // first mode
boolean night = false;          // not all animations during the night
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
byte ledsX[LED_COUNT][3];     //-ARRAY FOR COPYING WHATS IN THE LED STRIP CURRENTLY (FOR CELL-AUTOMATA, MARCH, ETC)

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


const byte PYRAMID_LEVELS_COUNT = 7;
const byte PYRAMID_LEVELS[PYRAMID_LEVELS_COUNT][2] = {
    {0,54},       // 54
    {55,97},      // 42
    {98,129},     // 31
    {130,153},    // 23
    {154,170},    // 16
    {171,187},    // 16
    {188,200}     // 12
};

unsigned long timing = 0;
byte buttonState = 0;

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

void print_mode() {
  Serial.print("Mode: ");
  Serial.println(ledMode);
  Serial.print("Delay: ");
  Serial.println(thisdelay);
  Serial.print("Brightness: ");
  Serial.println(brightness);
}

void setup()
{
  pinMode(SWITCH_DT, INPUT_PULLUP);
  Serial.begin(9600);              // открыть порт для связи
  LEDS.setBrightness(brightness);  // ограничить максимальную яркость

  LEDS.addLeds<WS2811, LED_DT, RGB>(leds, LED_COUNT);  // настрйоки для нашей ленты (ленты на WS2811, WS2812, WS2812B)
  one_color_all(0, 0, 0);          // погасить все светодиоды
  LEDS.show();                     // отослать команду

  timing = millis();
  print_mode();
}

void loop() {
  if ( digitalRead(SWITCH_DT) != buttonState ) {
    buttonState = digitalRead(SWITCH_DT);
    if ( brightness == MAX_BRIGHTNESS ) {
      night = true; 
      brightness = NIGHT_BRIGHTNESS;
    } else {
      night = false;
      brightness = MAX_BRIGHTNESS;
    }
    LEDS.setBrightness(brightness);  // ограничить максимальную яркость
  }

  if (millis() - timing > 1000 * SECONDS_PER_MODE ) { 
    timing = millis();
    ledMode++;
    print_mode();
  }
  
  if (Serial.available() > 0) {     // если что то прислали
    ledMode = Serial.parseInt();    // парсим в тип данных int
    timing = millis();
    print_mode();
  }
  
  // change_mode(ledMode);
  // print_mode(ledMode);
  
  switch (ledMode) {
    case  1: thisdelay = 20; rainbow_fade(); break;            // плавная смена цветов всей ленты
    case  2: thisdelay = 30; thisstep = 3; rainbow_loop(); break;            // крутящаяся радуга
    case  3: thisdelay = 200; random_burst(); break;            // случайная смена цветов
    case  4: thisdelay = 30; color_bounce(); break;            // бегающий светодиод
    case  5: thisdelay = 50; color_bounceFADE(); break;        // бегающий паровозик светодиодов
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
    case 19: thisdelay = 50; strip_march_ccw(); break;         // против часовой стрелки
    case 20: thisdelay = 50; strip_march_cw(); break;          // по часовой стрелке
    case 21: colorWipe(0x00, 0xff, 0x00, thisdelay); break;   // плавное заполнение цветом
    case 22: colorWipe(0x00, 0x00, 0x00, thisdelay); break;   // плавное заполнение цветом
    case 23: thisdelay = 100; CylonBounce(0xff, 0, 0, 4, 10, thisdelay); break;                     // бегающие светодиоды
    case 24: ledMode++ ; break; // thisdelay = 15; Fire(55, 120, thisdelay); break;                 // линейный огонь
    case 25: thisdelay = 100; NewKITT(0xff, 0, 0, 8, 10, thisdelay); break;                         // беготня секторов круга (не работает)
    case 26: thisdelay = 20; rainbowCycle(thisdelay); break;                                        // очень плавная вращающаяся радуга
    case 27: thisdelay = 30; TwinkleRandom(20, thisdelay, 1); break;                                // случайные разноцветные включения (1 - танцуют все, 0 - случайный 1 диод)
    case 28: thisdelay = 80; RunningLights(0xff, 0xff, 0x00, thisdelay); break;                     // бегущие огни
    case 29: thisdelay = 30; Sparkle(0xff, 0xaa, 0xff, thisdelay); break;                           // случайные вспышки белого цвета
    case 30: thisdelay = 20; SnowSparkle(0x10, 0x10, 0x10, thisdelay, random(100, 500)); break;     // случайные вспышки белого цвета на белом фоне
    case 31: thisdelay = 150; theaterChase(0xff, 0, 0, thisdelay); break;                           // бегущие каждые 3 (ЧИСЛО СВЕТОДИОДОВ ДОЛЖНО БЫТЬ НЕЧЁТНОЕ)
    case 32: thisdelay = 200; theaterChaseRainbow(thisdelay); break;                                // бегущие каждые 3 радуга (ЧИСЛО СВЕТОДИОДОВ ДОЛЖНО БЫТЬ КРАТНО 3)
    case 33: thisdelay = 100; Pyramid1(thisdelay, 255, 0, 0); break;
    case 34: thisdelay = 20; Pyramid2(thisdelay, 0, 250, 0); break;
    case 35: thisdelay = 20; Pyramid3(thisdelay, 0, 250, 0); break;
    case 36: ledMode = 1; break;
  }

}
