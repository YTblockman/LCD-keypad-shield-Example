/*
 Modified ... 
 Welcome.ino //YTblockman 2020
 Display "LCD Keypad shield" 
 by "LiquidCrystal.h" library
 DESC: This is some example for your arduino uno or else
     - LCD shield requiered !
   Download page : https://github.com/YTblockman/LCD-keypad-shield-Example.git
*/
#include <LiquidCrystal.h> // import a library
int LoopA = 1;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);// Custom char. (like 0: Welcome_face)
byte Welcome_face[8] = {
  0b00000,
  0b01010,
  0b01010,
  0b00000,
  0b10001,
  0b01110,
  0b00000,
  0b00000
};
byte Sand_Clock[8] = {
  0b00000,
  0b11111,
  0b01110,
  0b00100,
  0b01110,
  0b11111,
  0b00000,
  0b00000
};
byte Sand_Clock1[8] = {
  0b00000,
  0b10001,
  0b11011,
  0b11111,
  0b11011,
  0b10001,
  0b00000,
  0b00000
};
byte Welcome_face2[8] = {
  0b00000,
  0b00010,
  0b11010,
  0b00000,
  0b10001,
  0b01110,
  0b00000,
  0b00000
};
void setup() {
  Serial.begin(9600); // this serial prints progress of Graphic loading, Serial moinitor (Ctrl + Shift + M)
  Serial.println("Serial for Welcome.ino");
  Serial.println("---Loading-Progress---");
  Serial.println("bytes defined.");
  Serial.println("void setup"); // like this ( prints where program slider is )
  lcd.begin(16, 2);
  lcd.createChar(0, Welcome_face); // Defines Char.
  lcd.createChar(1, Sand_Clock);
  lcd.createChar(2, Sand_Clock1);
  lcd.createChar(3, Welcome_face2);
  Serial.println("void setup Done!");
}
void loop() {
  Serial.println("void loop");
  for (int Clock = 1; Clock <= 4; Clock++) {
    Serial.print("for (Sand_Clock) run = ");
    Serial.print(Clock);
    Serial.println("");
    lcd.setCursor(0, 1);
    lcd.print("Welcome.ino");
    lcd.setCursor(15, 1);
    lcd.write(byte(1));
    //lcd.write(byte(0));
    delay(1000);
    lcd.setCursor(15, 1);
    lcd.write(byte(2));
    //lcd.write(byte(3));
    delay(1000);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcome!"); // Prints Basic Text
  Serial.println("Printing Weclome");
  for(;;) {
  delay(1000); // Prints Face (Animated)
  lcd.setCursor(15, 1);
  lcd.write(byte(3));
  delay(1000);
  lcd.setCursor(15, 1);
  lcd.write(byte(0));
  Serial.print("Smile face blink run = ");
  Serial.print(LoopA);
  Serial.println("");
  LoopA = LoopA +1;
  }
}
