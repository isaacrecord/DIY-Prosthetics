int button = 0; // Creates the variable and sets the arduino pin (0) for the action button
int buzzer = 13; // Creates the variable and sets the arduino pin (13) for the buzzer

int buttonState = 0; // Variable for understanding the state of the button

void setup() {
  pinMode (button, INPUT); // Delcares the button as the inut method
  pinMode (buzzer, OUTPUT); // Declare the buzzer 
  Serial.begin(9600); // start the serial communication (testing window) 
}

void loop() {
  
  buttonState = digitalRead(button); // Reads the state of the button
  
  if (buttonState == LOW){           // if the button is pressed
    digitalWrite(buzzer, HIGH);      // Start the buzzer
  }
  else {                             // if the buzzer is not pressed
    digitalWrite(buzzer, LOW);      // Leave the buzzer off
  }
  
Serial.print(buttonState);          // Just a test to make sure the buzzer and button
Serial.print(" Buzzer: ");          // Are working
Serial.println(buzzer);
}
