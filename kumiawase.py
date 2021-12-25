import RPi.GPIO as GPIO
from time import sleep
import LINE
import hanasu
import sirial_tesuto2
import serial

ser = serial.Serial('/dev/ttyACM0', 19200)
GPIO.setmode(GPIO.BCM)
GPIO.setup(4,GPIO.OUT)
GPIO.setup(17,GPIO.IN)
GPIO.setup(27,GPIO.IN)

sirial_tesuto2.clear()

while True:
    String_data = ser.read()
    
    if String_data == b'A':
        hanasu.speak("put it here and push the button, please.")
        sleep(3)
        sirial_tesuto2.clear()
    
    if GPIO.input(27)==GPIO.HIGH:
        GPIO.output(4,GPIO.HIGH)
        hanasu.speak("Thankyou")
        LINE.line("push the button")
        sirial_tesuto2.B()
        
    if GPIO.input(17)==GPIO.HIGH:
        GPIO.output(4,GPIO.HIGH)
        LINE.line("Hello")
        #hanasu.speak("Delivery arrived")
        sirial_tesuto2.A()
    
    
    else:
        GPIO.output(4,GPIO.LOW)
        sleep(0.01)
