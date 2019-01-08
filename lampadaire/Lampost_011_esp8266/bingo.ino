
/*******************************************************/
void bingo_chase() {
#ifdef DEBUGDMX
  Serial.print("bingo_chase()");
  Serial.print(" /rouge:");
  Serial.print(rouge);
  Serial.print(" /vert:");
  Serial.print(vert);
  Serial.print(" /bleu:");
  Serial.println(bleu);
#endif
  if (cmd != 7) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0701);
    delay(1000);
    cmd = 7;
  }
  bi++;
  if (bi >= loop_time_bingo) {
    dmxbuffer[1] = random(255);
    dmxbuffer[2] = random(255);
    dmxbuffer[3] = random(255);
    copyDMXToOutput();
    delay(temp);
    bi = 0;
  }
  if ((millis() - lastbingo) > REFRESHbingo) {
    state = 6;
  }
}
