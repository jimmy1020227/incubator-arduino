#include <SimpleDHT.h> 
int  dhtFlag=0;
int pinDHT11 = 12;
SimpleDHT11 dht11;
 
void dhtSetup() {
  
}
void dhtActive()
{
  dhtFlag=dhtFlag+1;
  dhtFlag=dhtFlag%2;
}
void dhtCheck()
{
  if(dhtFlag==1)
  {
    byte temperature = 0;
    byte humidity = 0;
    int err = SimpleDHTErrSuccess;
    // start working...
    Serial.println("=================================");
    if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
       Serial.print("Read DHT11 failed, err="); 
       Serial.println(err);
       delay(1000);
       return;
    }
    Serial.print("Humidity = ");   
    Serial.print((int)humidity);   
    Serial.print("% , ");   
    Serial.print("Temperature = ");   
    Serial.print((int)temperature);   
    Serial.println("C ");   
 
    delay(1000);  //每3秒顯示一次 
  }
 
}