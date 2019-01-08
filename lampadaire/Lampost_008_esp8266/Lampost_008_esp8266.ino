/**************************************************************************/
/*!
    @file     lampost_008_esp82266.ino
    @author   riri
    @NodeMCU 1.0(ESP-12E Module)
*/
/**************************************************************************/

//#define DEBUG 1
//#define DEBUGSR 1
//#define DEBUGDMX 1
//#define DEBUGDMXvalue 1
//#define DEBUGTOUCH 1
//#define DEBUGMP3 1

/***************************** WIRE ********************/
#include <Arduino.h>
#include <Wire.h>
#define myWire Wire

/****************************** DMX ********************/
#include <LXESP8266UARTDMX.h>

#define DMX_DIRECTION_PIN D3
#define DMX_SERIAL_OUTPUT_PIN D4
uint8_t level;
uint8_t dmxbuffer[DMX_MAX_FRAME];

/****************************** MP3 ********************/
#include <SoftwareSerial.h>
SoftwareSerial mp3(D7, D8);

static int8_t Send_buf[8] = {0}; // Buffer for Send commands.
static uint8_t ansbuf[10] = {0}; // Buffer for the answers.
String mp3Answer;                // Answer from the MP3.

/*************** Command byte **************************/
#define CMD_NEXT_SONG         0X01  // Play next song.
#define CMD_PREV_SONG         0X02  // Play previous song.
#define CMD_PLAY_W_INDEX      0X03  //
#define CMD_VOLUME_UP         0X04  //
#define CMD_VOLUME_DOWN       0X05  //
#define CMD_SET_VOLUME        0X06  //(0-30)

#define CMD_SNG_CYCL_PLAY     0X08  // Single Cycle Play.
#define CMD_SEL_DEV           0X09  //
#define CMD_SLEEP_MODE        0X0A  //
#define CMD_WAKE_UP           0X0B  //
#define CMD_RESET             0X0C  //
#define CMD_PLAY              0X0D  //
#define CMD_PAUSE             0X0E  //
#define CMD_PLAY_FOLDER_FILE  0X0F  //

#define CMD_STOP_PLAY         0X16  //
#define CMD_FOLDER_CYCLE      0X17  //
#define CMD_SHUFFLE_PLAY      0x18  //
#define CMD_SET_SNGL_CYCL     0X19  // Set single cycle.

#define CMD_SET_DAC           0X1A  //
#define DAC_ON                0X00  //
#define DAC_OFF               0X01  //

#define CMD_PLAY_W_VOL        0X22  //
#define CMD_PLAYING_N         0x4C  //
#define CMD_QUERY_STATUS      0x42  //
#define CMD_QUERY_VOLUME      0x43  //
#define CMD_QUERY_FLDR_TRACKS 0x4e  //
#define CMD_QUERY_TOT_TRACKS  0x48  //
#define CMD_QUERY_FLDR_COUNT  0x4f  //

/******************** Options **************************/
#define DEV_TF                0X02  //
/*******************************************************/

/***************************** HC-SR04 **********************/
// defines pins numbers hc
const int trigPin = D5;
const int echoPin = D6;
// defines variables hr
long duration;
int distance;

/************************* Variable ********************/
unsigned long lastRefresh = 0;
#define REFRESH 100                 //timing de trig loop
unsigned long lastRefreshw = 0;
#define REFRESHw 100                //timing de trig de fade white

int state = 0;                      //statue_prog
int cmd = 0;                        //statue_mp3

uint8_t temp = 1;                   // delay_dmx_send
uint8_t temp_mp3 = 5;              // delay_mp3_send

const int no_presence = 120;        // hc value
const int presence = 100;           // hc gate

const int MP3_Volume = 30;          //volume mp3 (0-30)

const int loop_time = 10;           //gate de time

uint8_t h;                          //time_loop no_presence
uint8_t i;                          //time_loop presence
uint8_t j;                          //time_loop pink touch1
uint8_t k;                          //time_loop red  touch2
uint8_t l;                          //time_loop pink_red touch1 && touch2
uint8_t m;                          //time_loop i2c
uint8_t o;                          //time_fade pink-red
uint8_t p;                          //time_loop no_presence de fade w

uint8_t n;                          //I2C varible de myWire.requestFrom(4, 2);

uint8_t pink_red = 0;               //statue de fade pink red

float RedNow = 0;
float GreenNow = 0;
float BlueNow = 0;                  // rvb fade_white

float jRedNow = 0;
float jGreenNow = 0;
float jBlueNow = 0;                 // rvb fade_pink

float kRedNow = 0;
float kGreenNow = 0;
float kBlueNow = 0;                 // rvb fade_red

float lRedNow = 0;
float lGreenNow = 0;
float lBlueNow = 0;                 // rvb fade_pink_red

float mRedNow = 255;
float mGreenNow = 255;
float mBlueNow = 240;               // rvb seq_fade

int touch1;
int touch2;
const int touch_gate = 10;          //gate de touch


/**************************** SETUP ********************/
void setup() {

#ifdef DEBUG
  Serial.begin(74880);             //74880 freq de l'esp8266 crash
  Serial.setDebugOutput(1);        //use uart0 for debugging
  Serial.println("setup");
#endif

  mp3.begin(9600);
  delay(500);
  sendCommand(CMD_SEL_DEV, DEV_TF);
  delay(500);
  sendCommand(CMD_SET_VOLUME, MP3_Volume);
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

/***************************** LOOP ********************/
void loop() {
  /************** mp3 ****************/
  check_mp3();

  /***************i2c****************/
  if (state != 1) {
    m++;
    if (m >= loop_time) {
      m = 0;
      I2C_request();
    }
  }

  /**************Prog****************/

  if ((millis() - lastRefresh) > REFRESH) {
    if (state == 0) {
      trig();
    }
    lastRefresh = millis();
  }

  if (state < 3) {
    if (distance < presence) {
      i++;
      if (i >= loop_time) {
        i = 0;
        state = 1;
        fade_white();
        I2C_request();
      }
    }
    if (distance > no_presence) {
      h++;
      if (h >= loop_time) {
        h = 0;
        if (state == 0) {
          play_seq();
        }
        else if (state == 1) {
          fade_white();
        }
        else if (state == 2) {
          fade_seq();
        }
      }
    }
  }
    if (touch1 < touch_gate && touch2 < touch_gate && state > 2 ) {
      state = 0 ;
    }
  
    if (touch1 > touch_gate && touch2 < touch_gate) {
      j++;
      if (j >= loop_time) {
        state = 3 ;
        fade_pink();
      }
    }
    if (touch1 < touch_gate && touch2 > touch_gate) {
      k++;
      if (k >= loop_time) {
        state = 4;
        fade_red();
      }
    }
    if (touch1 > touch_gate && touch2 > touch_gate) {
      l++;
      if (l >= loop_time) {
        state = 5;
        fade_pink_red();
      }
    }
}
