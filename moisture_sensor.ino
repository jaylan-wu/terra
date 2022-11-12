
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16, 2);

//defines the variables for the moisture sensor
#define sensor A2
#define wet 269
#define dry 500

//defines the emotes that are used for the plant's feelings
#define happy "   yay!!!! :D   "
#define sad "   sad.... :(   "
#define drowning " TOO MUCH!! >o< "
#define dead "  water... x.x  "
 
void setup() {
  //sets up the moisture sensor
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}
 
void loop() {
  //code for the moisture sensor
    // value is the analog reading from the moisture sensor
  int value = analogRead(sensor);
    // pre is the percentange of moisture that the sensor is measuring
  int pre = map(value, wet, dry, 100, 0);
    // prints out values to the LCD screen on the first row
  lcd.setCursor(0, 0);
  lcd.print("Moisture %: ");
  lcd.print(pre);
  lcd.print("%   ");

  //code for the feelings uses the moisture levels from before in the second row of the LCD
  lcd.setCursor(0, 1);
  if (pre >= 90) {
    lcd.print(drowning); //drowning interface if moisture level is > 90%
  }
  else if (pre < 90 && pre >= 45) {
    lcd.print(happy); // happy1 interface by random but if moisture level is >45% and <90%
  }
  else if (pre < 45 && pre >= 10) {
    lcd.print(sad); //sad interface if moisture level is <45% and >10%
  }
  else if (pre < 10) {
    lcd.print(dead); //dry interface if moisture level is <10%
  }
}
