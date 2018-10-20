#include <HardWire.h>

int c;

void setup() {
  Serial.begin(115200);
//  Wire.begin(10, 9);
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.println("ok");
}

void loop() {

  delay(100);
}

// function that executes when ever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    c = Wire.read(); // receive byte as a character
    Serial.println(c);         // print the character
  }
}

