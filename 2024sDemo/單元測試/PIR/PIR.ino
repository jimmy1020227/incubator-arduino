
int sensor = 5;  //訊號線

void setup() {                
  Serial.begin(9600); 
  pinMode(sensor, INPUT); 
}

void loop() {
  
  int moving = digitalRead(sensor); //讀取D9是否有偵測到物體移動
  if(moving==1){ //如果有物體移動
    Serial.println("有東西在動！");  
  }
  delay(100);
}