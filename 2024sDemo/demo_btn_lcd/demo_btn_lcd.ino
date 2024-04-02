#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

int btnflag=0;
int btnpin=4;




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

}


//------------------------------------------------------
void loop() {

  
  int sensorVal = digitalRead(btnpin);



  Serial.println(sensorVal);

  
  if (sensorVal == HIGH) {

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
}
