int btnflag=0;
int btnpin=4;

void setup() {
  Serial.begin(9600);
  pinMode(btnpin, INPUT_PULLUP);

  pinMode(13, OUTPUT);
}

void loop() {
  int sensorVal = digitalRead(btnpin);
  Serial.println(sensorVal);
  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
    btnflag=btnflag+1;
    btnflag=btnflag%2;
    delay(500);
  }
}
