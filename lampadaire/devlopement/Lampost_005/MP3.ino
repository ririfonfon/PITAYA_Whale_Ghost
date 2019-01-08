void sendMP3Command(char c) {
  switch (c) {
    case '?':
    case 'h':
#ifdef DEBUGMP3
      Serial.println("HELP  ");
      Serial.println(" p = Play");
      Serial.println(" P = Pause");
      Serial.println(" > = Next");
      Serial.println(" < = Previous");
      Serial.println(" + = Volume UP");
      Serial.println(" - = Volume DOWN");
      Serial.println(" c = Query current file");
      Serial.println(" q = Query status");
      Serial.println(" v = Query volume");
      Serial.println(" x = Query folder count");
      Serial.println(" t = Query total file count");
      Serial.println(" 1 = Play folder 1");
      Serial.println(" 2 = Play folder 2");
      Serial.println(" 3 = Play folder 3");
      Serial.println(" 4 = Play folder 4");
      Serial.println(" 5 = Play folder 5");
      Serial.println(" S = Sleep");
      Serial.println(" W = Wake up");
      Serial.println(" r = Reset");
#endif
      break;


    case 'p':
#ifdef DEBUGMP3
      Serial.println("Play ");
#endif
      sendCommand(CMD_PLAY, 0);
      break;

    case 'P':
#ifdef DEBUGMP3
      Serial.println("Pause");
#endif
      sendCommand(CMD_PAUSE, 0);
      break;

    case '>':
#ifdef DEBUGMP3
      Serial.println("Next");
#endif
      sendCommand(CMD_NEXT_SONG, 0);
      sendCommand(CMD_PLAYING_N, 0x0000); // ask for the number of file is playing
      break;

    case '<':
#ifdef DEBUGMP3
      Serial.println("Previous");
#endif
      sendCommand(CMD_PREV_SONG, 0);
      sendCommand(CMD_PLAYING_N, 0x0000); // ask for the number of file is playing
      break;

    case '+':
#ifdef DEBUGMP3
      Serial.println("Volume Up");
#endif
      sendCommand(CMD_VOLUME_UP, 0);
      break;

    case '-':
#ifdef DEBUGMP3
      Serial.println("Volume Down");
#endif
      sendCommand(CMD_VOLUME_DOWN, 0);
      break;

    case 'c':
#ifdef DEBUGMP3
      Serial.println("Query current file");
#endif
      sendCommand(CMD_PLAYING_N, 0);
      break;

    case 'q':
#ifdef DEBUGMP3
      Serial.println("Query status");
#endif
      sendCommand(CMD_QUERY_STATUS, 0);
      break;

    case 'v':
#ifdef DEBUGMP3
      Serial.println("Query volume");
#endif
      sendCommand(CMD_QUERY_VOLUME, 0);
      break;

    case 'x':
#ifdef DEBUGMP3
      Serial.println("Query folder count");
#endif
      sendCommand(CMD_QUERY_FLDR_COUNT, 0);
      break;

    case 't':
#ifdef DEBUGMP3
      Serial.println("Query total file count");
#endif
      sendCommand(CMD_QUERY_TOT_TRACKS, 0);
      break;

    case '1':
#ifdef DEBUGMP3
      Serial.println("Play folder 1");
#endif
      sendCommand(CMD_FOLDER_CYCLE, 0x0101);
      break;

    case '2':
#ifdef DEBUGMP3
      Serial.println("Play folder 2");
#endif
      sendCommand(CMD_FOLDER_CYCLE, 0x0201);
      break;

    case '3':
#ifdef DEBUGMP3
      Serial.println("Play folder 3");
#endif
      sendCommand(CMD_FOLDER_CYCLE, 0x0301);
      break;

    case '4':
#ifdef DEBUGMP3
      Serial.println("Play folder 4");
#endif
      sendCommand(CMD_FOLDER_CYCLE, 0x0401);
      break;

    case '5':
#ifdef DEBUGMP3
      Serial.println("Play folder 5");
#endif
      sendCommand(CMD_FOLDER_CYCLE, 0x0501);
      break;

    case '6':
#ifdef DEBUGMP3
      Serial.println("Play folder 6");
#endif
      sendCommand(CMD_FOLDER_CYCLE, 0x0601);
      break;

    case 'S':
#ifdef DEBUGMP3
      Serial.println("Sleep");
#endif
      sendCommand(CMD_SLEEP_MODE, 0x00);
      break;

    case 'W':
#ifdef DEBUGMP3
      Serial.println("Wake up");
#endif
      sendCommand(CMD_WAKE_UP, 0x00);
      break;

    case 'r':
#ifdef DEBUGMP3
      Serial.println("Reset");
#endif
      sendCommand(CMD_RESET, 0x00);
      break;

    case 's':
#ifdef DEBUGMP3
      Serial.println("Single");
#endif
      sendCommand(CMD_SET_SNGL_CYCL, 0x00);
      break;
  }
}



