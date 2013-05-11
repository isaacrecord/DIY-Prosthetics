/*
See the fritzing sketch for wiring instructions.
Speaker will be really loud and annoying. 
Place it face down on a surface.
*/

int sensorPin = 0;
int piezoPin = 9;

int val = 0;

void setup() {
  pinMode(piezoPin, OUTPUT);
}

void loop() {
  digitalWrite(piezoPin, LOW);
  val = analogRead(sensorPin);
  val = val/2;

  for( int i=0; i<500; i++ ) {  // play it for 50 cycles
    digitalWrite(piezoPin, HIGH);
    delayMicroseconds(val);
    digitalWrite(piezoPin, LOW);
    delayMicroseconds(val);
  }
}
