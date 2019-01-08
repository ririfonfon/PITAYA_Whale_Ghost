
#include "Wire.h"

int c;

void setup() {
  Serial.begin(115200);
  Wire.begin(8);                // join i2c bus with address #8
  
}

void loop() {
  Wire.onReceive(receiveEvent); // register event
  delay(500);
}

// function that executes when ever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    c = Wire.read(8); // receive byte as a character
    Serial.println(c);         // print the character
  }
}

