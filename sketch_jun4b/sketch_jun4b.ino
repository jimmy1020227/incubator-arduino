#include <Servo.h>
Servo a,b;
int t=50;
void setup() {
  // put your setup code here, to run once:
  // put your setup code here, to run once:
  a.attach(8);
  b.attach(9); 
  Serial.begin(9600);
  delay(1000);
  Serial.println(a.read());
  Serial.println(b.read());


}
String serialRead()
{
  String s="";
  while(Serial.available())
  {
    char c = Serial.read();
    if(c!='\n')
    {
        s=s+c;
    }
    delay(5);
  }
  if(s!="")
  {
      //b.write(s.toInt());
      //t=s.toInt();
  }
  return s;
}
void test1()
{
 for(int i=93 ; i<180 ; i+=2)
  {
      //serialRead();
      //delay(50);
      serialRead(); 
      b.write(i);
      Serial.print("i= ");
      Serial.println(i);
      delay(t);
      Serial.println(b.read());


  }
  for(int i=180 ; i>0 ; i-=2)
  {
      //serialRead();
      //delay(50);
      serialRead(); 
      b.write(i);
      Serial.print("i= ");
      Serial.println(i);
      delay(t);
      Serial.println(b.read());

  }
  for(int i=0 ; i<93 ; i+=2)
 {
    //serialRead();
    //delay(50);
    serialRead(); 
    b.write(i);
    Serial.print("i= ");
    Serial.println(i);
    delay(t);
    Serial.println(b.read());

 }

}
void test2()
{
 for(int i=93 ; i>0 ; i-=2)
 {
    //serialRead();
    //delay(50);
    serialRead(); 
    b.write(i);
    Serial.print("i= ");
    Serial.println(i);
    delay(t);
    Serial.println(b.read());

 }

  for(int i=0 ; i<93 ; i+=2)
 {
    //serialRead();
    //delay(50);
    serialRead(); 
    b.write(i);
    Serial.print("i= ");
    Serial.println(i);
    delay(t);
    Serial.println(b.read());

 }

}

void test3(int a)
{
  int p =b.read();
  if(p<a)
  {
    for(int i=p ; i<a; i+=2)
    {
    //serialRead();
    //delay(50);
    //serialRead(); 
    b.write(i);
    //Serial.print("i= ");
    //Serial.println(i);
    delay(t);
    Serial.println(b.read());

    }
  }
  else
  {
    for(int i=p ; i>a ; i-=2)
    {
    //serialRead();
    //delay(50);
    //serialRead(); 
    b.write(i);
    //Serial.print("i= ");
    //Serial.println(i);
    delay(t);
    Serial.println(b.read());

    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //test1();   
  //test2();    
  String  rtn = serialRead(); 
  if(rtn !="")
  {
    test3(rtn.toInt());   
  }
 

}
