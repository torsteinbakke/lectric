# -*- coding: utf-8 -*-
#Project for the Subject Prototyping av Interaktive medier
#Department of Design
#NTNU
#May 8th 2017
#Group 1 - Ingvild Engelsen, Sofie Bjoernaa, Gjoeril Fjeldstad, Torstein Bakke

#This python script is programmed to launch each time the Raspberry Pi boots - cold or warm
#Import needed libraries - serial, pygame (for sound) and time (for delays)

import serial
import pygame
import time


#Open up serial communication with arduinos. Called by linux symbolic id
controlPanel = serial.Serial('/dev/serial/by-id/usb-Arduino_Srl_Arduino_Mega_8553530363635171D1B0-if00', 9600) #ttyACM0
lcd = serial.Serial('/dev/ttyUSB0', 9600) #ttyUSB0
head = serial.Serial('/dev/serial/by-id/usb-1a86_USB2.0-Serial-if00-port0', 9600)

#Initialize pygame mixer, set large number of channels
pygame.mixer.init()
pygame.mixer.set_num_channels(100)

#Load all sounds
discharge = pygame.mixer.Sound('discharge.ogg')
drops = pygame.mixer.Sound('drops.ogg')
drops.set_volume(0.3)
done = pygame.mixer.Sound('done_ambience.ogg')
hintblitz = pygame.mixer.Sound('hint1blitz.ogg')
hintluke = pygame.mixer.Sound('hintluke.ogg')
hintkombo = pygame.mixer.Sound('hintkombo.ogg')
forteller = pygame.mixer.Sound('Introfortellerdame.ogg')
introrobot = pygame.mixer.Sound('Intro robot.ogg')
error = pygame.mixer.Sound('error.ogg')
tiktak = pygame.mixer.Sound('evil2.ogg')
death = pygame.mixer.Sound('robotendor.ogg')
grattis = pygame.mixer.Sound('grattis.ogg')

#Counter for hints
i = 1



#Loop:
while True:
#Makes sure win sound is stopped at reset
    done.stop()

#Reads byte from Arduino Mega
    byte = controlPanel.read()

#Sends to LCD
    if ord((byte)) <= 35:
        print(ord(byte))
        lcd.write(byte)

        
#Plays sound and head movement at startup
    elif ord((byte)) == 36:
        print('starting')
        #Starts ambient sounds, plays file 5 times
        drops.play(4)
        forteller.play()
        time.sleep(16)
        head.write(byte)
        introrobot.play()
        time.sleep(11)
        
#Plays charge sound and prints charge message on charge
    elif ord((byte)) == 37:
        print('charge')
        charge = pygame.mixer.Sound('charge.ogg')
        lcd.write(byte)
        charge.play()

#Plays discharge sound on discharge
    elif ord((byte)) == 38:
        print('discharge')
        time.sleep(2)
        discharge.play()
    elif ord((byte)) == 39:

        
#Plays error sounds and starts head movement on error        
        print('wrong')
        error.play()
        tiktak.play()
        head.write(byte)
        time.sleep(1)

#Plays hints in right order        
    elif ord((byte)) == 40:
        print("hint")
        if i == 1:
            print("hintblitz")
            hintblitz.play()
            i = i + 1
        elif i == 2 :
            print("hintluke")
            hintluke.play()
            i = i + 1
        elif i == 3 :
            print("hintkombo")
            hintkombo.play()
            i = 1
        
#Plays final sounds and starts head movement on winning the game
    elif ord((byte)) == 41:
        print("won")
        head.write(byte)
        drops.stop()
        done.play()
        time.sleep(2)
        death.play()
        lcd.write(byte)
        time.sleep(8)
        grattis.play()
        time.sleep(5)
        print("restart")
