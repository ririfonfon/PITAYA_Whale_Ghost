void copyDMXToOutput(void) {
#ifdef DEBUGDMXvalue
  Serial.print("rouge : ");
  Serial.println(dmxbuffer[1]);
  Serial.print("vert: ");
  Serial.println(dmxbuffer[2]);
  Serial.print("bleu: ");
  Serial.println(dmxbuffer[3]);
#endif
  rouge = dmxbuffer[1];
  ro = uint8_t(rouge);
  vert = dmxbuffer[2];
  ve = uint8_t(vert);
  bleu = dmxbuffer[3];
  bl = uint8_t(bleu);

  for (int i = 1; i < DMX_MAX_FRAME; i++) {
    ESP8266DMX.setSlot(i , (uint8_t((dmxbuffer[i]*dmxbuffer[i]) / 255)));
  }

}


