import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BCM)
GPIO.setup(4,GPIO.OUT)
GPIO.setup(5,GPIO.OUT)
GPIO.setup(6,GPIO.OUT) 
GPIO.setup(26,GPIO.IN)

while True:    
     
     GPIO.output(5, GPIO.HIGH)
     #sleep(0.5)
     #GPIO.output(5, GPIO.LOW)
     #GPIO.output(6, GPIO.HIGH)
     sleep(0.5)
     #GPIO.output(6, GPIO.LOW)
     #sleep(0.5)
    
