/*******************************************************/
void fade_seq() {
#ifdef DEBUGDMX
  Serial.print("fade_seq()");
  Serial.print(" /rouge:");
  Serial.print(rouge);
  Serial.print(" /vert:");
  Serial.print(vert);
  Serial.print(" /bleu:");
  Serial.print(bleu);
  Serial.print(" /ro:");
  Serial.print(ro);
  Serial.print(" /ve:");
  Serial.print(ve);
  Serial.print(" /bl:");
  Serial.println(bl);
#endif
  if (cmd != 3) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0301);
    delay(temp_mp3);
    cmd = 3;
  }

  rouge = rouge - 0.2;
  vert = vert - 0.2;
  bleu = bleu - 0.2;
  if (rouge < 80) rouge = 80;
  if (vert < 50) vert = 50;
  if (bleu < 0) bleu = 0;
  if (ro == 80 && ve == 50 && bl == 0) {
    state = 0;
    h = 0;
  }

  dmxbuffer[1] = rouge;
  dmxbuffer[2] = vert;
  dmxbuffer[3] = bleu;
  copyDMXToOutput();
  delay(temp);
  h = 0;
}

