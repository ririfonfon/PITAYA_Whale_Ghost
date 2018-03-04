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

  // Enable wifi and connect
  WiFi.mode(WIFI_STA);
  WiFi.config(ip, gateway, subnet);
  WiFi.setAutoReconnect(true);
  WiFi.begin(ssid, password);

  // If WIFI is the main channel, wait for connection to succeed or restart
  if (WiFi.waitForConnectResult() != WL_CONNECTED)  ESP.restart();

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

