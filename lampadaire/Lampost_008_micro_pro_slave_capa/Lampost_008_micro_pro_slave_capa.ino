/**************************************************************************/
/*!
    @file     lampost_008_micro_pro_slave_capa.ino
    @author   riri
    @arduino leonardo (micro_pro_MEGA32U4)
*/
/**************************************************************************/

#define DEBUG 1

/************************** Include ********************/
#include <Wire.h>
#include <CapacitiveSensor.h>
long d;           // touch 9

/************************* Variable ********************/
int e;            // map touch 9
int f;            // map de e

long a;           // touch 6
int b;            // map touch 6
int c;            // map de b

int aniv_h = 2000;
int aniv_b = 1000;

int dniv_h = 2000;
int dniv_b = 1000;

/*************************** Touch **********************/
CapacitiveSensor   cs_8_9 = CapacitiveSensor(8, 9);
CapacitiveSensor   cs_8_6 = CapacitiveSensor(8, 6);

/**************************** SETUP ********************/
void setup() {
#ifdef DEBUG
  Serial.begin(9600);              // start serial for output
  Serial.println("\nSlave");
#endif

  Wire.begin(4);                  // join i2c bus as slave with address #4
  Wire.onRequest(requestEvent);   // interrupt handler for when data is requested by i2c
}

/***************************** LOOP ********************/
void loop() {
  d =  cs_8_9.capacitiveSensor(30);
  if (d < dniv_b) f = dniv_b;
  else if (d > dniv_h) f = dniv_h;
  else f = d;
  e = map (f, dniv_b, dniv_h, 0, 255);

  a =  cs_8_6.capacitiveSensor(30);
  if (a < aniv_b) c = aniv_b;
  else if (a > aniv_h) c = aniv_h;
  else c = a;
  b = map (c, aniv_b, aniv_h, 0, 255);

#ifdef DEBUG
  Serial.print(" d : ");
  Serial.print(d);
  Serial.print(" e : ");
  Serial.println(e);
  Serial.print(" a : ");
  Serial.print(a);
  Serial.print(" b : ");
  Serial.println(b);
#endif
}

/*********************** requestEvent ********************/
void requestEvent() {
  static byte i = 0;
  char TXbuf[] = { e, b };
  Wire.write(TXbuf, sizeof(TXbuf));
}

