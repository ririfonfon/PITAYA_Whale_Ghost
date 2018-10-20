
#include <Wire.h>
#include <CapacitiveSensor.h>

long d;
int e;
int f;

long a;
int b;
int c;

CapacitiveSensor   cs_8_9 = CapacitiveSensor(8, 9);
CapacitiveSensor   cs_8_6 = CapacitiveSensor(8, 6);

void setup() {
  Serial.begin(9600);           // start serial for output
  Serial.println("\nSlave");

  Wire.begin(4); // join i2c bus as slave with address #4

  Wire.onRequest(requestEvent); // interrupt handler for when data is requested by i2c
}

void loop() {
  d =  cs_8_9.capacitiveSensor(30);
  if (d<150) f=150;
  else if (d>3000) f=3000;
  else f=d;
  e = map (f, 150, 3000, 0, 255);

  a =  cs_8_6.capacitiveSensor(30);
  if (a<150) c=150;
  else if (a>3000) c=3000;
  else c=a;
  b = map (c, 150, 3000, 0, 255);

  Serial.print(" d : ");
  Serial.print(d);
  Serial.print(" e : ");
  Serial.println(e);
  Serial.print(" a : ");
  Serial.print(a);
  Serial.print(" b : ");
  Serial.println(b);
}

void requestEvent() {

  static byte i = 0;
  char TXbuf[] = { e, b };
  Wire.write(TXbuf, sizeof(TXbuf));

}

