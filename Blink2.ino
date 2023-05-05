
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  int sensorValue = 0;
  sensorValue = analogRead(A0);
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(sensorValue);                       // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(sensorValue);                       // wait for a second
  Serial.println(sensorValue);
  delay(1);
  
}
