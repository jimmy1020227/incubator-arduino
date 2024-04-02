
int pwm3 = 6;
//------------------------
void setup() {
  Serial.begin(9600);
  
  pinMode(pwm3,OUTPUT);
  analogWrite(pwm3,250);
}
//--------------------------
void loop() {    
  
}
