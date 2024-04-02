
int sensor = 5;  //訊號線
int pirFlag=0;
void pirSetup() {                
  
  pinMode(sensor, INPUT); 
}
void pirActive()
{
  pirFlag+=1;
  //pirFlag=pirFlag+1;
  pirFlag=pirFlag%2;
  

  
}

void pirCheck()
{
  if(pirFlag == 1)
  {
    int moving = digitalRead(sensor); //讀取D9是否有偵測到物體移動
    if(moving==1){ //如果有物體移動
      Serial.println("-----有東西在動！-----");  
    }
    else
    {
      Serial.println("沒有東西在動！"); 

    }
    delay(100);
  }
}