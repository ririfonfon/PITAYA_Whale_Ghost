#define DEBUG 1

#include "Wire.h"

long cm;

void setup() {
  Wire.begin(3, 1);

  delay(100);
}

void loop() {

  cm = 58;

  sendi2c();
  delay(100);
}

void sendi2c()
{
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(cm);              // sends one byte
  Wire.endTransmission();    // stop transmitting
}



