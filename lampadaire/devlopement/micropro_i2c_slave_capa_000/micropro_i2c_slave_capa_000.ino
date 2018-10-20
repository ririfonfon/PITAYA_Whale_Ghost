
#include <Wire.h>
#include <CapacitiveSensor.h>

long y;
int x;

CapacitiveSensor   cs_8_9 = CapacitiveSensor(8, 9);

void setup() {
  Serial.begin(9600);           // start serial for output
  Serial.println("\nSlave");

  Wire.begin(4); // join i2c bus as slave with address #4

  Wire.onRequest(requestEvent); // interrupt handler for when data is requested by i2c
}

void loop() {
  x = map (y, 500, 4500, 0, 255);
  y =  cs_8_9.capacitiveSensor(30);
  Serial.print(" y : ");
  Serial.print(y);
  Serial.print(" x : ");
  Serial.println(x);
}

void requestEvent() {

  Wire.write(x);

}

