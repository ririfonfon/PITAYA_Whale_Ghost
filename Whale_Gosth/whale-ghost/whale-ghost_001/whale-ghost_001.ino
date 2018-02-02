//Debug
//#define DEBUG 1

//Lib
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ArtnetWifi.h>
#include <Adafruit_NeoPixel.h>

//Wifi settings
const char* ssid = "RIRI-DMX-WiFi";
const char* password = "riridmxwifi";
#define WIFI_TIMEOUT 30000
unsigned long last_wifi_check_time = 0;

//WS settings
#define NUM_STRIPS 6
#define NUM_LEDS_PER_STRIP 28
const int numberOfChannels = NUM_STRIPS * NUM_LEDS_PER_STRIP * 3;
const int numberOfLed = NUM_STRIPS * NUM_LEDS_PER_STRIP ;

Adafruit_NeoPixel strip0 = Adafruit_NeoPixel(NUM_LEDS_PER_STRIP, 5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_LEDS_PER_STRIP, 4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_LEDS_PER_STRIP, 0, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(NUM_LEDS_PER_STRIP, 2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(NUM_LEDS_PER_STRIP, 14, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(NUM_LEDS_PER_STRIP, 12, NEO_GRB + NEO_KHZ800);

void leds_init() {
  strip0.begin();
  strip1.begin();
  strip2.begin();
  strip3.begin();
  strip4.begin();
  strip5.begin();
}

void leds_show() {
  strip0.show();
  strip1.show();
  strip2.show();
  strip3.show();
  strip4.show();
  strip5.show();
}

// Artnet settings
ArtnetWifi artnet;
const int startUniverse = 0; // CHANGE FOR YOUR SETUP most software this is 1, some software send out artnet first universe as 0.

// Check if we got all universes
const int maxUniverses = numberOfChannels / 512 + ((numberOfChannels % 512) ? 1 : 0);
bool universesReceived[maxUniverses];
bool sendFrame = 1;
int previousDataLength = 0;

// connect to wifi – returns true if successful or false if not
boolean ConnectWifi(void) {
  boolean state = true;
  int i = 0;

  WiFi.begin(ssid, password);
  #ifdef DEBUG
  Serial.println("");
  Serial.println("Connecting to WiFi");
  
  // Wait for connection
  Serial.print("Connecting");
  #endif
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    #ifdef DEBUG
    Serial.print(".");
    #endif
    if (i > 20){
      state = false;
      break;
    }
    i++;
  }
  if (state){
    #ifdef DEBUG
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    #endif
  } else {
    #ifdef DEBUG
    Serial.println("");
    Serial.println("Connection failed.");
    #endif
  }
  
  return state;
}//ConnectWifi

void initTest() {
  for (int i = 0 ; i < numberOfLed ; i++) {
  if (i<=NUM_LEDS_PER_STRIP) 
    strip0.setPixelColor(i, 127, 0, 0);
  
  if (i<=NUM_LEDS_PER_STRIP*2 & i>=NUM_LEDS_PER_STRIP) 
    strip1.setPixelColor(i-NUM_LEDS_PER_STRIP, 127, 0, 0);
  
  if (i<=NUM_LEDS_PER_STRIP*3 & i>=NUM_LEDS_PER_STRIP*2) 
    strip2.setPixelColor(i-NUM_LEDS_PER_STRIP*2, 127, 0, 0);
  
  if (i<=NUM_LEDS_PER_STRIP*4 & i>=NUM_LEDS_PER_STRIP*3) 
    strip3.setPixelColor(i-NUM_LEDS_PER_STRIP*3, 127, 0, 0);
  
  if (i<=NUM_LEDS_PER_STRIP*5 & i>=NUM_LEDS_PER_STRIP*4) 
    strip4.setPixelColor(i-NUM_LEDS_PER_STRIP*4, 127, 0, 0);
  
  if (i<=NUM_LEDS_PER_STRIP*6 & i>=NUM_LEDS_PER_STRIP*5)
    strip5.setPixelColor(i-NUM_LEDS_PER_STRIP*5, 127, 0, 0);
  
  leds_show();
}//for i
  delay(500);
  for (int i = 0 ; i < numberOfLed ; i++) {
    if (i<=NUM_LEDS_PER_STRIP) 
    strip0.setPixelColor(i, 0, 127, 0);
  
  if (i<=NUM_LEDS_PER_STRIP*2 & i>=NUM_LEDS_PER_STRIP) 
    strip1.setPixelColor(i-NUM_LEDS_PER_STRIP, 0, 127, 0);
  
  if (i<=NUM_LEDS_PER_STRIP*3 & i>=NUM_LEDS_PER_STRIP*2) 
    strip2.setPixelColor(i-NUM_LEDS_PER_STRIP*2, 0, 127, 0);
  
  if (i<=NUM_LEDS_PER_STRIP*4 & i>=NUM_LEDS_PER_STRIP*3) 
    strip3.setPixelColor(i-NUM_LEDS_PER_STRIP*3, 0, 127, 0);
  
  if (i<=NUM_LEDS_PER_STRIP*5 & i>=NUM_LEDS_PER_STRIP*4) 
    strip4.setPixelColor(i-NUM_LEDS_PER_STRIP*4, 0, 127, 0);
  
  if (i<=NUM_LEDS_PER_STRIP*6 & i>=NUM_LEDS_PER_STRIP*5) 
    strip5.setPixelColor(i-NUM_LEDS_PER_STRIP*5, 0, 127, 0);
  
  leds_show();
}//for i
  delay(500);
  for (int i = 0 ; i < numberOfLed ; i++) {
    if (i<=NUM_LEDS_PER_STRIP) 
    strip0.setPixelColor(i, 0, 0, 127);
  
  if (i<=NUM_LEDS_PER_STRIP*2 & i>=NUM_LEDS_PER_STRIP) 
    strip1.setPixelColor(i-NUM_LEDS_PER_STRIP, 0, 0, 127);
  
  if (i<=NUM_LEDS_PER_STRIP*3 & i>=NUM_LEDS_PER_STRIP*2) 
    strip2.setPixelColor(i-NUM_LEDS_PER_STRIP*2, 0, 0, 127);
  
  if (i<=NUM_LEDS_PER_STRIP*4 & i>=NUM_LEDS_PER_STRIP*3) 
    strip3.setPixelColor(i-NUM_LEDS_PER_STRIP*3, 0, 0, 127);
  
  if (i<=NUM_LEDS_PER_STRIP*5 & i>=NUM_LEDS_PER_STRIP*4) 
    strip4.setPixelColor(i-NUM_LEDS_PER_STRIP*4, 0, 0, 127);
  
  if (i<=NUM_LEDS_PER_STRIP*6 & i>=NUM_LEDS_PER_STRIP*5) 
    strip5.setPixelColor(i-NUM_LEDS_PER_STRIP*5, 0, 0, 127);
  
  leds_show();
  }//for i
  delay(500);
  for (int i = 0 ; i < numberOfLed ; i++) {
     if (i<=NUM_LEDS_PER_STRIP) 
    strip0.setPixelColor(i, 0, 0, 0);
  
  if (i<=NUM_LEDS_PER_STRIP*2 & i>=NUM_LEDS_PER_STRIP) 
    strip1.setPixelColor(i-NUM_LEDS_PER_STRIP, 0, 0, 0);
  
  if (i<=NUM_LEDS_PER_STRIP*3 & i>=NUM_LEDS_PER_STRIP*2) 
    strip2.setPixelColor(i-NUM_LEDS_PER_STRIP*2, 0, 0, 0);
  
  if (i<=NUM_LEDS_PER_STRIP*4 & i>=NUM_LEDS_PER_STRIP*3) 
    strip3.setPixelColor(i-NUM_LEDS_PER_STRIP*3, 0, 0, 0);
  
  if (i<=NUM_LEDS_PER_STRIP*5 & i>=NUM_LEDS_PER_STRIP*4) 
    strip4.setPixelColor(i-NUM_LEDS_PER_STRIP*4, 0, 0, 0);
  
  if (i<=NUM_LEDS_PER_STRIP*6 & i>=NUM_LEDS_PER_STRIP*5) 
    strip5.setPixelColor(i-NUM_LEDS_PER_STRIP*5, 0, 0, 0);
  
  }
  leds_show();
}//initest

void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data) {
  sendFrame = 1;
  // set brightness of the whole strip 
  if (universe == 15)
  {
    strip0.setBrightness(data[0]);
    strip1.setBrightness(data[0]);
    strip2.setBrightness(data[0]);
    strip3.setBrightness(data[0]);
    strip4.setBrightness(data[0]);
    strip5.setBrightness(data[0]);
    leds_show();
  }

  // Store which universe has got in
  if ((universe - startUniverse) < maxUniverses)
    universesReceived[universe - startUniverse] = 1;

  for (int i = 0 ; i < maxUniverses ; i++) {
    if (universesReceived[i] == 0) {
      #ifdef DEBUG
      Serial.println("Broke");
      #endif
      sendFrame = 0;
      break;
    }
  }//for i

  // read universe and put into the right part of the display buffer
  for (int i = 0; i < length / 3; i++)
  {
    int led = i + (universe - startUniverse) * (previousDataLength / 3);
    if (led<=NUM_LEDS_PER_STRIP) {
    strip0.setPixelColor(led, data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
  }
  if (led<=NUM_LEDS_PER_STRIP*2 & led>=NUM_LEDS_PER_STRIP) 
    strip1.setPixelColor(led-NUM_LEDS_PER_STRIP, data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
  
  if (led<=NUM_LEDS_PER_STRIP*3 & led>=NUM_LEDS_PER_STRIP*2) 
    strip2.setPixelColor(led-NUM_LEDS_PER_STRIP*2, data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
  
  if (led<=NUM_LEDS_PER_STRIP*4 & led>=NUM_LEDS_PER_STRIP*3) 
    strip3.setPixelColor(led-NUM_LEDS_PER_STRIP*3, data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
  
  if (led<=NUM_LEDS_PER_STRIP*5 & led>=NUM_LEDS_PER_STRIP*4) 
    strip4.setPixelColor(led-NUM_LEDS_PER_STRIP*4, data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
  
  if (led<=NUM_LEDS_PER_STRIP*6 & led>=NUM_LEDS_PER_STRIP*5) 
    strip5.setPixelColor(led-NUM_LEDS_PER_STRIP*5, data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
  
  }//for i
  previousDataLength = length;     
  
  if (sendFrame){
    leds_show();
    // Reset universeReceived to 0
    memset(universesReceived, 0, maxUniverses);
  }
}//onframedmx

void setup() {
  #ifdef DEBUG
  Serial.begin(115200);
  #endif
  ConnectWifi();
  artnet.begin();
  leds_init();
  initTest();

  // this will be called for each packet received
  artnet.setArtDmxCallback(onDmxFrame);
}//setup

void loop() {
  unsigned long now = millis();

    if(now - last_wifi_check_time > WIFI_TIMEOUT) {
      #ifdef DEBUG
      Serial.print("Checking WiFi... ");
      #endif
    if(WiFi.status() != WL_CONNECTED) {
      #ifdef DEBUG
      Serial.println("WiFi connection lost. Reconnecting...");
      #endif
      ConnectWifi();
    } else {
      #ifdef DEBUG
      Serial.println("OK");
      #endif
    }
    last_wifi_check_time = now;
  }
  // we call the read function inside the loop
  artnet.read();
}//loop
