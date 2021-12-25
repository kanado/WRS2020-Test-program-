import RPi.GPIO as GPIO
from time import sleep
import LINE
import hanasu
#import sirial_tesuto2
#import serial

#ser = serial.Serial('/dev/ttyACM0', 115200)
GPIO.setmode(GPIO.BCM)
GPIO.setup(4,GPIO.OUT)
GPIO.setup(5, GPIO.OUT)
GPIO.setup(6, GPIO.OUT)
GPIO.setup(17,GPIO.IN)
GPIO.setup(26,GPIO.IN)
GPIO.setup(27,GPIO.IN)

#sirial_tesuto2.clear()
GPIO.output(6, GPIO.LOW)
GPIO.output(5, GPIO.LOW)

magaru = ("B")

while True:
    #String_data = ser.read()
    print(magaru)
    if (GPIO.input(26)==GPIO.HIGH and magaru==("A")):
        hanasu.speak("Mission accomplished")
        
    if GPIO.input(26)==GPIO.HIGH:
        hanasu.speak("put it here and push the button, please.")
        sleep(0.05)
        #sirial_tesuto2.clear()
        print("LED on")
        
    
    
    if GPIO.input(27)==GPIO.HIGH:
        GPIO.output(4,GPIO.HIGH)
        hanasu.speak(" Thank you. Good bye.")
        #LINE.line("push the button")
        GPIO.output(6,GPIO.HIGH)
        sleep(0.5)
        GPIO.output(6,GPIO.LOW)
        sleep(0.5)
        print("GO")
        magaru = ("A")
        print(magaru)
        #sirial_tesuto2.B()
        
    if GPIO.input(17)==GPIO.HIGH:
        GPIO.output(4,GPIO.HIGH)
        hanasu.speak("Delivery arrived.")
        sleep(0.5)
        hanasu.speak("I head to the door")
        sleep(0.5)
        LINE.line("Delivery arrived")
        GPIO.output(5,GPIO.HIGH)
        sleep(0.5)
        GPIO.output(5,GPIO.LOW)
        sleep(0.5)
        print("strat")
        #sirial_tesuto2.A()
        
    
    
    else:
        GPIO.output(4,GPIO.LOW)
        GPIO.output(6, GPIO.LOW)
        GPIO.output(5, GPIO.LOW)
        sleep(0.01)
