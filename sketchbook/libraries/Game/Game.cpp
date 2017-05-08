//Project for the Subject Prototyping av Interaktive medier
//Department of Design
//NTNU
//May 8th 2017
//Group 1 - Ingvild Engelsen, Sofie Bjørnå, Gjøril Fjeldstad, Torstein Bakke

//constructor
#include "Game.h"
// include core Wiring API
#include "Arduino.h"

//includes rand function
#include <stdlib.h>


// include description files for other libraries used (if any)
#include "HardwareSerial.h"

//Constructor: starts a new game. Sets won to false, turns off LED strip, initiates the opening sequence,
//makes random solution and starts the game
Game::Game() {
  won = false;
  capColor = 0;
  digitalWrite(stripPin, LOW);
  Serial.begin(9600);
  startSpeech();
  capDischarge();
  setSolution();
  play();
}


//tells the Raspberry PI to play sound and start head movement
void Game::startSpeech() {
  Serial.write(36);
}
//Set the colors of the symbols and the solution
void Game::setSolution() {
  //get a random starting point
  randomSeed(analogRead(A2));
  setCircleColor();
  setSquareColor();
  setTriangleColor();
  setSolutionVoltage();

}

//sets random squareColor
void Game::setSquareColor(){
  /* generate random number between 1 and 4: */
  n1 = random(1, 4);
  squareColor = colors[n1];
};

void Game::setTriangleColor(){
  n2 = random(1,4);
  //makes sure the two first colors are not the same
  while (n2 == n1) {
    n2 = random(1,5);
  }
  triangleColor = colors[n2];
};

// makes sure the last color is one of two, so the solution makes sense
void Game::setCircleColor(){
  int n = random(5,6);
  circleColor = colors[n];


};
//uses the colors to compute the overall solution
void Game::setSolutionVoltage(){
  solutionVoltage = squareColor + triangleColor - circleColor;
}

//Charging the capacitor
void Game::capCharge() {
  playChargeSound();
  setCapColor(1);
  setCapVoltage(chargerVoltage);
}

//discharges the capacitor
void Game::capDischarge(){
  playDischargeSound();
  setCapColor(0);
  setCapVoltage(0);

}

//Sets the color of the capacitor to red or green depending on charge/discharge, and fades it if change.
void Game::setCapColor(int color){
  if (color == 1 && capColor == 0) {
    for( int i = 0 ; i < 255 ; i += 1 ){
      int green;
      int red;
      green += 1;
      red += 1;
      analogWrite( capGreenPin, 255 + green );
      analogWrite( capRedPin, 255 - red );
      delay(10);
    } capColor = 1;
  }
  else if (color == 0 && capColor == 1) {
    for( int i = 0 ; i < 255 ; i += 1 ){
      int green;
      int red;
      green += 1;
      red += 1;
      analogWrite( capGreenPin, 255 - green );
      analogWrite( capRedPin, 255 + red );
      delay(10);
    } capColor = 0;
  }
  else if (color == 1 && capColor == 1){
    analogWrite(capRedPin, 0);
    analogWrite(capGreenPin, 255);
  }
  else {
    analogWrite(capRedPin, 255);
    analogWrite(capGreenPin, 0);
  }
}



//Sets the voltage of the capacitor
void Game::setCapVoltage(int voltage){
  capVoltage = voltage;
}

//tells the Raspberry Pi to play the charge sound
void Game::playChargeSound(){
  Serial.write(37);
}

//tells the Raspberry Pi to play the discharge sound
void Game::playDischargeSound(){
  Serial.write(38);
}

//Reads potmeter voltage and sends it to the Raspberry Pi. Only sends if new value.
void Game::readPotAndSend() {
  potVal = analogRead(A0);
  prevVolts = chargerVoltage;
  chargerVoltage = map(potVal, 0, 1023, 0, 35);

  if (chargerVoltage != prevVolts){
  Serial.write(chargerVoltage);
  delay(1);}
}

//Returns state of any given button
bool Game::isButtonDown(int button) {
  return digitalRead(button);
}

//Write as color to flash for 1 second on each of the symbols.
void Game::setColorCombination (int redPin, int greenPin, int bluePin, int red, int green, int blue) {

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);

  delay (1000);   //hvor lenge blitsen skal lyse

  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
}

