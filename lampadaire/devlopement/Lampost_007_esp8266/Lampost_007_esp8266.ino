/**************************************************************************/
/*!
    @file     lampost_006.ino
    @author   riri

*/
/**************************************************************************/

#define DEBUG 1
//#define DEBUGSR 1
#define DEBUGDMX 1
//#define DEBUGDMXvalue 1
//#define DEBUGTOUCH 1
//#define DEBUGMP3 1

#include <LXESP8266UARTDMX.h>
#include "Wire.h"

#define DMX_DIRECTION_PIN 21
#define DMX_SERIAL_OUTPUT_PIN 17

/****************************** MP3 ********************/
HardwareSerial mp3(1);

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

/************ Opitons **************************/
#define DEV_TF            0X02
/**********************************************************************/

uint8_t level;
uint8_t dmxbuffer[DMX_MAX_FRAME];

int RedList[]   = {70, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80};
int GreenList[] = {40, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
int BlueList[]  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int h;
int i;
int j;
int k;
int l;
uint8_t pink_lav = 0;

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

int detected = 20;
int Released = 25;

int temp = 1;

int cmd;

unsigned long lastRefresh = 0;
#define REFRESH 1000

unsigned long lastRefreshT = 0;
#define REFRESHT 1250

int x;
int y;

int distance;
TwoWire I2C = TwoWire(8);                // join i2c bus with address #8

void setup() {

#ifdef DEBUG
  Serial.begin(115200);
  Serial.println("setup");
#endif

  mp3.begin(9600, SERIAL_8N1, 32, 33);
  delay(500);

  sendCommand(CMD_SEL_DEV, DEV_TF);
  delay(500);

  pinMode(DMX_DIRECTION_PIN, OUTPUT);
  digitalWrite(DMX_DIRECTION_PIN, HIGH);

  pinMode(DMX_SERIAL_OUTPUT_PIN, OUTPUT);
  ESP8266DMX.startOutput(DMX_SERIAL_OUTPUT_PIN);


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
  /**********************************/
  distance = I2C.read();

  Serial.println(distance);

  //    if ((millis() - lastRefresh) > REFRESH) {
  //      if (state == 0) {
  //
  //      }
  //      lastRefresh = millis();
  //    }
  //
  //    if (state < 3) {
  //      if (distance < 100) {
  //        i = i + 1;
  //        if (i >= 10) {
  //          i = 0;
  //          state = 1;
  //          fade_white();
  //        }
  //      }
  //      if (distance > 130) {
  //        h = h + 1;
  //        if (h >= 10) {
  //          h = 0;
  //          if (state == 0) {
  //            play_seq();
  //          }
  //          if (state == 2) {
  //            h = 0;
  //            fade_seq();
  //          }
  //        }
  //      }
  //    }
  //  if ((millis() - lastRefreshT) > REFRESHT) {
  //#ifdef DEBUGTOUCH
  //    Serial.print("touchRead(T0):");
  //    Serial.println(touchRead(T0));
  //    Serial.print("touchRead(T3):");
  //    Serial.println(touchRead(T3));
  //#endif
  //
  //    if ((touchRead(T0) > Released) && (touchRead(T3) < detected)) {
  //#ifdef DEBUGTOUCH
  //      Serial.println("Touch 7 detected");
  //      Serial.print(" j : ");
  //      Serial.println(j);
  //#endif
  //      j = j + 1;
  //      if (j >= 10) {
  //        state = 3 ;
  //        fade_pink();
  //      }
  //    }
  //    else if ((touchRead(T0) < detected) && (touchRead(T3) > Released)) {
  //#ifdef DEBUGTOUCH
  //      Serial.println("Touch 6 detected");
  //#endif
  //      k = k + 1;
  //      if (k >= 10) {
  //        state = 4;
  //        fade_lavender();
  //      }
  //    }
  //    else if ((touchRead(T0) < detected) && (touchRead(T3) < detected)) {
  //#ifdef DEBUGTOUCH
  //      Serial.println("Touch 7 & 6 detected");
  //#endif
  //      l = l + 1;
  //      if (l >= 10) {
  //        state = 5;
  //        fade_pink_lavender();
  //      }
  //    }
  //    else if ((touchRead(T0) > Released) && (touchRead(T3) > Released)) {
  //#ifdef DEBUGTOUCH
  //      Serial.println("Touch 7 & 6 Released");
  //#endif
  //      if (state > 2) {
  //        state = 0;
  //      }
  //    }
  //    lastRefreshT = millis();
  //  }
}

