void play_seq() {
#ifdef DEBUGDMX
  Serial.print("play_seq()");
  Serial.print(" /dmx_red:");
  Serial.print(dmx_red);
  Serial.print(" /dmx_blue:");
  Serial.print(dmx_blue);
  Serial.print(" /dmx_green:");
  Serial.println(dmx_green);
#endif
  if (cmd != 1) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0101);
    delay(temp_mp3);
    cmd = 1;
  }
  if (part == 0) {
    RedNow = RedList1[level];
    GreenNow = GreenList1[level];
    BlueNow = BlueList1[level];
    dmxbuffer[1] = RedList1[level];
    dmxbuffer[2] = GreenList1[level];
    dmxbuffer[3] = BlueList1[level];
  }
  else if (part == 1) {
    RedNow = RedList2[level];
    GreenNow = GreenList2[level];
    BlueNow = BlueList2[level];
    dmxbuffer[1] = RedList2[level];
    dmxbuffer[2] = GreenList2[level];
    dmxbuffer[3] = BlueList2[level];
  }
  else if (part == 2) {
    RedNow = RedList3[level];
    GreenNow = GreenList3[level];
    BlueNow = BlueList3[level];
    dmxbuffer[1] = RedList3[level];
    dmxbuffer[2] = GreenList3[level];
    dmxbuffer[3] = BlueList3[level];
  }

  jRedNow = 0;
  jGreenNow = 0;
  jBlueNow = 0;

  kRedNow = 0;
  kGreenNow = 0;
  kBlueNow = 0;

  lRedNow = 0;
  lGreenNow = 0;
  lBlueNow = 0;

  mRedNow = 255;
  mGreenNow = 255;
  mBlueNow = 240;

  pink_red = 0;

  copyDMXToOutput();
  h = 0;
  seq++;
  if (seq > loop_time_seq) {
    seq = 0;
    level++;
  }
  if (level > Cue) {
    level = 0;
    part = part + 1;
    if (part >= 3) part = 0;
  }

}

