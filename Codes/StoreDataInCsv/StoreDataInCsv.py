import serial
import serial.tools.list_ports
import csv
import pandas as pd
from time import strftime, time
from pathlib import Path

serialPort = serial.Serial()
serialPort.timeout = 0.5

df = pd.DataFrame(columns=["latitude", "longitude", "altura", "speed"])

arquivo = strftime("%d.%m.%Y_%Hh%M")
path = Path("Arquivos_CSV")
path.mkdir(parents=True, exist_ok=True)
with open(f"Arquivos_CSV/{arquivo}.csv", 'w', newline='') as f:
    thewriter = csv.writer(f)
    thewriter.writerow(
        ['latitude', 'longitude', 'altura', 'speed'])
portList = [port.device for port in serial.tools.list_ports.comports()]

serialPort.port = 'COM9'
serialPort.baudrate = 115200

try:
    serialPort.open()  # Tenta abrir a porta serial
except:
    print("ERROR SERIAL")

while True:
    if serialPort.is_open:
        try:
            latitude, longitude, altura, speed = [float(x) for x in
                                                  serialPort.readline().decode("utf-8").rstrip("\r\n").split(
                                                      ",")]
            with open(f"Arquivos_CSV/{arquivo}.csv", 'a+', newline='') as f:
                thewriter = csv.writer(f)
                thewriter.writerow([latitude, longitude, altura, speed])
        except:
            print("Error Serial")