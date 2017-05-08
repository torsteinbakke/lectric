//Project for the Subject Prototyping av Interaktive medier
//Department of Design
//NTNU
//May 8th 2017
//Group 1 - Ingvild Engelsen, Sofie Bjørnå, Gjøril Fjeldstad, Torstein Bakke

// This code controls the Arduino Uno which controls the head

//Include Servo library (Arduino Native)
#include <Servo.h>

//Declare all pins, servos, counters and incoming serial comm
Servo servoMouth;  // create a servo object
Servo servoEyes;  // create a servo object
Servo servoBrowL;  // create a servo object
Servo servoBrowR;  // create a servo object
int mouthPin = 12;
int i = 0;
int redPin = 3;
int greenPin = 5;
int bluePin = 6;
int const potPin = A0; // analog pin used to connect the potentiometer
int potVal;  // variable to read the value from the analog pin
int angle;   // variable to hold the angle for the servo motor
int incomingByte;

int number;

void setup() {
  
  //Sets LED pins to output and attaches all servos to the right pins
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
  
  servoMouth.attach(4); // attaches the servo on pin 9 to the servo object
  servoBrowL.attach(9); // attaches the servo on pin 9 to the servo object
  servoBrowR.attach(8); // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // open a serial connection to your computer
  
  //Sets servos to start positions
  servoMouth.write(144);
  servoBrowR.write(60);
  servoBrowL.write(80);
}


//Sets eye colors
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

//Head movement/eyecolor program
void AU1(){ // 2,5 sek (feil blits)
 setColor(0,0,255); //oransje
 servoBrowR.write(100);
 servoBrowL.write(60);
 servoMouth.write(150);
 delay(500);
 servoMouth.write(160);
 delay(500);
 servoMouth.write(150);
 delay(500);
 servoMouth.write(160);
 delay(500);
 servoMouth.write(150);
 delay(500);
}

//Head resting position
void sov(){ // sov
 setColor(255,0,0); //rosa
 servoBrowR.write(100);
 servoBrowL.write(40);
 servoMouth.write(160);
 }

//Head movement/eyecolor program
void introRobot(){ // 10 sek (intro robot)
  servoMouth.write(160);
  servoBrowR.write(80);
  servoBrowL.write(60);
  setColor(0,255,255); //cyan
  delay(1000);
  setColor(0,0,0);
  delay(100);
  setColor(0,255,255);
  delay(200);
  setColor(0,0,0);
  delay(100);
  setColor(0,255,255);
  delay(300);
  setColor(0,0,0);
  delay(100);
  setColor(0,255,255);
  delay(100);
  for (int i = 0; i < 10; i++){
    servoMouth.write(144);
    delay(500);
    servoMouth.write(160);
    delay(500);
}}

//Head movement/eyecolor program
void ondLatter(){ //2,2 sek (ond latter)
  setColor(255,0,0); //rød
  servoBrowR.write(100);
  servoBrowL.write(40);
  servoMouth.write(144);
  delay(200);
  servoMouth.write(160);
  delay(500);
  servoMouth.write(144);
  delay(200);
  servoMouth.write(160);
  delay(500);
  servoMouth.write(144);
  delay(200);
  servoMouth.write(160);
  delay(400);
  servoMouth.write(144);
  delay(200);
}

//Head movement/eyecolor program
void AU5(){ // 2,8 sek (tiden går)
 setColor(255,255,0); //gul
 servoBrowR.write(60);
 servoBrowL.write(80);
 for (int i = 0; i < 3; i++){
  servoMouth.write(160);
  delay(400);
  servoMouth.write(144);
  delay(300);
 }

}

//Head movement/eyecolor program
void AU6(){
 setColor(255,255,0); //gul
 servoBrowR.write(60);
 servoBrowL.write(80);
 for (int i = 0; i < 3; i++){
  servoMouth.write(160);
  delay(400);
  servoMouth.write(144);
  delay(300);  
}
}

