void play_seq() {
#ifdef DEBUGDMX
  Serial.println("no_presence");
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
    dmxbuffer[1] = (RedList1[level] * RedList1[level]) / 255;
    dmxbuffer[2] = (GreenList1[level] * GreenList1[level]) / 255;
    dmxbuffer[3] = (BlueList1[level] * BlueList1[level]) / 255;
  }
  else if (part == 1) {
    RedNow = RedList2[level];
    GreenNow = GreenList2[level];
    BlueNow = BlueList2[level];
    dmxbuffer[1] = (RedList2[level] * RedList2[level]) / 255;
    dmxbuffer[2] = (GreenList2[level] * GreenList2[level]) / 255;
    dmxbuffer[3] = (BlueList2[level] * BlueList2[level]) / 255;
  }
  else if (part == 2) {
    RedNow = RedList3[level];
    GreenNow = GreenList3[level];
    BlueNow = BlueList3[level];
    dmxbuffer[1] = (RedList3[level] * RedList3[level]) / 255;
    dmxbuffer[2] = (GreenList3[level] * GreenList3[level]) / 255;
    dmxbuffer[3] = (BlueList3[level] * BlueList3[level]) / 255;
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

  level++;
  if (level > Cue) {
    level = 0;
    part = part + 1;
    if (part >= 3) part = 0;
  }

}

