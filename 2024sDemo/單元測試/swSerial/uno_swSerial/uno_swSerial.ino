#include <SoftwareSerial.h>

#define rxPin 3
#define txPin 2

SoftwareSerial mySerial(rxPin, txPin);

void setup()  {
    // Define pin modes for TX and RX
    //pinMode(rxPin, INPUT);
    //pinMode(txPin, OUTPUT);
    
    // Set the baud rate for the SoftwareSerial object
    mySerial.begin(9600);
    Serial.begin(9600);
    Serial.println("setup");
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
void loop() {
    swSwrialReadCommand();
}
