int IN1=8;
int IN2=9;
int pwm1 = 7;



//------------------------
void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(pwm1,OUTPUT);
 
  
}
//--------------------------
void loop() {    
  STOP();
  delay(3000);
 
  control2();

}
//---------------------------
void STOP(){
  analogWrite(pwm1,0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}


void control2()
{
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(pwm1,255);//?????
  delay(5000);

}
