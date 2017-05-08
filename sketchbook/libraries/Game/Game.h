//Project for the Subject Prototyping av Interaktive medier
//Department of Design
//NTNU
//May 8th 2017
//Group 1 - Ingvild Engelsen, Sofie Bjørnå, Gjøril Fjeldstad, Torstein Bakke


//Header file for the Game libary used to run the Lectric
#ifndef Game_h
# define Game_h


//declaring class and all member functions and variables. Assigns pin numbers and maps colors to numbers
class Game
{
  public:

    Game ();    //constructor
    void startSpeech();
    void capCharge();
    void capDischarge();
    void setSolution();
    bool isButtonDown(int button);
    void win();
    void play();
    void setCapColor(int color);
    void setCapVoltage(int voltage);
    void playChargeSound();
    void playDischargeSound();
    void setSquareColor();
    void setTriangleColor();
    void setCircleColor();
    void setSolutionVoltage();
    void giveColorToFlash(int redPin, int greenPin, int bluePin, int color);
    void setColorCombination(int redPin, int greenPin, int bluePin, int red, int green, int blue);
    void readPotAndSend();



  private:

    int capColor;
    int capVoltage;
    int chargerVoltage;
    int potVal;
    int prevVolts;



    int red = 5;
    int pink = 12;
    int orange = 3;
    int green = 20;
    int yellow = 15;
    int blue = 10;
    int colors[6] = {pink, green, yellow, blue, red, orange};
    int solutionVoltage;

    int capRedPin = 2;
    int capGreenPin = 3;

    int squareColor;
    int squareRedPin = 8;
    int squareGreenPin = 9;
    int squareBluePin = 10;

    int triangleColor;
    int triangleRedPin = 11;
    int triangleGreenPin = 12;
    int triangleBluePin = 13;

    int circleColor;
    int circleRedPin = 5;
    int circleGreenPin = 6;
    int circleBluePin = 7;



    bool won;

    int n1;
    int n2;
    int chargerButton = 25;    //pin
    int squareButton = 27;
    int triangleButton = 28;
    int circleButton =26;
    int headButton = 22;
    int chargeButton = 24;
    int hintButton = 23;

    int stripPin = 46;



};


#endif
