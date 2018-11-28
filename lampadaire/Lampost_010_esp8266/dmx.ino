void copyDMXToOutput(void) {
  dmx_red = dmxbuffer[1];
  dmx_green = dmxbuffer[2];
  dmx_blue = dmxbuffer[3];

  for (int i = 1; i < DMX_MAX_FRAME; i++) {
    ESP8266DMX.setSlot(i , dmxbuffer[i]);
  }

}


