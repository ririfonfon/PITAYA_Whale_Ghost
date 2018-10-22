void play_seq() {
#ifdef DEBUGDMX
  Serial.println("no_presence");
#endif
  if (cmd != 1) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0101);
    delay(temp_mp3);
    cmd = 1;
  }
  RedNow = RedList[level];
  GreenNow = GreenList[level];
  BlueNow = BlueList[level];

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

  dmxbuffer[1] = (RedList[level] * RedList[level]) / 255;
  dmxbuffer[2] = (GreenList[level] * GreenList[level]) / 255;
  dmxbuffer[3] = (BlueList[level] * BlueList[level]) / 255;

  copyDMXToOutput();
  h = 0;

  level++;
  if (level > Cue) level = 0;

}

