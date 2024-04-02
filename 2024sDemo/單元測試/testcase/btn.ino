int btnflag=0;
int btnpin=4;

void btnSetup() {
  
  pinMode(btnpin, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}
void btnActive()
{
  btnflag=btnflag+1;
  btnflag=btnflag%2;
}
void btnCheck()
{
  if(btnflag==1)
  {
    int sensorVal = digitalRead(btnpin);
    //Serial.println(sensorVal);
    if (sensorVal == HIGH) {
      digitalWrite(13, LOW);
    } else {
      digitalWrite(13, HIGH);
      
    }
  }
 
}