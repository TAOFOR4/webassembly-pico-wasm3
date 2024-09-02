import serial
import sys
import time

# This file is to send the wasm code into pico
while True:
    try:
        port = serial.Serial("/dev/ttyACM0", 115200, timeout=1000000)

        with open(sys.argv[1], "rb") as f:
            data = f.read()
            assert len(data) <= 1021, "File too big!"
            
        port.write((1).to_bytes(1, 'little'))
        port.write(data)

        port.close()
        break
    except Exception as e:
        print(e)
        time.sleep(2)