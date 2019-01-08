void reset_hcsr04() {
#ifdef DEBUGSR
  Serial.println("reset hcsr04");
#endif
  pinMode(echoPin, OUTPUT);
  digitalWrite(echoPin, LOW);
  delay(100);
  pinMode(echoPin, INPUT);
}

