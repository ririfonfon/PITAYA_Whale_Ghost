/*******************************************************/
void fade_to() {
#ifdef DEBUGDMX
  Serial.print("fade_to()");
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


  if (ro != 25 && ve != 20 && bl != 0 ) {
    state = 6;
  }
  if ( ro == 25 && ve == 20 && bl == 0) {
    to++;
    if (to >= 400) {
      to = 0;
      state = 9;
    }
  }

  if (cmd != 6) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0301);
    delay(temp_mp3);
    cmd = 6;
    dmxbuffer[1] = 255;
    dmxbuffer[2] = 255;
    dmxbuffer[3] = 255;
    copyDMXToOutput();
    delay(temp);
  }

  rouge = rouge -  0.1;
  vert = vert - 0.1;
  bleu = bleu -  0.1;

  if (rouge < 25) rouge = 25;
  if (vert < 20) vert = 20;
  if (bleu <= 0) bleu = 0;

  dmxbuffer[1] = rouge;
  dmxbuffer[2] = vert;
  dmxbuffer[3] = bleu;
  copyDMXToOutput();
  delay(temp);
}
