/**************************************************************************/
/*!
    @file     lampost_001.ino
    @author   riri

*/
/**************************************************************************/

#define DEBUG 1

#include <LXESP32DMX.h>
#include "esp_task_wdt.h"

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

int detected = 20;
int Released = 25;

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
#ifdef DEBUG
  Serial.print("touchRead(6):");
  Serial.println(touchRead(T6));
  Serial.print("touchRead(T7):");
  Serial.println(touchRead(T7));
#endif

  if ((touchRead(T6) > Released) && (touchRead(T7) < detected)) {
#ifdef DEBUG
    Serial.println("Touch 7 detected");
#endif
    j = j + 1;
    if (j = 250000) {
      state = 3 ;
      fade_pink();
    }
  }
  else if ((touchRead(T6) < detected) && (touchRead(T7) > Released)) {
#ifdef DEBUG
    Serial.println("Touch 6 detected");
#endif
    k = k + 1;
    if (k = 250000) {
      state = 4;
      fade_lavender();
    }
  }
  else if ((touchRead(T6) < detected) && (touchRead(T7) < detected)) {
#ifdef DEBUG
    Serial.println("Touch 7 & 6 detected");
#endif
    l = l + 1;
    if (l = 250000) {
      state = 5;
      fade_pink_lavender();
    }
  }
  else if ((touchRead(T6) > Released) && (touchRead(T7) > Released)) {
#ifdef DEBUG
    Serial.println("Touch 7 & 6 Released");
#endif
    if (state > 2) {
      state = 0;
    }
  }
}

