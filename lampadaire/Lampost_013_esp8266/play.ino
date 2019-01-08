void play_seq() {
#ifdef DEBUGDMX
  Serial.print("play_seq()");
  Serial.print(" /rouge:");
  Serial.print(rouge);
  Serial.print(" /vert:");
  Serial.print(vert);
  Serial.print(" /bleu:");
  Serial.println(bleu);
#endif
  if (cmd != 1) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0101);
    seq = 0;
    part = 0;
    delay(temp_mp3);
    cmd = 1;
  }

  if (cmd == 1) {
    if (part == 0) {
      dmxbuffer[1] = RList1[level];
      dmxbuffer[2] = GList1[level];
      dmxbuffer[3] = 0;
    }
    else if (part == 1) {
      dmxbuffer[1] = RList2[level];
      dmxbuffer[2] = GList2[level];
      dmxbuffer[3] = 0;
    }
    else if (part == 2) {
      dmxbuffer[1] = RList3[level];
      dmxbuffer[2] = GList3[level];
      dmxbuffer[3] = 0;
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
      rnd = 0;
      part = part + 1;
      if (part >= 3) {
        part = 0;
        cmd = 0;
      }
    }
  }
}

