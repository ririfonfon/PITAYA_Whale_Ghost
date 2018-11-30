/*******************************************************/
void fade_to() {
#ifdef DEBUGDMX
  Serial.print("fade_to()");
  Serial.print(" /dmx_red:");
  Serial.print(dmx_red);
  Serial.print(" /dmx_green:");
  Serial.print(dmx_green);
  Serial.print(" /dmx_blue:");
  Serial.println(dmx_blue);
#endif


  if (dmx_red != 200 && dmx_green != 150 && dmx_blue != 0 ) {
    Serial.print(" != ");
    state = 6;
  }
  if (dmx_blue == 200 && dmx_green == 150 && dmx_blue == 0) {
    state = 0;
  }


  if (cmd != 6) {
    sendCommand(CMD_FOLDER_CYCLE, 0x0601);
    delay(temp_mp3);
    cmd = 6;
  }

  if (dmx_red < 200)  dmx_red = dmx_red +  0.2;
  if (dmx_red > 200)  dmx_red = dmx_red -  0.2;
  if (dmx_green < 150)   dmx_green = dmx_green + 0.2;
  if (dmx_green > 150)   dmx_green = dmx_green - 0.2;
  if (dmx_blue > 0)  dmx_blue = dmx_blue -  0.2;

  if (dmx_red == 200) dmx_red = 200;
  if (dmx_green == 150) dmx_green = 150;
  if (dmx_blue <= 0) dmx_blue = 0;

  dmxbuffer[1] = dmx_red;
  dmxbuffer[2] = dmx_green;
  dmxbuffer[3] = dmx_blue;
  copyDMXToOutput();
  delay(temp);
}
