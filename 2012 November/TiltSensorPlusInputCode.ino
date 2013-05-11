/* This is the tilt sensor if statement for the Prosthetics Workshop
 * In this program you will paste in the necessary code for the input you
 * want to read from IN ADDITION to the Tilt Sensor
 *
 * Part of this code was adapted from the:
 * Better Debouncer
 * From
 * http://www.ladyada.net/learn/sensor/tilt.html
 */
 
int inPin = A5;         // the number of the TILT SENSOR input pin

/* This set of declared variables is for the Proximity Sensor
 * replace these variables if you are using a different input
 */
int sensorPin = A0; //analog pin 0
int blueLEDpin = 9;          // connect Blue LED to pin 09 (PWM pin)
int greenLEDpin = 10;          // connect Green LED to pin 10 (PWM pin)
int redLEDpin = 11;          // connect Red LED to pin 11 (PWM pin)
int LEDbrightness;        // 
// End ofProximity Sensor variables


int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin
 
// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 50;   // the debounce time, increase if the output flickers
 
void setup()
{
  pinMode(inPin, INPUT);
  Serial.begin(9600);
}
 
void loop()
{
  int switchstate;
  int distance = analogRead(sensorPin);
  Serial.println(distance);
  
  reading = digitalRead(inPin);
 
  // If the switch changed, due to bounce or pressing...
  if (reading != previous) {
    // reset the debouncing timer
    time = millis();
  } 
 
  if ((millis() - time) > debounce) {
     // whatever the switch is at, its been there for a long time
     // so lets settle on it!
     switchstate = reading;
 
    if (switchstate == HIGH){ //if Tilt Switch switch is "off"

      // sets the LED to off
      LEDbrightness = 0;
      analogWrite(blueLEDpin, LEDbrightness);
      analogWrite(greenLEDpin, LEDbrightness);
      analogWrite(redLEDpin, LEDbrightness);
    }
    
    else // if Tilt Switch is "on"
    {
      //just to slow down the output - remove if trying to catch an object passing by
      delay(100);
    
/* The code Below is the actions for the proximity sensor to be used
 * if the Tilt Sensor is "on" remove the code below if you want to use an
 * Input instead of the proximity sensor until the comment "End of Inserted Code"
 */
 
 
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
      
      // ********************** //
      /* END OF INSERTED CODE */
      // ********************** //
      
    }
  }

 
  // Save the last reading so we keep a running tally
  previous = reading;
}

