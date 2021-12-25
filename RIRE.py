import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BCM)
GPIO.setup(5, GPIO.OUT)
GPIO.setup(6, GPIO.OUT)
GPIO.output(6, True)
GPIO.output(5, True)
while True:
    GPIO.output(6, True)
    GPIO.output(5, True)
    sleep(0.01)
    GPIO.output(5, False)
    GPIO.output(6, False)
    sleep(0.01)
    
