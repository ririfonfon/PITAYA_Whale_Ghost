void trig() {
  if (digitalRead(trigPin) == HIGH) { //si le signal est à l'état haut
    distance = presence;
  }
  if (digitalRead(trigPin) == LOW) { //si le signal est à l'état bas
    distance = no_presence;
  }


#ifdef DEBUGSR
  // Prints the distance on the Serial Monitor
  Serial.print("distance:");
  Serial.print(distance);
  Serial.print(" state: ");
  Serial.print(state);
  Serial.print(" cmd: ");
  Serial.println(cmd);

#endif
}

