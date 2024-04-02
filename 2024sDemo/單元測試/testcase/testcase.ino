
#include <SoftwareSerial.h>
#define rxPin 3
#define txPin 2

SoftwareSerial mySerial(rxPin, txPin);

void testcase_setup() {
  Serial.begin(9600);
  ledsetup();
  atomizerSetup();
  motorSetup();
  lcdSetup();
  btnSetup();
  wlsSetup();
  pirSetup();
  dhtSetup();
  swSerialsetup();
}

void handleCommand(int act)
{
  
      switch (act)
      {
      case 0:
        test();
        break;
      case 1:
        ledblink();
      break;
      case 2:
        atomizerActive();
      break;
      case 3:
        motorControl();
      break;
      case 4:
        motorStop();
      break;
      case 5:
        lcdActive();
      break;
      case 6:
        btnActive();
      break;
      case 7:
        pirActive();
      break;
      case 8:
        wlsActive();
      break;
      case 9:
        dhtActive();
      break;
      case 10:
        swSerialActive();
      break;
      case 11:
        ledblinkYellow();
      break;
      case 12:
        ledblinkWhite();
      break;
      case 13:
        ledTurnOff();
      break;
      case 101:
        Serial.println("test t char");
      break;
       case 14:
        swSerialWrite();
      break;
    }
    
   
}
//control from serial monitor
void readCommand()
{
  String s="";
  while(Serial.available())
  {
    char c = Serial.read();
    if(c!='\n')
    {
      
      s+=c;
    }
    delay(5);
  }

  if(s!="")
  {
    Serial.println(s);
    int Num=s.toInt();
    handleCommand(Num);
  }
  delay(5);
  pirCheck();
  btnCheck();
  wlsCheck();
  dhtCheck();
  atomizerCheck();
  swSerialCheck();
}
void swSerialReadCommand()
{
  String s="";
  while(mySerial.available())
  {
    char c = mySerial.read();
    if(c!='\n')
    {
      
      s+=c;
    }
    delay(5);
  }

  if(s!="")
  {
    Serial.println(s);
    int Num=s.toInt();
    handleCommand(Num);

  }
  delay(5);
  pirCheck();
  btnCheck();
  wlsCheck();
  dhtCheck();
  atomizerCheck();
  swSerialCheck();
}
void testcase_loop() {
  readCommand();
  swSerialReadCommand();
}
void test()
{
  for(int i=0 ;i<10;i++)
  {
    Serial.print(i);
    Serial.println("holle world");
    delay(1000);
  }
  delay(10000);
}