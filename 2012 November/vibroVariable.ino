/*
You probably won't have a potentiometer, but Javed might. Ask him if you want to run this example.
See fritzing sketch for wiring instructions. 
 */

const int MAXVIB=180; // 180 is 3.6V if Vin is 5V (Arduino Uno)

const int analogInPin = A0;  
const int analogOutPin = 3; 

int sensorValue = 0;        
int outputValue = 0;       

void setup() {

  Serial.begin(9600); 
}

void loop() {
  sensorValue = analogRead(analogInPin);            
  outputValue = map(sensorValue, 0, 1023, 0, MAXVIB);  
  analogWrite(analogOutPin, outputValue);           

  // print the results to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t output = ");      
  Serial.println(outputValue);   

  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  
  delay(500);   

  analogWrite(analogOutPin, 0); 

  delay(500);  
}
