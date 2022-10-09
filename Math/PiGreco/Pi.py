#%%
from cmath import pi
import math as ma
from statistics import mode
from turtle import width
import plotly.graph_objects as go
import numpy as np
import matplotlib.pyplot as plt

dif=1
ang=0
j=4
y=[]
x=[]
sides=[]
app=[]

fig = go.Figure()
fig2 = go.Figure()


while dif>1.0e-4:
   ang=pi/j
   per=j*2*ma.sin(ang)
   for i in range(j):
        if ang*i<pi:
          x.append(ma.cos(2*ang*i+pi/2))
          y.append(ma.sin(2*ang*i+pi/2))
        i=i+1   
   x.append(ma.cos(pi/2))
   y.append(ma.sin(pi/2))
   j=j+1
 
   fig.add_trace(
             go.Scatter(
                 visible=False,
                 line=dict(color="black", width=2),
                 name=str(per/2),
                 x=x,
                 y=y
                 ))

   dif=abs(pi-per/2)
   sides.append(j)
   app.append(per/2)
   x.clear()
   y.clear()

fig2.add_trace(
             go.Scatter(
                 visible=True,
                 line=dict(color="black", width=2),
                 name=" polygon ",
                 x=sides,
                 y=app
                 ))                 

steps = []
for i in range(len(fig.data)):
    step = dict(
        method="update",
        args=[{"visible": [False] * len(fig.data)},
              {"title": "Pi approx with polygon with sides " + str(i+4)}],  # layout attribute
    )
    step["args"][0]["visible"][i] = True  # Toggle i'th trace to "visible"
    steps.append(step)

sliders = [dict(
    active=1,
    currentvalue={"prefix" : ": "},
    pad={"t": 50},
    steps=steps
)]

fig.update_layout(
    sliders=sliders
)

fig.show()
fig2.show()

# %%
