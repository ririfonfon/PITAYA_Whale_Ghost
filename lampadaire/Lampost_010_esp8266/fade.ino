void fade_white() {
#ifdef DEBUGDMX
  Serial.println("fade_white()");
#endif
  if (cmd != 2) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0201);
    delay(temp_mp3);
    cmd = 2;
  }
#ifdef DEBUGDMXvalue
  Serial.println("presence");
  Serial.print("RedNow: ");
  Serial.println(RedNow);
  Serial.print("GreenNow: ");
  Serial.println(GreenNow);
  Serial.print("BlueNow: ");
  Serial.println(BlueNow);
#endif
  RedNow = RedNow +  0.2;
  GreenNow = GreenNow +  0.2;
  BlueNow = BlueNow +  0.2;
  if (RedNow > 255) RedNow = 255;
  if (GreenNow > 255) GreenNow = 255;
  if (BlueNow > 240) BlueNow = 240;
  if ((RedNow == 255) && (GreenNow == 255) && (BlueNow == 240)) {
#ifdef DEBUGDMXvalue
    Serial.print("w");
#endif

    if ((millis() - lastRefreshw) > REFRESHw) {
      trig();
      if (distance >= no_presence) {
        p++;
        if (p >= loop_time) {
          p = 0;
          state = 2;
        }
      }
      lastRefreshw = millis();
    }
  }
  if (state < 2) {
#ifdef DEBUGDMXvalue
    Serial.println("state < 2");
#endif
    dmxbuffer[1] = RedNow;
    dmxbuffer[2] = GreenNow;
    dmxbuffer[3] = BlueNow;
    copyDMXToOutput();
    delay(temp);
  }
  i = 0;
}

/*******************************************************/
void fade_seq() {
  if (cmd != 3) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0301);
    delay(temp_mp3);
    cmd = 3;
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
  mRedNow = mRedNow - 0.2;
  mGreenNow = mGreenNow - 0.2;
  mBlueNow = mBlueNow - 0.2;
  if (mRedNow < 80) mRedNow = 80;
  if (mGreenNow < 50) mGreenNow = 50;
  if (mBlueNow < 0) mBlueNow = 0;
  if ((mRedNow == 80) && (mGreenNow == 50) && (mBlueNow == 0)) {
#ifdef DEBUGDMX
    Serial.println("((mRedNow == 80) && (mGreenNow == 50) && (mBlueNow == 0))");
#endif

    state = 0;
    h = 0;
  }

  dmxbuffer[1] = mRedNow;
  dmxbuffer[2] = mGreenNow;
  dmxbuffer[3] = mBlueNow;
  copyDMXToOutput();
  delay(temp);
  h = 0;
}

/*******************************************************/
void fade_red() {
#ifdef DEBUGDMX
  Serial.print("fade_red()");
  Serial.print(" /dmx_red:");
  Serial.print(dmx_red);
  Serial.print(" /dmx_blue:");
  Serial.print(dmx_blue);
  Serial.print(" /dmx_green:");
  Serial.println(dmx_green);
#endif
  if (cmd != 4) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0401);
    delay(temp_mp3);
    cmd = 4;
  }
  if (dmx_red < 255)  dmx_red = dmx_red +  0.1;
  if (dmx_red > 255)  dmx_red = dmx_red -  0.1;
  if (dmx_green > 0)   dmx_green = dmx_green - 0.1;
  if (dmx_blue > 0)  dmx_blue = dmx_blue -  0.1;

  if (dmx_red >= 255) dmx_red = 255;
  if (dmx_green <= 0) dmx_green = 0;
  if (dmx_blue <= 0) dmx_blue = 0;


  dmxbuffer[1] = dmx_red;
  dmxbuffer[2] = dmx_green;
  dmxbuffer[3] = dmx_blue;
  copyDMXToOutput();
  delay(temp);
  k = 0;
}

