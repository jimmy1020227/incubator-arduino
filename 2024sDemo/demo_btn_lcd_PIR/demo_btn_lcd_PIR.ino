#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
unsigned long time_now,timestart;
unsigned long duration=15000;
int btnflag=0;
int btnpin=4;
int sensor = 5; 
int enableLcd=0;





//------------------------------------------------------


void setup() {


  lcd.init();
  lcd.backlight();
  lcd.setCursor(5,0);
  lcd.print("holle");
  lcd.setCursor(5,1);
  lcd.print("jimmy");
  Serial.begin(9600);
  pinMode(btnpin, INPUT_PULLUP);
  pinMode(13, OUTPUT);
//pir
  pinMode(sensor, INPUT); 

}


//------------------------------------------------------
void loop() {

  time_now = millis();
  int btnstate = digitalRead(btnpin);
  int moving = digitalRead(sensor);

  Serial.print("btnstate=");
  Serial.println(btnstate);

  
  if (btnstate == HIGH) {

    digitalWrite(13, LOW);

  } else {

    digitalWrite(13, HIGH);
    btnflag=btnflag+1;
    btnflag=btnflag%2;
    
    lcd.setBacklight(btnflag);
    if(btnflag==0)
    {
      
      lcd.noDisplay();

    }
    else
    {
      lcd.display();
      
    }
    delay(500);

  }
  if(moving==1){ //如果有物體移動
    Serial.println("有東西在動！");  
     if(btnflag==0)
    {
      enableLcd=1;
      timestart = millis();
      lcd.setBacklight(1);
      lcd.display();
 
      
      //(3000);
      //lcd.noDisplay();
    }
      
  }
  delay(100);

  if(enableLcd==1 &&(time_now - timestart)> duration)
  {
    lcd.setBacklight(btnflag);
    lcd.noDisplay();

  }

}
