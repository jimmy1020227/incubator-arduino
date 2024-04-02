#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);


void lcdSetup() {
                     // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.setBacklight(0);
  lcd.noDisplay();
 



}
void lcdActive()
{
  lcd.setBacklight(1);
  lcd.display();

  lcd.backlight();
  lcd.setCursor(5,0);
  lcd.print("hello");
  lcd.setCursor(5,1);
  lcd.print("jimmy");
  delay(5000);
  lcd.setBacklight(0);
  lcd.noDisplay();
}
