/* Photocell Color Range *adapted from AdaFruit - www.ladyada.net/learn/sensors/cds.html*
 
See workshop documentation for wiring instructions*/
 
int photocellPin = A0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider
int blueLEDpin = 9;          // connect Blue LED to pin 09 (PWM pin)
int greenLEDpin = 10;          // connect Green LED to pin 10 (PWM pin)
int redLEDpin = 11;          // connect Red LED to pin 11 (PWM pin)
int LEDbrightness;        // 

void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);   
}
 
void loop(void) {
  photocellReading = analogRead(photocellPin);  
 
  Serial.print("Analog reading = ");
  Serial.println(photocellReading);     // the raw analog reading
 
  // LED gets brighter the darker it is at the sensor
  // that means we have to -invert- the reading from 0-1023 back to 1023-0
  photocellReading = 1023 - photocellReading;
  // Now we convert it into 3 ranges that move from Blue to Red to Green
  // This gives us a better sense of how bright the environment is
  if (photocellReading <= 341) { // For the brightest light readings
    LEDbrightness = map(photocellReading, 0, 341, 0, 255); 
      analogWrite(blueLEDpin, LEDbrightness);
      analogWrite(greenLEDpin, 0); // Need to make sure the other
      analogWrite(redLEDpin, 0);   // two LEDs are off
  } else if (photocellReading > 341 && photocellReading <= 682) { // The middle range of brightness
    LEDbrightness = map(photocellReading, 342, 682, 0, 255);
      analogWrite(redLEDpin, LEDbrightness);
      analogWrite(greenLEDpin, 0); // Need to make sure the other
      analogWrite(blueLEDpin, 0);  // two LEDs are off
  } else { // For the darkest range
    LEDbrightness = map(photocellReading, 683, 1023, 0, 255);
      analogWrite(greenLEDpin, LEDbrightness);
      analogWrite(redLEDpin, 0);   // Need to make sure the other
      analogWrite(blueLEDpin, 0);  // two LEDs are off
  }
  delay(100);
}