/*******************************************************/
void fade_pink() {
#ifdef DEBUGDMX
  Serial.print("fade_pink()");
  Serial.print(" /dmx_red:");
  Serial.print(dmx_red);
  Serial.print(" /dmx_blue:");
  Serial.print(dmx_blue);
  Serial.print(" /dmx_green:");
  Serial.print(dmx_green);
#endif

  if (cmd != 5) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0501);
    delay(temp_mp3);
    cmd = 5;
  }

  if (dmx_red < 255)  dmx_red = dmx_red +  0.1;
  if (dmx_red > 255)  dmx_red = dmx_red -  0.1;
  if (dmx_green > 0)   dmx_green = dmx_green - 0.1;
  if (dmx_blue < 255)  dmx_blue = dmx_blue +  0.1;
  if (dmx_blue > 255)  dmx_blue = dmx_blue -  0.1;

  if (dmx_red >= 255 ) {
    jRedNow = 0;
    Serial.println("dmx_red >= 255");
  }
  if (dmx_green <= 0) {
    jGreenNow = 0;
    Serial.println("dmx_green <= 0");
  }
  if (dmx_blue >= 255 ) {
    jBlueNow = 0;
    Serial.println("dmx_blue >= 255");
  }
  dmxbuffer[1] = dmx_red;
  dmxbuffer[2] = dmx_green;
  dmxbuffer[3] = dmx_blue;
  copyDMXToOutput();
  delay(temp);
  j = 0;
}

/*******************************************************/
void fade_pink_red() {
#ifdef DEBUGDMX
  Serial.println("fade_pink_red()");
#endif

  if (cmd != 6) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0601);
    delay(temp_mp3);
    cmd = 6;
  }

  if (pink_red == 0) {
#ifdef DEBUGDMX
    Serial.println("pink_red = 0");
#endif

    if (touch2 > lRedNow)  lRedNow = lRedNow +  0.1;
    if (touch2 < lRedNow)  lRedNow = lRedNow -  0.1;
    lGreenNow = 0;
    lBlueNow = lBlueNow -  0.1;
    if (lRedNow > touch2) lRedNow = touch2;
    if (lBlueNow < 0) lBlueNow = 0;

    if ((lRedNow == touch2) && (lBlueNow == 0)) {
      o++;
      if (o >= loop_time) {
        o = 0;
        pink_red = 1;

        lRedNow = 0;
        lGreenNow = 0;
        lBlueNow = 0;
      }
    }
  }
  else if (pink_red == 1) {
#ifdef DEBUGDMX
    Serial.println("pink_red = 1");
#endif
#ifdef DEBUGDMXvalue
    Serial.print("lRedNow: ");
    Serial.println(lRedNow);
    Serial.print("lGreenNow: ");
    Serial.println(lGreenNow);
    Serial.print("lBlueNow: ");
    Serial.println(lBlueNow);
#endif
    if (touch1 > lRedNow)  lRedNow = lRedNow +  0.1;
    if (touch1 < lRedNow)  lRedNow = lRedNow -  0.1;
    lGreenNow = 0;
    if (touch1 > lBlueNow)  lBlueNow = lBlueNow +  0.1;
    if (touch1 < lBlueNow)  lBlueNow = lBlueNow -  0.1;

    if (lRedNow > touch2) lRedNow = touch1;
    if (lBlueNow > touch2) lBlueNow = touch1;

    if ((lRedNow == touch1) && (lBlueNow == touch1)) {
#ifdef DEBUGDMX
      Serial.println("((lRedNow == 100) && (lBlueNow == 255))");
#endif
      o++;
      if (o >= loop_time) {
        o = 0;
        pink_red = 0;

        //        lRedNow = 0;
        //        lGreenNow = 0;
        //        lBlueNow = 0;
      }
    }
  }

  dmxbuffer[1] = lRedNow;
  dmxbuffer[2] = lGreenNow;
  dmxbuffer[3] = lBlueNow;
  copyDMXToOutput();
  delay(temp);
  l = 0;
}

