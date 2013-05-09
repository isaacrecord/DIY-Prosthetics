/* Generic Speaker Output
For circuit instructions please see workshop handout
*/

void setup() {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);
}

void loop() {
  // read the sensor:
  int sensorReading = analogRead(A0);
  // print the sensor reading so you know its range
  Serial.println(sensorReading);
  // Sets a loop so that it only plays a tone if there is a sensor reading
  // Over 100 (what 100 is is dependant on the sensor)
  // Change the number if you want to make the speaker start sooner or later
  if (sensorReading > 100){
  // This maps the sensor range to an inverse of the delay between beeps
  // So as the object gets closer, hotter, etc the beeps happen more frequently
  int distanceBeep = map(sensorReading, 100, 700, 350, 1);

  // play the sound - the first number is the output pin for the speaker
  // The seond number is the tone, and the last number is the duration
  // of the beep
  tone(9, 500, 30);
  delay(distanceBeep);
  }
  
  // This just makes sure that there is no sound from the speaker
  // if the sensor range is under 100
  else {
    noTone(9);
  }
}
