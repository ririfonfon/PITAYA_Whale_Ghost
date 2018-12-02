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

  rouge = rouge +  0.2;
  vert = vert +  0.2;
  bleu = bleu +  0.2;
  if (rouge > 255) rouge = 255;
  if (vert > 255) vert = 255;
  if (bleu > 240) bleu = 240;
  if (ro == 255 && ve == 240 && bl == 240) {
#ifdef DEBUGDMXvalue
    Serial.print("w");
#endif

    if ((millis() - lastRefreshw) > REFRESHw) {
      trig();
      if (distance >= no_presence) {
        p++;
        if (p >= loop_time) {
          p = 0;
          state = 2;
        }
      }
      lastRefreshw = millis();
    }
  }
  if (state < 2) {
#ifdef DEBUGDMXvalue
    Serial.println("state < 2");
#endif
    dmxbuffer[1] = rouge;
    dmxbuffer[2] = bleu;
    dmxbuffer[3] = bleu;
    copyDMXToOutput();
    delay(temp);
  }
  i = 0;
}

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

/*******************************************************/
void fade_rouge() {
#ifdef DEBUGDMX
  Serial.print("fade_rouge()");
  Serial.print(" /rouge:");
  Serial.print(rouge);
  Serial.print(" /vert:");
  Serial.print(vert);
  Serial.print(" /bleu:");
  Serial.println(bleu);
#endif
  if (cmd != 4) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0401);
    delay(temp_mp3);
    cmd = 4;
  }
  if (rouge < 255)  rouge = rouge +  0.2;
  if (rouge > 255)  rouge = rouge -  0.2;
  if (vert > 0)   vert = vert - 0.2;
  if (bleu > 0)  bleu = bleu -  0.2;

  if (rouge >= 254) {
    rouge = 255;
    bingo++;
  }
  if (vert <= 0) vert = 0;
  if (bleu <= 0) bleu = 0;


  dmxbuffer[1] = rouge;
  dmxbuffer[2] = vert;
  dmxbuffer[3] = bleu;
  copyDMXToOutput();
  delay(temp);
  l = 0;
  if (bingo == bingo_win) {
    lastbingo = millis();
    state = 20;
    bingo_chase();
  }
}

/*******************************************************/
void fade_pink() {
#ifdef DEBUGDMX
  Serial.print("fade_pink()");
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

  if (rouge < 255)  rouge = rouge +  0.2;
  if (rouge > 255)  rouge = rouge -  0.2;
  if (vert > 0)   vert = vert - 0.2;
  if (bleu < 255)  bleu = bleu +  0.2;
  if (bleu > 255)  bleu = bleu -  0.2;

  if (rouge >= 255 ) rouge = 255;
  if (vert <= 0) vert = 0;
  if (bleu >= 255 ) bleu = 255;
  if (rouge >= 254 && bleu >= 254) bingo++;

  dmxbuffer[1] = rouge;
  dmxbuffer[2] = vert;
  dmxbuffer[3] = bleu;
  copyDMXToOutput();

  delay(temp);
  j = 0;
  k = 0;
  if (bingo == bingo_win) {
    state = 20;
    lastbingo = millis();
    bingo_chase();
  }
}

