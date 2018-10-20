void fade_white() {
  if (cmd == 1) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0201);
    cmd = 2;
  }
#ifdef DEBUGDMXvalue
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
  if ((RedNow == 255) && (GreenNow == 255) && (BlueNow == 255)) {
#ifdef DEBUGDMX
    Serial.print("w");
#endif
    state = 2;
    if ((millis() - lastRefresh) > REFRESH) {
#ifdef DEBUGDMX
      Serial.println("*****************trig************************");
#endif
      
      lastRefresh = millis();
    }
  }
  if (state < 2) {
    Serial.println("state < 2");
    dmxbuffer[1] = (RedNow * RedNow) / 255;
    dmxbuffer[2] = (GreenNow * GreenNow) / 255;
    dmxbuffer[3] = (BlueNow * BlueNow) / 255;
    copyDMXToOutput();
    delay(temp);
  }
  i = 0;
  //  yield();
}

void fade_pink() {
#ifdef DEBUGDMX
  Serial.println("fade_pink()");
#endif
  jRedNow = jRedNow +  1;
  jGreenNow = 0;
  jBlueNow = jBlueNow +  1;
  if (jRedNow > 255) jRedNow = 255;
  if (jBlueNow > 100) jBlueNow = 100;
  dmxbuffer[1] = (jRedNow * jRedNow) / 255;
  dmxbuffer[2] = (jGreenNow * jGreenNow) / 255;
  dmxbuffer[3] = (jBlueNow * jBlueNow) / 255;
  copyDMXToOutput();
  delay(temp);
  j = 0;
}

void fade_lavender() {
#ifdef DEBUGDMX
  Serial.println("fade_lavender()");
#endif
  kRedNow = kRedNow +  1;
  kGreenNow = 0;
  kBlueNow = kBlueNow +  1;
  if (kRedNow > 100) kRedNow = 100;
  if (kBlueNow > 255) kBlueNow = 255;
  dmxbuffer[1] = (kRedNow * kRedNow) / 255;
  dmxbuffer[2] = (kGreenNow * kGreenNow) / 255;
  dmxbuffer[3] = (kBlueNow * kBlueNow) / 255;
  copyDMXToOutput();
  delay(temp);
  k = 0;
}
void fade_pink_lavender() {
#ifdef DEBUGDMX
  Serial.println("fade_pink_lavender()");
#endif
  if (pink_lav == 0) {
#ifdef DEBUGDMX
    Serial.println("pink_lav = 0");
#endif
#ifdef DEBUGDMXvalue
    Serial.print("lRedNow: ");
    Serial.println(lRedNow);
    Serial.print("lGreenNow: ");
    Serial.println(lGreenNow);
    Serial.print("lBlueNow: ");
    Serial.println(lBlueNow);
#endif
    lRedNow = lRedNow +  1;
    lGreenNow = 0;
    lBlueNow = lBlueNow +  1;
    if (lRedNow > 255) lRedNow = 255;
    if (lBlueNow > 200) lBlueNow = 200;
    if ((lRedNow == 255) && (lBlueNow == 200)) {
      pink_lav = 1;
    }
  }
  if (pink_lav == 1) {
#ifdef DEBUGDMX
    Serial.println("pink_lav = 1");
#endif
#ifdef DEBUGDMXvalue
    Serial.print("lRedNow: ");
    Serial.println(lRedNow);
    Serial.print("lGreenNow: ");
    Serial.println(lGreenNow);
    Serial.print("lBlueNow: ");
    Serial.println(lBlueNow);
#endif
    lRedNow = lRedNow -  1;
    lGreenNow = 0;
    lBlueNow = lBlueNow +  1;
    if (lRedNow < 100) lRedNow = 100;
    if (lBlueNow > 255) lBlueNow = 255;
    if ((lRedNow == 100) && (lBlueNow == 255)) {
#ifdef DEBUGDMX
      Serial.println("((lRedNow == 100) && (lBlueNow == 255))");
#endif
      pink_lav = 2;
      yield();
    }
  }
  if (pink_lav == 2) {
#ifdef DEBUGDMX
    Serial.println("pink_lav = 2");
#endif
#ifdef DEBUGDMXvalue
    Serial.print("lRedNow: ");
    Serial.println(lRedNow);
    Serial.print("lGreenNow: ");
    Serial.println(lGreenNow);
    Serial.print("lBlueNow: ");
    Serial.println(lBlueNow);
#endif
    lRedNow = lRedNow +  1;
    lGreenNow = 0;
    lBlueNow = lBlueNow -  1;
    if (lRedNow > 255) lRedNow = 255;
    if (lBlueNow < 100) lBlueNow = 100;
    if ((lRedNow == 255) && (lBlueNow == 100)) {
#ifdef DEBUGDMX
      Serial.println("((lRedNow == 255) && (lBlueNow == 100))");
#endif
      pink_lav = 1;
    }
  }
  dmxbuffer[1] = (lRedNow * lRedNow) / 255;
  dmxbuffer[2] = (lGreenNow * lGreenNow) / 255;
  dmxbuffer[3] = (lBlueNow * lBlueNow) / 255;
  copyDMXToOutput();
  delay(temp);
  l = 0;
}

void fade_seq() {
  if (cmd == 2) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0301);
    cmd = 0;
  }
#ifdef DEBUGDMX
  Serial.println("fade_seq()");
#endif
#ifdef DEBUGDMXvalue
  Serial.print("mRedNow: ");
  Serial.println(mRedNow);
  Serial.print("mGreenNow: ");
  Serial.println(mGreenNow);
  Serial.print("mBlueNow: ");
  Serial.println(mBlueNow);
#endif
  mRedNow = mRedNow - 1;
  mGreenNow = mGreenNow - 1;
  mBlueNow = mBlueNow - 1;
  if (mRedNow < 80) mRedNow = 80;
  if (mGreenNow < 50) mGreenNow = 50;
  if (mBlueNow < 0) mBlueNow = 0;
  if ((mRedNow == 80) && (mGreenNow == 50) && (mBlueNow == 0)) {
#ifdef DEBUGDMX
    Serial.println("((mRedNow == 80) && (mGreenNow == 50) && (mBlueNow == 0))");
#endif
    yield();
    state = 0;
    h = 0;
  }

  dmxbuffer[1] = (mRedNow * mRedNow) / 255;
  dmxbuffer[2] = (mGreenNow * mGreenNow) / 255;
  dmxbuffer[3] = (mBlueNow * mBlueNow) / 255;
  copyDMXToOutput();
  delay(temp);
  h = 0;
}


