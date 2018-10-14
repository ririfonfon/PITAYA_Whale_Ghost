void copyDMXToOutput(void) {
  xSemaphoreTake( ESP32DMX.lxDataLock, portMAX_DELAY );
  for (int i = 1; i < DMX_MAX_FRAME; i++) {
    ESP32DMX.setSlot(i , dmxbuffer[i]);
  }
  xSemaphoreGive( ESP32DMX.lxDataLock );
  yield();
}


