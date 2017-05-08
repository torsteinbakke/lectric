//Project for the Subject Prototyping av Interaktive medier
//Department of Design
//NTNU
//May 8th 2017
//Group 1 - Ingvild Engelsen, Sofie Bjørnå, Gjøril Fjeldstad, Torstein Bakke

//This is the code to run on the Arduino Mega
//We wrote this library to make it easy to maintain
#include <Game.h>



void setup() {
//Initiates pins, begins serial communication with Raspberry Pi
  
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(41, OUTPUT);

pinMode(22,INPUT);
pinMode(23,INPUT);
pinMode(24,INPUT);
pinMode(25,INPUT);
pinMode(26,INPUT);
pinMode(27,INPUT);
pinMode(28,INPUT);

pinMode(46,OUTPUT);
Serial.begin(9600);

//Sets the LED strip to LOW - pin 46 controls LED strip 
digitalWrite(46,LOW); 


}

void loop() {
  //digitalWrite(41, LOW); This pin tells the system that the game has not been won yet
  
  
  digitalWrite(46,LOW); 
  
  //Starts the game (creates new Game object) once the charge button is pressed
  if (digitalRead(24) == HIGH){
  Game myGame = Game();
  }
 
  
  //Check leds and potmeter in case of maintenance
  /*digitalWrite(46,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  Serial.println(analogRead(A0));*/
  
}
