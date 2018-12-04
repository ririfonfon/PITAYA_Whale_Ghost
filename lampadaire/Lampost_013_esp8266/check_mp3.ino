void check_mp3() {
  char c = ' ';

  // If there a char on Serial call sendMP3Command to sendCommand
  if ( Serial.available() )
  {
    c = Serial.read();
    sendMP3Command(c);
  }

  // Check for the answer.
  if (mp3.available())
  {
    char c = ' ';

    // If there a char on Serial call sendMP3Command to sendCommand
    if ( Serial.available() )
    {
      c = Serial.read();
      sendMP3Command(c);
    }

    // Check for the answer.
    if (mp3.available())
    {
#ifdef DEBUGMP3
      Serial.print("decodeMP3Answer():");
      Serial.println(decodeMP3Answer());
#endif
    }
  }
}

