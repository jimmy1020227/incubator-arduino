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
    //snprintf (msg, MSG_BUFFER_SIZE, s);
    s.toCharArray(msg, MSG_BUFFER_SIZE);
    //Serial.print("Publish message: ");
    //Serial.println(msg);
    client.publish("outTopic", msg);
    
  }
}