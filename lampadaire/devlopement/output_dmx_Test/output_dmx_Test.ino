#define DEBUG 1
/**************************************************************************/
/*!
    @file     output_dmx_Test.ino
    @author   riri
    @license  BSD (see LXESP32DMX LICENSE)
    @copyright 2017 by Claude Heintz

    Simple Fade test of ESP32 DMX Driver
    @section  HISTORY

    v1.00 - First release
*/
/**************************************************************************/
#include <LXESP32DMX.h>
#include "esp_task_wdt.h"

#define DMX_DIRECTION_PIN 21
#define DMX_SERIAL_OUTPUT_PIN 17

uint8_t level;
uint8_t dmxbuffer[DMX_MAX_FRAME];

int RedList[]   = {70, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80};
int GreenList[] = {40, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
int BlueList[]  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


int RedLevel, GreenLevel, BlueLevel;

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

void copyDMXToOutput(void) {
  xSemaphoreTake( ESP32DMX.lxDataLock, portMAX_DELAY );
  for (int i = 1; i < DMX_MAX_FRAME; i++) {
    ESP32DMX.setSlot(i , dmxbuffer[i]);
  }
  xSemaphoreGive( ESP32DMX.lxDataLock );
}

void loop() {

  if (touch8detected) {
    touch8detected = false;
    Serial.println("Touch 8 detected");
    j = j + 1;
    if (j = 250000) {
      jRedNow = jRedNow +  1;
      jGreenNow = 0;
      jBlueNow = jBlueNow +  1;
      if (jRedNow > 255) jRedNow = 255;
      if (jBlueNow > 200) jBlueNow = 200;
      dmxbuffer[1] = (jRedNow * jRedNow) / 255;
      dmxbuffer[2] = (jGreenNow * jGreenNow) / 255;
      dmxbuffer[3] = (jBlueNow * jBlueNow) / 255;
      copyDMXToOutput();
      j = 0;
    }
  }
  else if (touch9detected) {
    touch9detected = false;
    Serial.println("Touch 9 detected");
    k = k + 1;
    if (k = 250000) {
      kRedNow = kRedNow +  1;
      kGreenNow = 0;
      kBlueNow = kBlueNow +  1;
      if (kRedNow > 200) kRedNow = 200;
      if (kBlueNow > 255) kBlueNow = 255;
      dmxbuffer[1] = (kRedNow * kRedNow) / 255;
      dmxbuffer[2] = (kGreenNow * kGreenNow) / 255;
      dmxbuffer[3] = (kBlueNow * kBlueNow) / 255;
      copyDMXToOutput();
      k = 0;
    }
  }
  else {

    trig();
  }
}

void trig() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;

  if (distance == 0) {
#ifdef DEBUG
    Serial.println("reset hcsr04");
#endif
    reset_hcsr04();
  }

  if (distance < 100) {
    i = i + 1;
    if (i = 250000) {
#ifdef DEBUG
      Serial.println("<100");
      Serial.print("RedNow: ");
      Serial.println(RedNow);
      Serial.print("GreenNow: ");
      Serial.println(GreenNow);
      Serial.print("BlueNow: ");
      Serial.println(BlueNow);
#endif
      RedNow = RedNow +  1;
      GreenNow = GreenNow +  1;
      BlueNow = BlueNow +  1;
      if (RedNow > 255) RedNow = 255;
      if (GreenNow > 255) GreenNow = 255;
      if (BlueNow > 255) BlueNow = 255;
      dmxbuffer[1] = (RedNow * RedNow) / 255;
      dmxbuffer[2] = (GreenNow * GreenNow) / 255;
      dmxbuffer[3] = (BlueNow * BlueNow) / 255;
      copyDMXToOutput();
      i = 0;
    }
  }
  if (distance > 130) {
    i = i + 1;
    if (i = 250000) {
#ifdef DEBUG
      Serial.println(">130");
#endif
      RedNow = 0;
      GreenNow = 0;
      BlueNow = 0;

      jRedNow = 0;
      jGreenNow = 0;
      jBlueNow = 0;

      kRedNow = 0;
      kGreenNow = 0;
      kBlueNow = 0;
      i = 0;
      dmxbuffer[1] = RedList[level];
      dmxbuffer[2] = GreenList[level];
      dmxbuffer[3] = BlueList[level];


      copyDMXToOutput();
      i = 0;

      level++;
      if (level > 20) level = 0;

      esp_task_wdt_feed();
      vTaskDelay(100);
    }
  }
#ifdef DEBUG
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
#endif
}

void reset_hcsr04() {
  pinMode(echoPin, OUTPUT);
  digitalWrite(echoPin, LOW);
  delay(100);
  pinMode(echoPin, INPUT);
}

void gotTouch8() {
  touch8detected = true;
}

void gotTouch9() {
  touch9detected = true;
}
