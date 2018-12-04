void fade_white() {
#ifdef DEBUGDMX
  Serial.print("fade_white()");
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

  if (cmd != 2) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0201);
    delay(temp_mp3);
    cmd = 2;
  }
  if (etat == 0) {
#ifdef DEBUGDMXvalue
    Serial.print("fade in w");
#endif
    rouge = rouge +  0.2;
    vert = vert +  0.2;
    bleu = bleu +  0.2;
    if (rouge > 255) rouge = 255;
    if (vert > 255) vert = 255;
    if (bleu > 240) bleu = 240;
  }

  if (ro == 255 && ve == 240 && bl == 240) {
    etat = 1;
  }
  if (etat == 1) {
#ifdef DEBUGDMXvalue
    Serial.print("fade out w");
#endif
    rouge = rouge -  0.2;
    vert = vert -  0.2;
    bleu = bleu -  0.2;
    if (rouge < 0) rouge = 0;
    if (vert < 0) vert = 0;
    if (bleu < 0) bleu = 0;
  }
  if (ro == 255 && ve == 240 && bl == 240) {
    etat = 1;
  }
  if (ro == 0 && ve == 0 && bl == 0) {
    etat = 0;
  }

  p++;
  if (p >= loop_time) {
    p = 0;
    state = 6;
  }

  dmxbuffer[1] = rouge;
  dmxbuffer[2] = bleu;
  dmxbuffer[3] = bleu;
  copyDMXToOutput();
  delay(temp);
}


/*******************************************************/
void fade_rouge() {
#ifdef DEBUGDMX
  Serial.print("fade_rouge()");
  Serial.print(" /etat:");
  Serial.print(etat);
  Serial.print(" /rouge:");
  Serial.print(rouge);
  Serial.print(" /vert:");
  Serial.print(vert);
  Serial.print(" /bleu:");
  Serial.println(bleu);
#endif
  if (cmd != 4) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0601);
    delay(temp_mp3);
    cmd = 4;
  }
  if (etat == 0) {
    if (rouge < 255)  rouge = rouge +  0.2;
    if (rouge > 255)  rouge = rouge -  0.2;
    if (vert > 0)   vert = vert - 0.2;
    if (bleu > 0)  bleu = bleu -  0.2;

    if (rouge >= 254) {
      rouge = 255;
      etat = 1;
    }
  }
  if (etat == 1) {
    if (rouge < 0)  rouge = rouge +  0.2;
    if (rouge > 0)  rouge = rouge -  0.2;
    if (vert > 0)   vert = vert - 0.2;
    if (bleu > 0)  bleu = bleu -  0.2;

    if (rouge <= 0) {
      rouge = 0;
      etat = 0;
    }
  }

  if (vert <= 0) vert = 0;
  if (bleu <= 0) bleu = 0;

  p++;
  if (p >= loop_time) {
    p = 0;
    state = 6;
  }

  dmxbuffer[1] = rouge;
  dmxbuffer[2] = vert;
  dmxbuffer[3] = bleu;
  copyDMXToOutput();
  delay(temp);
}

/*******************************************************/
void fade_pink() {
#ifdef DEBUGDMX
  Serial.print("fade_pink()");
  Serial.print(" /etat:");
  Serial.print(etat);
  Serial.print(" /rouge:");
  Serial.print(rouge);
  Serial.print(" /vert:");
  Serial.print(vert);
  Serial.print(" /bleu:");
  Serial.println(bleu);
#endif

  if (cmd != 5) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0501);
    delay(temp_mp3);
    cmd = 5;
  }
  if (etat == 0) {
    rouge = rouge +  0.2;
    vert = vert - 0.2;
    bleu = bleu +  0.2;


    if (rouge >= 255 ) rouge = 255;
    if (vert <= 0) vert = 0;
    if (bleu >= 255 ) bleu = 255;
    if (rouge >= 254 && bleu >= 254) etat = 1;
  }

  if (etat == 1) {
    if (rouge < 0)  rouge = rouge +  0.2;
    if (rouge > 0)  rouge = rouge -  0.2;
    if (vert > 0)   vert = vert - 0.2;
    if (bleu < 0)  bleu = bleu +  0.2;
    if (bleu > 0)  bleu = bleu -  0.2;

    if (rouge <= 0 ) rouge = 0;
    if (vert <= 0) vert = 0;
    if (bleu <= 0 ) bleu = 0;
    if (rouge <= 0 && bleu <= 0) etat = 0;
  }

  p++;
  if (p >= loop_time) {
    p = 0;
    state = 6;
  }

  dmxbuffer[1] = rouge;
  dmxbuffer[2] = vert;
  dmxbuffer[3] = bleu;
  copyDMXToOutput();
  delay(temp);
}

