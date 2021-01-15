/*
  Turtlebro Blink tester for A12 GPIO  
*/
  
void setup() {
  pinMode(A12, OUTPUT);
}


void loop() {
  digitalWrite(A12, HIGH);   
  delay(1000);                       
  digitalWrite(A12, LOW);    
  delay(1000);                       
}
