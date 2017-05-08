//Project for the Subject Prototyping av Interaktive medier
//Department of Design
//NTNU
//May 8th 2017
//Group 1 - Ingvild Engelsen, Sofie Bjørnå, Gjøril Fjeldstad, Torstein Bakke

// Includes LCD Library (Arduino Native)
#include <LiquidCrystal.h>

//Initiates the screen
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int number;

void setup() {
  //Sets up serial connection to receive from Raspberry Pi
  Serial.begin(9600);
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);

  // Prints message
  lcd.print("TRYKK HER");

}

void loop() {

 
  while (Serial.available() > 0) {
    //Reads byte from serial connection
      number = Serial.read();

//If-Else loop to check for byte and print messages accordingly
      if (number < 36){
        lcd.clear();
        lcd.print("LAD OPP:");
        lcd.setCursor(0, 1);
        lcd.print("   ");
        lcd.setCursor(0, 1);
        lcd.print(number*10, DEC);
        lcd.setCursor(4,1);
        lcd.print("VOLT");
        delay(10);
      }
      else if (number == 37){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("LADER OPP");
        lcd.setCursor(0,1);
        //Loop to animate charging
        for (int i = 1; i < 16; i++){
          lcd.print("-");
          lcd.setCursor(i-1, 1);
          delay(200);
        }
        lcd.clear();
        lcd.print("LAD OPP: ");
      }
      //Final messages
      else if (number == 41){
        lcd.clear();
        lcd.print("GRATULERER");
        delay(20000);
        //Reverts to initial message
        lcd.clear();
        lcd.print("TRYKK HER");
      }
  }
}
