void play_seq() {
#ifdef DEBUGDMX
  Serial.print("play_seq()");
  Serial.print(" /dmx_red:");
  Serial.print(dmx_red);
  Serial.print(" /dmx_green:");
  Serial.print(dmx_green);
  Serial.print(" /dmx_blue:");
  Serial.println(dmx_blue);
#endif
  if (cmd != 1) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0101);
    delay(temp_mp3);
    cmd = 1;
  }
  if (part == 0) {
    dmxbuffer[1] = RedList1[level];
    dmxbuffer[2] = GreenList1[level];
    dmxbuffer[3] = BlueList1[level];
  }
  else if (part == 1) {
    dmxbuffer[1] = RedList2[level];
    dmxbuffer[2] = GreenList2[level];
    dmxbuffer[3] = BlueList2[level];
  }
  else if (part == 2) {
    dmxbuffer[1] = RedList3[level];
    dmxbuffer[2] = GreenList3[level];
    dmxbuffer[3] = BlueList3[level];
  }
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

