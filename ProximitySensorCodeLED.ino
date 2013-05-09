/* Poximity Sensor
For circuit instructions please see workshop handout
*/

int sensorPin = A0; //analog pin 0
int blueLEDpin = 9;          // connect Blue LED to pin 09 (PWM pin)
int greenLEDpin = 10;          // connect Green LED to pin 10 (PWM pin)
int redLEDpin = 11;          // connect Red LED to pin 11 (PWM pin)
int LEDbrightness;        // 

void setup(){
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);
}

void loop(){
  int distance = analogRead(sensorPin);
  Serial.println(distance);

  //just to slow down the output - remove if trying to catch an object passing by
  delay(100);


  // The LEDs change colour depending on how far away the object is
  // You can change the ranges by changing the numbers
  // in the "if", "else" and LEDbrightness = map(distance, X, X, 0, 255) for each loop
  // Now we convert it into 3 ranges that move from Blue to Green to Red
  // This gives us a better sense of how close an object to the sensor
  if (distance >= 0 && distance <= 233) { // When the object is farthest away
    LEDbrightness = map(distance, 0, 233, 0, 255); 
      analogWrite(blueLEDpin, LEDbrightness);
      analogWrite(greenLEDpin, 0); // Need to make sure the other
      analogWrite(redLEDpin, 0);   // two LEDs are off
  } else if (distance > 234 && distance <= 468) { // The mid-range of distance
 
    LEDbrightness = map(distance, 234, 468, 0, 255);
      analogWrite(greenLEDpin, LEDbrightness);
      analogWrite(redLEDpin, 0);   // Need to make sure the other
      analogWrite(blueLEDpin, 0);  // two LEDs are off

  } else { // For the closest readings    
     LEDbrightness = map(distance, 469, 700, 0, 255);
       analogWrite(redLEDpin, LEDbrightness);
       analogWrite(greenLEDpin, 0); // Need to make sure the other
       analogWrite(blueLEDpin, 0);  // two LEDs are off
  }

}
