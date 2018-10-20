/**************************************************************************/
/*!
    @file     lampost_001.ino
    @author   riri

*/
/**************************************************************************/

#define DEBUG 1

#include <LXESP32DMX.h>
#include "esp_task_wdt.h"

#include <RBD_Timer.h>  // https://github.com/alextaujenis/RBD_Timer
#include <RBD_Button.h> // https://github.com/alextaujenis/RBD_Button
RBD::Button button9(T9); //droite
RBD::Button button8(T8); //gauche
//uint8_t init_btn9 = 0;
//uint8_t init_btn8 = 0;

#define DMX_DIRECTION_PIN 21
#define DMX_SERIAL_OUTPUT_PIN 17

uint8_t level;
uint8_t dmxbuffer[DMX_MAX_FRAME];

int RedList[]   = {70, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80};
int GreenList[] = {40, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
int BlueList[]  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int h;
int i;
int j;
int k;
int l;
uint8_t pink_lav = 0;

float NowRed = 0;
float NowGreen = 0;
float NowBlue = 0;

float RedNow = 0;
float GreenNow = 0;
float BlueNow = 0;

float jRedNow = 0;
float jGreenNow = 0;
float jBlueNow = 0;

float kRedNow = 0;
float kGreenNow = 0;
float kBlueNow = 0;

float lRedNow = 0;
float lGreenNow = 0;
float lBlueNow = 0;

float mRedNow = 255;
float mGreenNow = 255;
float mBlueNow = 255;

int state = 0;

// defines pins numbers hr
const int trigPin = 35;
const int echoPin = 34;

// defines variables hr
long duration;
int distance;



void setup() {
#ifdef DEBUG
  Serial.begin(115200);
  //Serial.setDebugOutput(1); //use uart0 for debugging
  Serial.print("setup");
#endif

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  pinMode(DMX_DIRECTION_PIN, OUTPUT);
  digitalWrite(DMX_DIRECTION_PIN, HIGH);

  pinMode(DMX_SERIAL_OUTPUT_PIN, OUTPUT);
  ESP32DMX.startOutput(DMX_SERIAL_OUTPUT_PIN);

  trig();

#ifdef DEBUG
  Serial.println("setup complete");
#endif
}

void loop() {
  if (state == 0) {
    trig();
  }

  if (distance < 100) {
    i = i + 1;
    if (i = 250000) {
      state = 1;
      fade_white();
    }
  }
  if (distance > 130) {
    h = h + 1;
    if (h = 250000) {
      if (state == 0) {
        play_seq();
      }
      if (state == 2) {
        fade_seq();
      }
    }
  }

  if (button9.isReleased() && button8.isPressed()) {
#ifdef DEBUG
    Serial.println("Touch 8 detected");
#endif
    j = j + 1;
    if (j = 250000) {
      state = 3 ;
      fade_pink();
    }
  }
  else if (button9.isPressed() && button8.isReleased()) {
#ifdef DEBUG
    Serial.println("Touch 9 detected");
#endif
    k = k + 1;
    if (k = 250000) {
      state = 4;
      fade_lavender();
    }
  }
  else if (button9.isPressed() && button8.isPressed()) {
#ifdef DEBUG
    Serial.println("Touch 8 & 9 detected");
#endif
    l = l + 1;
    if (l = 250000) {
      state = 5;
      fade_pink_lavender();
    }
  }
  else if (button9.isReleased() && button8.isReleased()) {
#ifdef DEBUG
    Serial.println("Touch 8 & 9 isReleased()");
#endif
    if (state > 2) {
      state = 0;
    }
  }
}

