/**************************************************************************/
/*!
    @file     lampost_011_esp82266.ino
    @author   riri
    @NodeMCU 1.0(ESP-12E Module)
*/
/**************************************************************************/

//#define DEBUG 1
//#define DEBUGDMX 1
//#define DEBUGDMXvalue 1
//#define DEBUGTOUCH 1
//#define DEBUGMP3 1
//#define DEBUGSTATE 1

/***************************** WIRE ********************/
#include <Arduino.h>
#include <Wire.h>
#define myWire Wire

/****************************** DMX ********************/
#include <LXESP8266UARTDMX.h>

#define DMX_DIRECTION_PIN D3
#define DMX_SERIAL_OUTPUT_PIN D4
long level;
uint8_t part;
float dmxbuffer[DMX_MAX_FRAME];

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

/***************************** HC-SR501 **********************/
// defines pins numbers hc
const int trigPin = D5;
int distance;

/************************* Variable ********************/

#define REFRESH 100                 //timing de trig loop
unsigned long lastRefresh = 0;

#define REFRESHw 100                //timing de trig de fade white
unsigned long lastRefreshw = 0;

#define REFRESHbingo 39000          //timing de play de bingo
unsigned long lastbingo = 0;

#define REFRESHtouch 2000           //timing de trig de touch
unsigned long lasttouch = 0;
int cmdtouch;

int bingo_win = 2500;                //timing de play bingo

int state = 0;                      //statue_prog
int cmd = 0;                        //statue_mp3
int rnd = 0;                        //statue_rnd

uint8_t temp = 1;                   // delay_dmx_send
uint8_t temp_mp3 = 5;               // delay_mp3_send

const int no_presence = 200;        // hc value
const int presence = 100;           // hc gate

const int MP3_Volume = 28;          //volume mp3 (0-30)

const long loop_time = 8000;           //gate de time
const int loop_time_seq = 100;       //gate de time de seq
long loop_time_bingo = 1500;    //gate de couleur de bingo

const int touch_gate = 10;          //gate de touch

uint8_t seq;                        //time_loop de play
uint8_t etat;                       //etat anim auto
uint8_t h;                          //time_loop no_presence
uint8_t i;                          //time_loop presence
uint8_t j;                          //time_loop pink touch1
uint8_t k;                          //time_loop R  touch2
uint8_t l;                          //time_loop pink_rouge touch1 && touch2
uint8_t m;                          //time_loop i2c
uint8_t o;                          //time_fade pink-rouge
long p;                             //time_loop no_presence de fade w
int bi;                             //time_loop de bingo
long to;                             //time_loop de fade to

uint8_t n;                          //I2C varible de myWire.requestFrom(4, 2);
uint8_t tir;

float rouge ;
float vert ;
float bleu ;

uint8_t ro ;
uint8_t ve ;
uint8_t bl ;

int touch1;
int touch2;

int bingo;


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

  pinMode(trigPin, INPUT); // Sets the trigPin as an Input


  pinMode(DMX_DIRECTION_PIN, OUTPUT);
  digitalWrite(DMX_DIRECTION_PIN, HIGH);

  pinMode(DMX_SERIAL_OUTPUT_PIN, OUTPUT);
  ESP8266DMX.startOutput();

  //  myWire.begin(5, 4);
  //  myWire.begin();

  etat = 0;
  trig();

#ifdef DEBUG
  Serial.println("setup complete");
#endif
  delay(5000);
}

/***************************** LOOP ********************/
void loop() {



  /************** mp3 ****************/
  //  check_mp3();

  /***************i2c****************/
  //  if (state != 1) {
  //    m++;
  //    if (m >= loop_time) {
  //      m = 0;
  //      I2C_request();
  //    }
  //  }

  /**************Prog****************/


  trig();


  if (distance <= presence && rnd == 0) {
        tir++;
        if (tir <= 9) {
          state = 1;
        }
        else if (tir >= 10) {
          tir = 0;
          state = 2;
        }

#ifdef DEBUGSTATE
    Serial.print("state de rnd :");
    Serial.print(state);
    Serial.print(" /rnd :");
    Serial.println(rnd);
#endif
    rnd = 1;
    distance = no_presence;
  }

  if (state == 0) {
    play_seq();
  }
  else if (state == 1) {
    fade_white();
  }

  else if (state == 2) {
    bingo_chase();
  }

  else if (state == 6) {
    fade_to();
  }

  else if (state == 9) {
#ifdef DEBUGSTATE
    Serial.print("state :");
    Serial.print(state);
    Serial.print(" /rnd :");
    Serial.println(rnd);
#endif
    part = 0;
    seq = 0;
    level = 0;
    state = 0;
    rnd = 0;
  }

  else if (state == 12) {
    fade_pink();
  }
  else if (state == 13) {
    fade_rouge();
  }

}
