#include <Arduino.h>

#define PWM_CHANNELS 5      //
#define PWM_FREQUENCY 60000 //
#define PWM_RESOLUTION 16   //
uint8_t PWM_GPIOPIN[PWM_CHANNELS] = {32, 33, 25, 26, 27};

long previousMillis = 0;
bool cycle = true;
bool f0 = false;
bool f1 = false;
bool f2 = false;
bool f3 = false;
bool f4 = false;
bool p = false;
bool p0 = false;
bool p1 = false;
bool p2 = false;
bool p3 = false;
bool p4 = false;

long fade = 8;        // fade * 2,6 = seconds
long decalage = 1000; // milliseconds
long on = 20000;      // milliseconds
long off = 20000;     // milliseconds

int value[5] = {0};

unsigned long currentp;
unsigned long currentp0;
unsigned long currentp1;
unsigned long currentp2;
unsigned long currentp3;
unsigned long currentp4;

struct Led
{
  // state variables
  uint8_t pin;
  bool on;

  // methods
  void update()
  {
    digitalWrite(pin, on ? HIGH : LOW);
  }
};

Led onboard_led = {2, false};

void init_led()
{
  pinMode(onboard_led.pin, OUTPUT);
} //init_led

uint8_t ref[5];
void rnd()
{
  ref[0] = {8};
  ref[1] = {8};
  ref[2] = {8};
  ref[3] = {8};
  ref[4] = {8};
  int i = 0;
  
  boolean equals;
  // ref[i] = random(4);
  // Serial.print("ref[");
  // Serial.print(i);
  // Serial.print("] = ");
  // Serial.println(ref[i]);
  // i++;
  while (i != 5)
  {
    ref[i] = random(5);
    Serial.print("ref[");
    Serial.print(i);
    Serial.print("] = ");
    Serial.println(ref[i]);
    equals = false;
    for (int k = 0; k != i; k++)
    {
      Serial.print("k ref[");
      Serial.print(k);
      Serial.print("] = ");
      Serial.print(ref[k]);
      Serial.print("  iref[");
      Serial.print(i);
      Serial.print("] = ");
      Serial.println(ref[i]);
      if (ref[k] == ref[i])
      {
        equals = true;
      }
    }
    if (!equals)
    {
      i++;
    }
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.println();

  //init led
  init_led();

  //init pwm
  for (int k = 0; k < PWM_CHANNELS; k++)
  {
    ledcAttachPin(PWM_GPIOPIN[k], k);
    ledcSetup(k, PWM_FREQUENCY, PWM_RESOLUTION);
  }
  rnd();
  for (int k = 0; k > 5; k++)
  {
    Serial.println(ref[k]);
  }
}

void loop()
{
  onboard_led.on = millis() % 2000 < 1000;
  onboard_led.update();

  bool fade_clock;

  unsigned long currentMillis = millis();
  if (cycle)
  {
    previousMillis = currentMillis;
    cycle = false;
  }
  if (f0 != true && p0 != true && currentMillis - previousMillis > decalage)
  {
    Serial.print("f0 ");
    Serial.println(currentMillis);
    f0 = true;
  }
  if (f1 != true && p1 != true && currentMillis - previousMillis > (2 * decalage))
  {
    Serial.print("f1 ");
    Serial.println(currentMillis);
    f1 = true;
  }
  if (f2 != true && p2 != true && currentMillis - previousMillis > (3 * decalage))
  {
    Serial.print("f2 ");
    Serial.println(currentMillis);
    f2 = true;
  }
  if (f3 != true && p3 != true && currentMillis - previousMillis > (4 * decalage))
  {
    Serial.print("f3 ");
    Serial.println(currentMillis);
    f3 = true;
  }
  if (f4 != true && p4 != true && currentMillis - previousMillis > (5 * decalage))
  {
    Serial.print("f4 ");
    Serial.println(currentMillis);
    f4 = true;
  }
  if (f0)
  {
    fade_clock = millis() % fade < 1;
    if (fade_clock && f0)
    {
      value[0] += 1;
    }
    if (value[0] > 65535)
    {
      value[0] = 65535;
      f0 = false;
      p0 = true;
      currentp0 = currentMillis;
      Serial.print("currentp0 ");
      Serial.println(currentp0);
    }
  }
  if (f1)
  {
    fade_clock = millis() % fade < 1;
    if (fade_clock && f1)
    {
      value[1] += 1;
    }
    if (value[1] > 65535)
    {
      value[1] = 65535;
      f1 = false;
      p1 = true;
      currentp1 = currentMillis;
      Serial.print("currentp1 ");
      Serial.println(currentp1);
    }
  }
  if (f2)
  {
    fade_clock = millis() % fade < 1;
    if (fade_clock && f2)
    {
      value[2] += 1;
    }
    if (value[2] > 65535)
    {
      value[2] = 65535;
      f2 = false;
      p2 = true;
      currentp2 = currentMillis;
      Serial.print("currentp2 ");
      Serial.println(currentp2);
    }
  }
  if (f3)
  {
    fade_clock = millis() % fade < 1;
    if (fade_clock && f3)
    {
      value[3] += 1;
    }
    if (value[3] > 65535)
    {
      value[3] = 65535;
      f3 = false;
      p3 = true;
      currentp3 = currentMillis;
      Serial.print("currentp3 ");
      Serial.println(currentp3);
    }
  }
  if (f4)
  {
    fade_clock = millis() % fade < 1;
    if (fade_clock && f4)
    {
      value[4] += 1;
    }
    if (value[4] > 65535)
    {
      value[4] = 65535;
      f4 = false;
      p4 = true;
      currentp4 = currentMillis;
      Serial.print("currentp4 ");
      Serial.println(currentp4);
    }
  }

  if (p0 && currentMillis - currentp0 > on)
  {
    value[0] = 0;
  }
  if (p1 && currentMillis - currentp1 > on)
  {
    value[1] = 0;
  }
  if (p2 && currentMillis - currentp2 > on)
  {
    value[2] = 0;
  }
  if (p3 && currentMillis - currentp3 > on)
  {
    value[3] = 0;
  }
  if (p4 && p != true && currentMillis - currentp4 > on)
  {
    value[4] = 0;
    p = true;
    currentp = currentMillis;
    Serial.print("currentp ");
    Serial.println(currentp);
  }

  if (p && currentMillis - currentp > off)
  {
    previousMillis = currentMillis;
    p = false;
    p0 = false;
    p1 = false;
    p2 = false;
    p3 = false;
    p4 = false;
    f0 = false;
    f1 = false;
    f2 = false;
    f3 = false;
    f4 = false;
    rnd();
  }
  ledcWrite(0, value[ref[0]]);
  ledcWrite(1, value[ref[1]]);
  ledcWrite(2, value[ref[2]]);
  ledcWrite(3, value[ref[3]]);
  ledcWrite(4, value[ref[4]]);
}