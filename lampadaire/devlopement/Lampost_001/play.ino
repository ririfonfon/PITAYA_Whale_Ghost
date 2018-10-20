void play_seq() {
#ifdef DEBUG
  Serial.println(">130");
#endif
  RedNow = 0;
  GreenNow = 0;
  BlueNow = 0;

  jRedNow = 0;
  jGreenNow = 0;
  jBlueNow = 0;

  kRedNow = 0;
  kGreenNow = 0;
  kBlueNow = 0;
  i = 0;
  dmxbuffer[1] = RedList[level];
  dmxbuffer[2] = GreenList[level];
  dmxbuffer[3] = BlueList[level];


  copyDMXToOutput();
  i = 0;

  level++;
  if (level > 20) level = 0;

  esp_task_wdt_feed();
  vTaskDelay(100);
}
