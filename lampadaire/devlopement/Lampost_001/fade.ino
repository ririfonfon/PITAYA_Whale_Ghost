void fade_white() {
#ifdef DEBUG
  Serial.println("<100");
  Serial.print("RedNow: ");
  Serial.println(RedNow);
  Serial.print("GreenNow: ");
  Serial.println(GreenNow);
  Serial.print("BlueNow: ");
  Serial.println(BlueNow);
#endif
  RedNow = RedNow +  1;
  GreenNow = GreenNow +  1;
  BlueNow = BlueNow +  1;
  if (RedNow > 255) RedNow = 255;
  if (GreenNow > 255) GreenNow = 255;
  if (BlueNow > 255) BlueNow = 255;
  dmxbuffer[1] = (RedNow * RedNow) / 255;
  dmxbuffer[2] = (GreenNow * GreenNow) / 255;
  dmxbuffer[3] = (BlueNow * BlueNow) / 255;
  copyDMXToOutput();
  i = 0;
}

void fade_pink() {
  jRedNow = jRedNow +  1;
  jGreenNow = 0;
  jBlueNow = jBlueNow +  1;
  if (jRedNow > 255) jRedNow = 255;
  if (jBlueNow > 200) jBlueNow = 200;
  dmxbuffer[1] = (jRedNow * jRedNow) / 255;
  dmxbuffer[2] = (jGreenNow * jGreenNow) / 255;
  dmxbuffer[3] = (jBlueNow * jBlueNow) / 255;
  copyDMXToOutput();
  j = 0;
}

void fade_lavender() {
  kRedNow = kRedNow +  1;
  kGreenNow = 0;
  kBlueNow = kBlueNow +  1;
  if (kRedNow > 200) kRedNow = 200;
  if (kBlueNow > 255) kBlueNow = 255;
  dmxbuffer[1] = (kRedNow * kRedNow) / 255;
  dmxbuffer[2] = (kGreenNow * kGreenNow) / 255;
  dmxbuffer[3] = (kBlueNow * kBlueNow) / 255;
  copyDMXToOutput();
  k = 0;
}

