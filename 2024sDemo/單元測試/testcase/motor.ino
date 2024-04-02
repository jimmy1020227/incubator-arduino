int IN1=8;
int IN2=9;
int pwm1 = 7;
int  motorFlag=0;



void motorSetup() {
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(pwm1,OUTPUT);
  
  
}
void motorActive()
{
  motorFlag=motorFlag+1;
  motorFlag=motorFlag%2;

}

void motorControl()
{
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(pwm1,300);//?????
  //delay(2000);
  //motorStop();

}
void motorStop(){
  analogWrite(pwm1,0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}



void motorCheck()
{
  if(motorFlag==1)
  {
      motorControl();
  }
  else
  {

    motorStop();
  }
}


