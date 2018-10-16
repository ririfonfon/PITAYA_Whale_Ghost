void copyDMXToOutput(void) {
  for (int i = 1; i < DMX_MAX_FRAME; i++) {
    ESP8266DMX.setSlot(i , dmxbuffer[i]);
  }

}


