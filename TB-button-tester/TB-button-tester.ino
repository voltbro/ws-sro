/*
  Turtlebro Button tester for A13 GPIO  
*/

const int buttonPin = A13;     // the number of the pushbutton pin
const int ledPin = A12;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.println(F("Test of Button"));
}

void loop() {
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    Serial.println("True");
    digitalWrite(ledPin, HIGH);
    delay(100);
  } else {
    // turn LED off:
    Serial.println("False");
    digitalWrite(ledPin, LOW);
    delay(100);
  }
}
