#ifndef variable_h
#define variable_h
#endif

#define PWM_CHANNELS 5      //
#define PWM_FREQUENCY 60000 //
#define PWM_RESOLUTION 16   //

uint8_t PWM_GPIOPIN[PWM_CHANNELS] = {32, 33, 25, 26, 27};

long previousMillis = 0;
bool cycle = true;

bool f[PWM_CHANNELS] = {false};
bool p[PWM_CHANNELS+1] = {false};
bool n[PWM_CHANNELS] = {false};
unsigned long currentp[PWM_CHANNELS];

long fade = 8;        // fade * 2,6 = seconds
long decalage = 1000; // milliseconds
long on = 20000;      // milliseconds
long off = 20000;     // milliseconds

int value[PWM_CHANNELS] = {0};

uint8_t ref[PWM_CHANNELS];