#include <SimpleDHT.h>
#include <Wire.h> // I2C程式庫
#include <LiquidCrystal_I2C.h> // LCD_I2C模組程式庫
unsigned long time_now,timestart;
unsigned long duration=15000;
bool startFlag = 0;
// LCD I2C位址，默認為0x27或0x3F，依據背板的晶片不同而有差異，16、2為LCD顯示器大小。
LiquidCrystal_I2C lcd(0x27, 16, 2); 


// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

void setup() {
  Serial.begin(115200);
  // 初始化LCD
  lcd.init();
  lcd.backlight();
  /*
  lcd.setCursor(2, 0); // (colum, row)從第一排的第三個位置開始顯示
  lcd.print("Hello World!"); 
  lcd.setCursor(2, 1); // (colum,row)從第二排第三格位置開始顯示
  lcd.print("Jimmy Lee !");
  */
  
  timestart = millis();
}
void display(int temperature,int humidity)
{
    lcd.clear();
    lcd.setCursor(0, 0); // (colum, row)從第一排的第三個位置開始顯示
    lcd.print("temp:");
    lcd.setCursor(6, 0);
    lcd.print((int)temperature);
    lcd.setCursor(8, 0); 
    lcd.print("C"); 

    lcd.setCursor(0, 1); // (colum, row)從第一排的第三個位置開始顯示
    lcd.print("humidity:");
    lcd.setCursor(10, 1);
    lcd.print((int)humidity);
    lcd.setCursor(12, 1); 
    lcd.print("H"); 
    lcd.backlight();
    delay(1000);
    lcd.noBacklight();

}

void loop() {
  time_now = millis();
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }

  Serial.print("Sample OK: ");
  Serial.print((int)temperature); 
  Serial.print(" *C, "); 
  Serial.print((int)humidity); 
  Serial.println(" H");

  if(startFlag == 0)
  {
    startFlag =1;
    display(temperature,humidity);
  }
  if((time_now - timestart)> duration)
  {
    timestart = millis();
    display(temperature,humidity);
  
  }
  // DHT11 sampling rate is 1HZ.
  
  delay(1500);
}
