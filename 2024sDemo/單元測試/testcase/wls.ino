int water_sensor=0;
int val=0;
int wlsFlag=0;
void wlsSetup()
{
  
}
void wlsActive()
{
  wlsFlag=wlsFlag+1;
  wlsFlag=wlsFlag%2;
}
void wlsCheck()
{
  if(wlsFlag==1)
  {
    val=analogRead(water_sensor);
    Serial.println(val);

    delay(100);
  }
  
}