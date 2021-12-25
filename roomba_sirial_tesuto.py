import serial
import time
 
ser = serial.Serial('/dev/ttyACM0', 19200)

for i in range(10):
        ser.write(b'a')
        print("LED ON")
        time.sleep(3)
        
ser.close()
print("bbb")