/********************************************************************************/
/*Function decodeMP3Answer: Decode MP3 answer.                                  */
/*Parameter:-void                                                               */
/*Return: The                                                  */

String decodeMP3Answer() {
  String decodedMP3Answer = "";

  decodedMP3Answer += sanswer();

  switch (ansbuf[3]) {
    case 0x3A:
      decodedMP3Answer += " -> Memory card inserted.";
      break;

    case 0x3D:
      decodedMP3Answer += " -> Completed play num " + String(ansbuf[6], DEC);
      break;

    case 0x40:
      decodedMP3Answer += " -> Error";
      break;

    case 0x41:
      decodedMP3Answer += " -> Data recived correctly. ";
      break;

    case 0x42:
      decodedMP3Answer += " -> Status playing: " + String(ansbuf[6], DEC);
      break;

    case 0x48:
      decodedMP3Answer += " -> File count: " + String(ansbuf[6], DEC);
      break;

    case 0x4C:
      decodedMP3Answer += " -> Playing: " + String(ansbuf[6], DEC);
      break;

    case 0x4E:
      decodedMP3Answer += " -> Folder file count: " + String(ansbuf[6], DEC);
      break;

    case 0x4F:
      decodedMP3Answer += " -> Folder count: " + String(ansbuf[6], DEC);
      break;
  }

  return decodedMP3Answer;
}






/********************************************************************************/
/*Function: Send command to the MP3                                         */
/*Parameter:-int8_t command                                                     */
/*Parameter:-int16_ dat  parameter for the command                              */

void sendCommand(int8_t command, int16_t dat)
{
  delay(20);
  Send_buf[0] = 0x7e;   //
  Send_buf[1] = 0xff;   //
  Send_buf[2] = 0x06;   // Len
  Send_buf[3] = command;//
  Send_buf[4] = 0x01;   // 0x00 NO, 0x01 feedback
  Send_buf[5] = (int8_t)(dat >> 8);  //datah
  Send_buf[6] = (int8_t)(dat);       //datal
  Send_buf[7] = 0xef;   //
#ifdef DEBUGMP3
  Serial.print("Sending: ");
#endif
  for (uint8_t i = 0; i < 8; i++)
  {
    mp3.write(Send_buf[i]) ;

#ifdef DEBUGMP3
    Serial.print(sbyte2hex(Send_buf[i]));
#endif
  }
#ifdef DEBUGMP3
  Serial.println();
#endif
}



/********************************************************************************/
/*Function: sbyte2hex. Returns a byte data in HEX format.                 */
/*Parameter:- uint8_t b. Byte to convert to HEX.                                */
/*Return: String                                                                */


String sbyte2hex(uint8_t b)
{
  String shex;

  shex = "0X";

  if (b < 16) shex += "0";
  shex += String(b, HEX);
  shex += " ";
  return shex;
}




/********************************************************************************/
/*Function: sanswer. Returns a String answer from mp3 UART module.          */
/*Parameter:- uint8_t b. void.                                                  */
/*Return: String. If the answer is well formated answer.                        */

String sanswer(void)
{
  uint8_t i = 0;
  String mp3answer = "";

  // Get only 10 Bytes
  while (mp3.available() && (i < 10))
  {
    uint8_t b = mp3.read();
    ansbuf[i] = b;
    i++;

    mp3answer += sbyte2hex(b);
  }

  // if the answer format is correct.
  if ((ansbuf[0] == 0x7E) && (ansbuf[9] == 0xEF))
  {
    return mp3answer;
  }

  return "???: " + mp3answer;
}
