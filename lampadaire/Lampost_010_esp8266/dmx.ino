void copyDMXToOutput(void) {
#ifdef DEBUGDMXvalue
  Serial.print("Red : ");
  Serial.println(dmxbuffer[1]);
  Serial.print("Green: ");
  Serial.println(dmxbuffer[2]);
  Serial.print("Blue: ");
  Serial.println(dmxbuffer[3]);
#endif
  dmx_red = dmxbuffer[1];
  dmx_green = dmxbuffer[2];
  dmx_blue = dmxbuffer[3];

  for (int i = 1; i < DMX_MAX_FRAME; i++) {
    ESP8266DMX.setSlot(i , (uint8_t((dmxbuffer[i]*dmxbuffer[i]) / 255)));
  }

}


