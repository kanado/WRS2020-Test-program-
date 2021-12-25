import serial
import time
import subprocess
 
ser = serial.Serial('/dev/ttyACM0', 19200)

def clear():
    ser.write(b'')
    time.sleep(3)

def A():
    subprocess.call(["espeak","-s140 -ven+18 -z","I head to the door"])
    ser.write(b'a')
    print("LED ON")  
    time.sleep(3)
    ser.write(b'')
def B():    
    ser.write(b'b')
    print("LED on")
    #subprocess.call(["espeak","-s140 -ven+18 -z","B"])
    time.sleep(3)
    ser.write(b'')
def C():
    ser.write(b'c')
    print("C")
    #subprocess.call(["espeak","-s140 -ven+18 -z","C"])
    time.sleep(2)


