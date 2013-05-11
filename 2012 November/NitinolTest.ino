const int nitinol=3;

void setup() {
  pinMode(nitinol, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Turning nitinol on");
  analogWrite(nitinol,191);
  delay(5000);
  Serial.println("Turning nitinol off");
  analogWrite(nitinol,0);
  delay(10000);
}

