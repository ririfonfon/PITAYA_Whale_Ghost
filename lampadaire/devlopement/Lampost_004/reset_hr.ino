void reset_hcsr04() {
#ifdef DEBUG
  Serial.println("reset hcsr04");
#endif
  pinMode(echoPin, OUTPUT);
  digitalWrite(echoPin, LOW);
  delay(100);
  pinMode(echoPin, INPUT);
}

