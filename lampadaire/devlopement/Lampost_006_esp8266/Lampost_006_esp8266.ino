/**************************************************************************/
/*!
    @file     lampost_006.ino
    @author   riri

*/
/**************************************************************************/

#define DEBUG 1
//#define DEBUGSR 1
//#define DEBUGDMX 1
//#define DEBUGDMXvalue 1
//#define DEBUGTOUCH 1
//#define DEBUGMP3 1

// Make code work with normal Wire library.
#include <Arduino.h>
#include <Wire.h>
#define myWire Wire

// dmx shield
#include <LXESP8266UARTDMX.h>

#define DMX_DIRECTION_PIN D3
#define DMX_SERIAL_OUTPUT_PIN D4

/****************************** MP3 ********************/
#include <SoftwareSerial.h>
SoftwareSerial mp3(D7, D8);

static int8_t Send_buf[8] = {0}; // Buffer for Send commands.  // BETTER LOCALLY
static uint8_t ansbuf[10] = {0}; // Buffer for the answers.    // BETTER LOCALLY

String mp3Answer;           // Answer from the MP3.

/************ Command byte **************************/
#define CMD_NEXT_SONG     0X01  // Play next song.
#define CMD_PREV_SONG     0X02  // Play previous song.
#define CMD_PLAY_W_INDEX  0X03
#define CMD_VOLUME_UP     0X04
#define CMD_VOLUME_DOWN   0X05
#define CMD_SET_VOLUME    0X06

#define CMD_SNG_CYCL_PLAY 0X08  // Single Cycle Play.
#define CMD_SEL_DEV       0X09
#define CMD_SLEEP_MODE    0X0A
#define CMD_WAKE_UP       0X0B
#define CMD_RESET         0X0C
#define CMD_PLAY          0X0D
#define CMD_PAUSE         0X0E
#define CMD_PLAY_FOLDER_FILE 0X0F

#define CMD_STOP_PLAY     0X16
#define CMD_FOLDER_CYCLE  0X17
#define CMD_SHUFFLE_PLAY  0x18 //
#define CMD_SET_SNGL_CYCL 0X19 // Set single cycle.

#define CMD_SET_DAC 0X1A
#define DAC_ON  0X00
#define DAC_OFF 0X01

#define CMD_PLAY_W_VOL    0X22
#define CMD_PLAYING_N     0x4C
#define CMD_QUERY_STATUS      0x42
#define CMD_QUERY_VOLUME      0x43
#define CMD_QUERY_FLDR_TRACKS 0x4e
#define CMD_QUERY_TOT_TRACKS  0x48
#define CMD_QUERY_FLDR_COUNT  0x4f

/************ Options **************************/
#define DEV_TF            0X02
/***********************************************/



uint8_t level;
uint8_t dmxbuffer[DMX_MAX_FRAME];

int RedList[]   = {70, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 180, 200, 200, 200};
int GreenList[] = {40, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 130, 150, 150, 150};
int BlueList[]  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int h;
int i;
int j;
int k;
int l;
uint8_t pink_red = 0;

float NowRed = 0;
float NowGreen = 0;
float NowBlue = 0;

float RedNow = 0;
float GreenNow = 0;
float BlueNow = 0;

float jRedNow = 0;
float jGreenNow = 0;
float jBlueNow = 0;

float kRedNow = 0;
float kGreenNow = 0;
float kBlueNow = 0;

float lRedNow = 0;
float lGreenNow = 0;
float lBlueNow = 0;

float mRedNow = 255;
float mGreenNow = 255;
float mBlueNow = 255;

int state = 0;

// defines pins numbers hr
const int trigPin = D5;
const int echoPin = D6;

// defines variables hr
long duration;
int distance;

int temp = 1;

int cmd = 0;

int n;

int touch1;
int touch2;

unsigned long lastRefresh = 0;
#define REFRESH 100

//unsigned long lastRefreshT = 0;
//#define REFRESHT 490

void setup() {

#ifdef DEBUG
  Serial.begin(74880);
  Serial.setDebugOutput(1); //use uart0 for debugging
  Serial.println("setup");
#endif

  mp3.begin(9600);
  delay(500);

  sendCommand(CMD_SEL_DEV, DEV_TF);
  delay(500);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  pinMode(DMX_DIRECTION_PIN, OUTPUT);
  digitalWrite(DMX_DIRECTION_PIN, HIGH);

  pinMode(DMX_SERIAL_OUTPUT_PIN, OUTPUT);
  ESP8266DMX.startOutput();

  myWire.begin(5, 4);
  myWire.begin();


  trig();

#ifdef DEBUG
  Serial.println("setup complete");
#endif
}

void loop() {

  /************** mp3 ****************/
  char c = ' ';

  // If there a char on Serial call sendMP3Command to sendCommand
  if ( Serial.available() )
  {
    c = Serial.read();
    sendMP3Command(c);
  }

  // Check for the answer.
  if (mp3.available())
  {
    char c = ' ';

    // If there a char on Serial call sendMP3Command to sendCommand
    if ( Serial.available() )
    {
      c = Serial.read();
      sendMP3Command(c);
    }

    // Check for the answer.
    if (mp3.available())
    {
#ifdef DEBUGMP3
      Serial.print("decodeMP3Answer():");
      Serial.println(decodeMP3Answer());
#endif
    }
  }
  /***************i2c****************/
  if (state != 1) {
  n = myWire.requestFrom(4, 2);
  byte buffer[40];
  myWire.readBytes( buffer, n);
  touch1 = (int) buffer[0];
  touch2 = (int) buffer[1];
#ifdef DEBUGTOUCH
  Serial.print("touch1 : ");
  Serial.print(touch1);
  Serial.print(" touch2 : ");
  Serial.print(touch2);
  Serial.print(" state : ");
  Serial.print(state);
  Serial.print(" distance : ");
  Serial.println(distance);
#endif
  }
  /**********************************/

  if ((millis() - lastRefresh) > REFRESH) {
    if (state == 0) {
      trig();
    }
    lastRefresh = millis();
  }

  if (state < 3) {
    if (distance < 100) {
      i = i + 1;
      if (i >= 10) {
        i = 0;
        state = 1;
        fade_white();
      }
    }
    if (distance > 120) {
      h = h + 1;
      if (h >= 10) {
        h = 0;
        if (state == 0) {
          play_seq();
        }
        if (state == 1) {
          fade_white();
        }
        if (state == 2) {
          fade_seq();
        }
      }
    }
  }
  if (touch1 < 10 && touch2 < 10 && state > 2 ) {
    state = 0 ;
  }

  if (touch1 > 10 && touch2 < 10) {
    state = 3 ;
    fade_pink();
  }
  if (touch1 < 10 && touch2 > 10) {
    state = 4;
    fade_red();
  }
  if (touch1 > 10 && touch2 > 10) {
    state = 5;
    fade_pink_red();
  }
}
