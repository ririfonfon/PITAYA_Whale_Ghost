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


  if (ro != 20 && ve != 14 && bl != 0 ) {
    state = 6;
  }
  if ( ro == 20 && ve == 14 && bl == 0) {
    to++;
    if (to >= 800) {
      to = 0;
      state = 9;
    }
  }

  if (cmd != 6) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0601);
    delay(temp_mp3);
    cmd = 6;
  }

  if (rouge < 20)  rouge = rouge +  0.2;
  if (rouge > 20)  rouge = rouge -  0.2;
  if (vert < 15)   vert = vert + 0.2;
  if (vert > 15)   vert = vert - 0.2;
  if (bleu > 0)  bleu = bleu -  0.2;

  if (19 < rouge < 20) rouge = 20;
  if (vert == 15) vert = 15;
  if (bleu <= 0) bleu = 0;

  dmxbuffer[1] = rouge;
  dmxbuffer[2] = vert;
  dmxbuffer[3] = bleu;
  copyDMXToOutput();
  delay(temp);
}
