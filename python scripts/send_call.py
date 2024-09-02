import serial
import sys
import time

# This file is to call the function
while True:
    try:
        port = serial.Serial("/dev/ttyACM0", 115200, timeout=1000000)
            
        port.write((2).to_bytes(1, 'little'))
        port.write((0).to_bytes(1, 'little'))

        port.close()
        break
    except Exception as e:
        print(e)
        time.sleep(2)