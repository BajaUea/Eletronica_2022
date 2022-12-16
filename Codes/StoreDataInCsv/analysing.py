import pandas as pd
import plotly.graph_objects as go

df_map = pd.read_csv("Arquivos_CSV/map.csv")
graph_map = go.Figure(data=go.Scatter(x=df_map["latitude"], y=df_map["longitude"], mode='markers'))

graph_map.show()