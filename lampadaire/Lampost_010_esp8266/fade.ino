void fade_white() {
#ifdef DEBUGDMXvalue
  Serial.println("fade_white()");
  Serial.print(" /dmx_red:");
  Serial.print(dmx_red);
  Serial.print(" /dmx_green:");
  Serial.print(dmx_green);
  Serial.print(" /dmx_blue:");
  Serial.println(dmx_blue);
#endif

  if (cmd != 2) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0201);
    delay(temp_mp3);
    cmd = 2;
  }

  dmx_red = dmx_red +  0.2;
  dmx_green = dmx_green +  0.2;
  dmx_blue = dmx_blue +  0.2;
  if (dmx_red > 255) dmx_red = 255;
  if (dmx_green > 255) dmx_green = 255;
  if (dmx_blue > 240) dmx_blue = 240;
  if (dmx_blue == 255 && dmx_green == 255 && dmx_blue == 240) {
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
    dmxbuffer[1] = dmx_red;
    dmxbuffer[2] = dmx_blue;
    dmxbuffer[3] = dmx_blue;
    copyDMXToOutput();
    delay(temp);
  }
  i = 0;
}

/*******************************************************/
void fade_seq() {
#ifdef DEBUGDMXvalue
  Serial.print("fade_seq()");
  Serial.print(" /dmx_red:");
  Serial.print(dmx_red);
  Serial.print(" /dmx_green:");
  Serial.print(dmx_green);
  Serial.print(" /dmx_blue:");
  Serial.println(dmx_blue);
#endif
  if (cmd != 3) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0301);
    delay(temp_mp3);
    cmd = 3;
  }

  dmx_red = dmx_red - 0.2;
  dmx_green = dmx_green - 0.2;
  dmx_blue = dmx_blue - 0.2;
  if (dmx_red < 80) dmx_red = 80;
  if (dmx_green < 50) dmx_green = 50;
  if (dmx_blue < 0) dmx_blue = 0;
  if (dmx_red == 80 && dmx_green == 50 && dmx_blue == 0) {
    state = 0;
    h = 0;
  }

  dmxbuffer[1] = dmx_red;
  dmxbuffer[2] = dmx_green;
  dmxbuffer[3] = dmx_blue;
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
  Serial.print(" /dmx_green:");
  Serial.print(dmx_green);
  Serial.print(" /dmx_blue:");
  Serial.println(dmx_blue);
#endif
  if (cmd != 4) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0401);
    delay(temp_mp3);
    cmd = 4;
  }
  if (dmx_red < 255)  dmx_red = dmx_red +  0.2;
  if (dmx_red > 255)  dmx_red = dmx_red -  0.2;
  if (dmx_green > 0)   dmx_green = dmx_green - 0.2;
  if (dmx_blue > 0)  dmx_blue = dmx_blue -  0.2;

  if (dmx_red >= 255) dmx_red = 255;
  if (dmx_green <= 0) dmx_green = 0;
  if (dmx_blue <= 0) dmx_blue = 0;


  dmxbuffer[1] = dmx_red;
  dmxbuffer[2] = dmx_green;
  dmxbuffer[3] = dmx_blue;
  copyDMXToOutput();
  delay(temp);
  l = 0;
}

/*******************************************************/
void fade_pink() {
#ifdef DEBUGDMX
  Serial.print("fade_pink()");
  Serial.print(" /dmx_red:");
  Serial.print(dmx_red);
  Serial.print(" /dmx_green:");
  Serial.print(dmx_green);
  Serial.print(" /dmx_blue:");
  Serial.println(dmx_blue);
#endif

  if (cmd != 5) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0501);
    delay(temp_mp3);
    cmd = 5;
  }

  if (dmx_red < 255)  dmx_red = dmx_red +  0.2;
  if (dmx_red > 255)  dmx_red = dmx_red -  0.2;
  if (dmx_green > 0)   dmx_green = dmx_green - 0.2;
  if (dmx_blue < 255)  dmx_blue = dmx_blue +  0.2;
  if (dmx_blue > 255)  dmx_blue = dmx_blue -  0.2;

  if (dmx_red >= 255 ) {
    dmx_red = 255;
  }
  if (dmx_green <= 0) {
    dmx_green = 0;
  }
  if (dmx_blue >= 255 ) {
    dmx_blue = 255;
  }
  dmxbuffer[1] = dmx_red;
  dmxbuffer[2] = dmx_green;
  dmxbuffer[3] = dmx_blue;
  copyDMXToOutput();
  delay(temp);
  j = 0;
  k = 0;
}

/*******************************************************/
void fade_pink_red() {
#ifdef DEBUGDMX
  Serial.println("fade_pink_red()");
#endif

}

