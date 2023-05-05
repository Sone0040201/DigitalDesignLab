void setup() {
  //pinMode(13, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int sensorRead = 0;
  sensorRead = analogRead(A5);//40~160
  Serial.println(sensorRead);
  if(sensorRead<40)sensorRead=40;
  else if(sensorRead>160)sensorRead=160;
  int lightblink = map(sensorRead,40,160,0,255);
  analogWrite(3,lightblink);
  delay(1);
}
