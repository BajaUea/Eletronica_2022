import serial
import serial.tools.list_ports
import csv
from time import strftime, time
from pathlib import Path
import dash
import pandas as pd
from dash.dependencies import Output, Input
import dash_core_components as dcc
import dash_html_components as html
import plotly
import random
import plotly.graph_objs as go

app = dash.Dash(__name__)
serialPort = serial.Serial()
serialPort.timeout = 0.5

df = pd.DataFrame(columns=["latitude", "longitude", "altura", "speed"])

path = Path("Arquivos_CSV")
path.mkdir(parents=True, exist_ok=True)
with open(f"Arquivos_CSV/map.csv", 'w', newline='') as f:
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

app.layout = html.Div(
    [
        dcc.Graph(id='live-graph', animate=True),
        dcc.Interval(
            id='graph-update',
            interval=1000,
            n_intervals=0
        ),
    ]
)


@app.callback(
    Output('live-graph', 'figure'),
    Input('graph-update', 'n_intervals')
)
def update_graph_scatter(n):
    if serialPort.is_open:
        print(serialPort.readline().decode("utf-8").rstrip("\r\n").split(","))
        try:
            latitude, longitude, altura, speed = [float(x) for x in
                                                  serialPort.readline().decode("utf-8").rstrip("\r\n").split(
                                                      ",")]
            with open(f"Arquivos_CSV/map.csv", 'a+', newline='') as f:
                thewriter = csv.writer(f)
                thewriter.writerow([latitude, longitude, altura, speed])

        except Exception as err:
            print(err)
    df_map = pd.read_csv("Arquivos_CSV/map.csv")
    X = df_map["latitude"]
    Y = df_map["longitude"]

    data = plotly.graph_objs.Scatter(
        x=list(X),
        y=list(Y),
        name='Scatter',
        mode='markers'
    )

    return {'data': [data]}


if __name__ == '__main__':
    app.run_server()
