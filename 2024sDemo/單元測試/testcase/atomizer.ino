int  atomizerFlag=0;
int pwm3 = 6;

void atomizerSetup()
{
  pinMode(pwm3,OUTPUT);
  

}
void atomizerActive()
{
  atomizerFlag=atomizerFlag+1;
  atomizerFlag=atomizerFlag%2;

}

void atomizerCheck()
{
  if(atomizerFlag==1)
  {
    analogWrite(pwm3,1023);
  }
  else
  {

    analogWrite(pwm3,0);
  }
}

