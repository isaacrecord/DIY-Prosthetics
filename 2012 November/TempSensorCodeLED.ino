/* Temperture Sensor
For circuit instructions please see workshop handout
*/

int temperturePin = A0; // analog pin
float tempread = 0, tempc = 0,tempf=0; // temperature variables
int i;
int blueLEDpin = 9;          // connect Blue LED to pin 09 (PWM pin)
int greenLEDpin = 10;          // connect Green LED to pin 10 (PWM pin)
int redLEDpin = 11;          // connect Red LED to pin 11 (PWM pin)
int LEDbrightness;        // 

void setup()
{
  Serial.begin(9600); // start serial communication
}

void loop()
{
  
  

  
  tempread = analogRead(temperturePin); 
  tempc = (5 * tempread * 100.0) / 1024.0;


tempf = (tempc * 9)/ 5 + 32; // converts to fahrenheit

Serial.print(tempc,DEC);
Serial.print(" Celsius, ");

Serial.print(tempf,DEC);
Serial.println(" fahrenheit -> ");


  // The LEDs change colour depending on the range of temperature
  // We have set the range for the temperature reading from -10 degrees celsius
  // to 100 degrees celcius - you can change the ranges by changing the numbers
  // in the "if", "else" and LEDbrightness = map(tempc, X, X, 0, 255) for each loop
  // Now we convert it into 3 ranges that move from Blue to Green to Red
  // This gives us a better sense of how warm the environment is
  if (tempc >= -10 && tempc <= 20) { // For the colder temperature readings
    LEDbrightness = map(tempc, -10, 20, 0, 255); 
      analogWrite(blueLEDpin, LEDbrightness);
      analogWrite(greenLEDpin, 0); // Need to make sure the other
      analogWrite(redLEDpin, 0);   // two LEDs are off
  } else if (tempc > 20 && tempc <= 50) { // The range of heat from 20 degrees to 50 degrees
 
    LEDbrightness = map(tempc, 20, 50, 0, 255);
      analogWrite(greenLEDpin, LEDbrightness);
      analogWrite(redLEDpin, 0);   // Need to make sure the other
      analogWrite(blueLEDpin, 0);  // two LEDs are off

  } else { // For the hottest readings    
     LEDbrightness = map(tempc, 50, 100, 0, 255);
       analogWrite(redLEDpin, LEDbrightness);
       analogWrite(greenLEDpin, 0); // Need to make sure the other
       analogWrite(blueLEDpin, 0);  // two LEDs are off
  }

delay(1000); // delay before loop
}