//Tells the setColorCombination which symbol should flash in which color.
void Game::giveColorToFlash(int redPin, int greenPin, int bluePin, int color) {

 if (color == 20) {
    setColorCombination(redPin, greenPin, bluePin, 0, 255, 0);  // green
  }
  else if (color == 15) {
    setColorCombination(redPin, greenPin, bluePin, 255, 128, 0);  // yellow
  }
  else if (color == 12) {
    setColorCombination(redPin, greenPin, bluePin, 255, 0, 80);  // pink
  }
    else if (color == 10) {
    setColorCombination(redPin, greenPin, bluePin, 0, 0, 255);  // blue
  }
    else if (color == 5) {
    setColorCombination(redPin, greenPin, bluePin, 255, 0, 0);  // red
  }
    else if (color == 3){
    setColorCombination(redPin, greenPin, bluePin, 255, 30, 0);  // orange
  }
}


// The win function. Breaks the play() loop, winning the game. Turns off LED strip and capacitor, tells Raspberry Pi to initiate
//final sequence
void Game::win() {
  Serial.write(41);
  digitalWrite(stripPin, LOW);
  delay(2000);
  analogWrite(capGreenPin, 0);
  analogWrite(capRedPin, 0);
  won = true;

  //Sets pin 41 high, opening the next drawer.
  //digitalWrite(41, HIGH);
}


//Play function.
void Game::play() {
  Serial.write(42);

  //Continues as long as the game is not won
  while (won == false) {

    //Reads hint button and plays hint from Raspberry Pi
    if (isButtonDown(hintButton)){
      Serial.write(40);
      delay(2000);
    }

    //Charges the capacitor according to voltage given by potmeter.
    //Reads value from potmeter and sends to Raspberry Pi and charges if charge button is pressed
    while (isButtonDown(chargerButton)) {
      potVal = analogRead(A0);
      prevVolts = chargerVoltage;
      chargerVoltage = map(potVal, 0, 1023, 0, 35);
      if (chargerVoltage != prevVolts){
      Serial.write(chargerVoltage);
      delay(1);}


      if (isButtonDown(chargeButton)) {
        digitalWrite(stripPin, HIGH);
        capCharge();
        delay(2000);
      }

    }

    //Runs while the symbol buttons are down. Checks if voltage if right
    // if right, discharges and flashes light in right color
    // if wrong, discharges and plays sound and head movement
    // if no voltage, do nothing
    while (isButtonDown(triangleButton)) {
      if (capVoltage == 25) {
        capDischarge();
        giveColorToFlash(triangleRedPin, triangleGreenPin, triangleBluePin, triangleColor);
      }
      else if (capVoltage >= 1){
        Serial.write(39);
        capDischarge();
      }
      else{

      }

    }

    //Runs while the symbol buttons are down. Checks if voltage if right
    // if right, discharges and flashes light in right color
    // if wrong, discharges and plays sound and head movement
    // if no voltage, do nothing
    while (isButtonDown(squareButton)) {
      if (capVoltage == 5) {
        capDischarge();
        giveColorToFlash(squareRedPin, squareGreenPin, squareBluePin, squareColor);

      }
      else if (capVoltage >= 1){
        Serial.write(39);
        capDischarge();
      }

    }

    //Runs while the symbol buttons are down. Checks if voltage if right
    // if right, discharges and flashes light in right color
    // if wrong, discharges and plays sound and head movement
    // if no voltage, do nothing
    while (isButtonDown(circleButton)) {
      if (capVoltage == 15) {
        capDischarge();
        giveColorToFlash(circleRedPin, circleGreenPin, circleBluePin, circleColor);

      }
      else if (capVoltage >= 1){
        Serial.write(39);
        capDischarge();
      }

    }

    //Runs while head button is down
    //If voltage is right, discharge and run Win sequence
    //if wrong, discharge and run error sequence
    while (isButtonDown(headButton)) {
      if (capVoltage == solutionVoltage) {
        capDischarge();
        win();
      }
      else if (capVoltage > 1){
        Serial.write(39);
        capDischarge();
      }

      //reset signal from drawer system wins the game, which makes it automatically reset.
    /*if (digitalRead(40)==HIGH) {
      won = true;
    }*/


    }}
    }
