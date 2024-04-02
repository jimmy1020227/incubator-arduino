

int swSerialFlag=0;

void swSerialsetup()  {
    // Define pin modes for TX and RX
    //pinMode(rxPin, INPUT);
    //pinMode(txPin, OUTPUT);
    
    // Set the baud rate for the SoftwareSerial object
    mySerial.begin(9600);
    //Serial.begin(9600);
    //Serial.println("setup");
}
void swSwrialReadCommand()
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
  }
}
void swSerialActive() 
{
  swSerialFlag=swSerialFlag+1;
  swSerialFlag=swSerialFlag%2;
}

void swSerialCheck()
{
  if(swSerialFlag==1)
  {
    swSwrialReadCommand();
  }
    
}
void swSerialWrite()
{
  mySerial.println("uno to esp8266");
}