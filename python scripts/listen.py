import serial
import time

# This file is to monitor the pico output
while True:
    try:
        port = serial.Serial("/dev/ttyACM0", 115200, timeout=1000000)

        # with open(sys.argv[1], "rb") as f:
        #     data = f.read()
            
        # port.write(len(data).to_bytes(2, 'little'))
        # port.write((1).to_bytes(1, 'little'))
        # port.write(data)

        while True:
            print(port.read_all().decode(), end= "", flush = True)
            time.sleep(1)

        port.close()
    except Exception as e:
        print(e)
        time.sleep(2)