//Head movement/eyecolor program
void dead(){
 servoMouth.write(144);
 servoBrowR.write(100);
 servoBrowL.write(40);
  setColor(230,230,0);
  delay(90);
  setColor(0,0,0);
  delay(40);
  setColor(0,60,70);
  delay(70);
  setColor(0,0,0);
  delay(40);
  setColor(255,255,0);
  delay(100);
  setColor(0,0,0);
  delay(20);
  setColor(255,0,0);
  delay(200);
  setColor(0,0,255);
  delay(70);
  setColor(230,230,0);
  delay(90);
  setColor(0,0,0);
  delay(40);
  setColor(0,60,70);
  delay(70);
  setColor(0,0,0);
  delay(40);
  setColor(255,255,0);
  delay(100);
  setColor(0,0,0);
  delay(20);
  setColor(255,0,0);
  delay(200);
  setColor(230,230,0);
  delay(90);
  setColor(0,0,0);
  delay(40);
  setColor(0,60,70);
  delay(70);
  setColor(0,0,0);
  delay(40);
  setColor(255,255,0);
  delay(100);
  setColor(0,0,0);
  delay(20);
  setColor(255,0,0);
  delay(200);
  setColor(0,0,255);
  delay(70);
  setColor(230,230,0);
  delay(90);
  setColor(0,0,0);
  delay(40);
  setColor(0,60,70);
  delay(70);
  setColor(0,0,0);
  delay(40);
  setColor(255,255,0);
  delay(100);
  setColor(0,0,0);
  delay(20);
  setColor(255,0,0);
  delay(200);
  setColor(230,230,0);
  delay(90);
  setColor(0,0,0);
  delay(40);
  setColor(0,60,70);
  delay(70);
  setColor(0,0,0);
  delay(40);
  setColor(255,255,0);
  delay(100);
  setColor(0,0,0);
  delay(20);
  setColor(255,0,0);
  delay(200);
  setColor(0,0,255);
  delay(70);
  setColor(230,230,0);
  delay(90);
  setColor(0,0,0);
  delay(40);
  setColor(0,60,70);
  delay(70);
  setColor(0,0,0);
  delay(40);
  setColor(255,255,0);
  delay(100);
  setColor(0,0,0);
  delay(20);
  setColor(255,0,0);
  delay(200);
  setColor(230,230,0);
  delay(90);
  setColor(0,0,0);
  delay(40);
  setColor(0,60,70);
  delay(70);
  setColor(0,0,0);
  delay(40);
  setColor(255,255,0);
  delay(100);
  setColor(0,0,0);
  delay(20);
  setColor(255,0,0);
  delay(200);
  setColor(0,0,255);
  delay(70);
  setColor(230,230,0);
  delay(90);
  setColor(0,0,0);
  delay(40);
  setColor(0,60,70);
  delay(70);
  setColor(0,0,0);
  delay(40);
  setColor(255,255,0);
  delay(100);
  setColor(0,0,0);
  delay(20);
  setColor(255,0,0);
  delay(200);
  setColor(230,230,0);
  delay(90);
  setColor(0,0,0);
  delay(40);
  setColor(0,60,70);
  delay(70);
  setColor(0,0,0);
  delay(40);
  setColor(255,255,0);
  delay(100);
  setColor(0,0,0);
  delay(20);
  setColor(255,0,0);
  delay(200);
  setColor(0,0,255);
  delay(70);
  setColor(230,230,0);
  delay(90);
  setColor(0,0,0);
  delay(40);
  setColor(0,60,70);
  delay(70);
  setColor(0,0,0);
  delay(40);
  setColor(255,255,0);
  delay(100);
  setColor(0,0,0);
  delay(20);
  setColor(255,0,0);
  delay(200);
  setColor(0,0,255);
  delay(70);
  setColor(0,0,0);
  delay(200);
  setColor(0,0,255);
  delay(400);
  setColor(0,0,0);
  delay(300);
  setColor(0,0,255);
  delay(400);
  setColor(0,0,0);
  delay(300);
  setColor(0,0,255);
  delay(400);
  setColor(0,0,0);
  delay(300);
  setColor(0,0,255);
  delay(400);
  setColor(0,0,0);
  delay(300);

}

//Loop. Listens for incoming serial communication, initiates program accordingly
void loop() {
  sov();
  while (Serial.available() > 0){
      number = Serial.read();
      if (number == 36){
        introRobot();
      }
      else if (number == 39){
        AU1();
      }
      else if (number == 41){
        dead();
      }
      }
      }
