
#define DEBUG 1

#include "SPI.h"
#include "Wire.h"

const int trigPin = D5;
const int echoPin = D6;

// defines variables hr
long duration;
int distance;

void setup() {
#ifdef DEBUG
  Serial.begin(115200);
  Serial.println("setup");
#endif
  
  Wire.begin();
//  Wire.setClock(400000L);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop() {
  trig();
  sendi2c();
}

void sendi2c()
{
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(distance);              // sends one byte
  Wire.endTransmission();    // stop transmitting
  Serial.print("->>");
  Serial.println(distance);
  delay(500);
}
