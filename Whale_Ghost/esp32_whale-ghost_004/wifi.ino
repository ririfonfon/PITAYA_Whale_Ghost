#include <WiFi.h>
#include <WiFiUdp.h>

WiFiUDP WUdp;

//Wifi settings
const char* ssid = "stratum";
const char* password = "9000leds";

//
// NETWORK
//
IPAddress server(192, 168, 0, 255);
unsigned int udpPort_node = 3737;  // Node port to listen on
unsigned int udpPort_server = 3738;  // Server port to speak to

void wifi_init() {

  IPAddress ip(192, 168, 0, eeprom_getID() + 100);               // Static IP
  IPAddress gateway(192, 168, 0, 1);
  IPAddress subnet(255, 255, 255, 0);

  // Enable wifi
  WiFi.mode(WIFI_STA);
  WiFi.config(ip, gateway, subnet);

  // Connect wifi
  WiFi.onEvent(wifi_event);
  WiFi.begin(ssid, password);

  // UDP Receiver
  WUdp.begin(udpPort_node);

#if defined(DEBUG)
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), udpPort_node);
#endif

}

void wifi_send(uint8_t* message, int sizeM) {
  WUdp.beginPacket(server, udpPort_server);
  WUdp.write(message, sizeM);
  WUdp.endPacket();
}


bool wifi_read(unsigned char* incomingPacket) {
  int packetSize = WUdp.parsePacket();
  if (packetSize)
  {
#if defined(DEBUG_MSG)
    Serial.printf("Received %d bytes from %s\n", packetSize, WUdp.remoteIP().toString().c_str());
#endif

    // receive incoming UDP packets
    int len = WUdp.read(incomingPacket, MTUu);

#if defined(DEBUG_MSG)
    Serial.println("Packet stored\n");
    for (int k = 0; k < len; k++) Serial.printf("%i ", incomingPacket[k]);
    Serial.println();
    //Serial.printf("PACKET: %s*\n", incomingPacket);
#endif

    return true;
  }
  return false;
}

void wifi_event(WiFiEvent_t event) {
  static byte retry = 0;
  static byte maxRetry = 15;

#ifdef DEBUG
  switch (event) {
    case SYSTEM_EVENT_STA_CONNECTED:
      Serial.print("WiFi connected");
      break;
    case SYSTEM_EVENT_STA_GOT_IP:
      Serial.print("Wifi Connected with IP: ");
      Serial.println(WiFi.localIP());
      break;
    case SYSTEM_EVENT_STA_LOST_IP:
      Serial.print("Lost IP..");
      break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
      Serial.print("WiFi lost connection... ");
      break;
  }
#endif

  if (event == SYSTEM_EVENT_STA_DISCONNECTED) {
    retry += 1;
    /*if (retry > maxRetry) {
      #ifdef DEBUG
        Serial.println("Can't connect to WIFI... RESTART ESP !");
      #endif
      WiFi.disconnect(true);
      delay(500);
      ESP.restart();
      }*/

#ifdef DEBUG
    Serial.print(" reconnecting ");
    Serial.print(retry);
    //Serial.print("/");
    //Serial.print(maxRetry);
    Serial.println();
#endif
    WiFi.reconnect();
  }
  else if (event == SYSTEM_EVENT_STA_GOT_IP) {
    retry = 0;
  }
}

