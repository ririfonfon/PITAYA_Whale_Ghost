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

float RedNow = 0;
float GreenNow = 0;
float BlueNow = 0;

float jRedNow = 0;
float jGreenNow = 0;
float jBlueNow = 0;

float kRedNow = 0;
float kGreenNow = 0;
float kBlueNow = 0;

int state = 0;

// defines pins numbers
const int trigPin = 2;  //D4
const int echoPin = 0;  //D3

// defines variables
long duration;
int distance;
int i;
int j;
int k;

int threshold = 10;
bool touch8detected = false;
bool touch9detected = false;

void setup() {
#ifdef DEBUG
  Serial.begin(115200);
  Serial.print("setup");
#endif

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  pinMode(DMX_DIRECTION_PIN, OUTPUT);
  digitalWrite(DMX_DIRECTION_PIN, HIGH);

  pinMode(DMX_SERIAL_OUTPUT_PIN, OUTPUT);
  ESP32DMX.startOutput(DMX_SERIAL_OUTPUT_PIN);

  touchAttachInterrupt(T8, gotTouch8, threshold);
  touchAttachInterrupt(T9, gotTouch9, threshold);

#ifdef DEBUG
  Serial.println("setup complete");
#endif
}

void loop() {

  if (distance == 0) {
    reset_hcsr04();
  }

  else if (distance < 100) {
    i = i + 1;
    if (i = 250000) {
      fade_white();
    }
  }
  else if (distance > 130) {
    i = i + 1;
    if (i = 250000) {
      play_seq();
    }
  }

  else if (touch8detected) {
    touch8detected = false;
    Serial.println("Touch 8 detected");
    j = j + 1;
    if (j = 250000) {
      fade_pink();
    }
  }
  else if (touch9detected) {
    touch9detected = false;
    Serial.println("Touch 9 detected");
    k = k + 1;
    if (k = 250000) {
      fade_lavender();
    }
  }
  else {

    trig();
  }
}

void gotTouch8() {
  touch8detected = true;
}

void gotTouch9() {
  touch9detected = true;
}
