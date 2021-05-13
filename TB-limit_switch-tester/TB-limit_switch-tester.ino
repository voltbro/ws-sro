/*
  Turtlebro limit_switch tester for A13 GPIO  
*/

const int limit_switchPin = A13;     
const int ledPin = A12;

// variables will change:
int limit_switchState = 0;         

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(limit_switchPin, INPUT);
  Serial.println(F("Test of limit_switch"));
}

void loop() {
  
  // read the state of the limit_switch value:
  limit_switchState = digitalRead(limit_switchPin);

  // check if the limit_switch is pressed. If it is, the limit_switch is HIGH:
  if (limit_switchState == HIGH) {
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
