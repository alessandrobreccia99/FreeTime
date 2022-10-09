# %%
from statistics import mode
from turtle import width
import plotly.graph_objects as go
import numpy as np
import matplotlib.pyplot as plt
from array import array

dif=1.0
r=0.0

p=[]
t=[]
last=[]
rate=[]

fig = go.Figure()
fig2 = go.Figure()


while r<4:
     r=r+0.001
     i=0
     x=0.5
     x1=0.0   
     p.append(x)
     t.append(0)    
     for s in range(300):
           x1=r*x*(1-x)
           s=s+1  
           dif=abs(x1-x)
           p.append(x1)
           t.append(s)
           if dif<1.0e-10:
               break
           x=x1  
     fig.add_trace(
             go.Scatter(
                 visible=False,
                 line=dict(color="black", width=2),
                 name=" starting population ",
                 x=t,
                 y=p
                 ))
     if r>2.7:            
      for j in range(min(len(p),32)):
             j=j+1 
             for k in range(min(len(p),32)): 
                 k=k+1
                 if p[-j]==p[-k]:
                     rate.append(r)          
                     last.append(p[-j])             
     else:
         rate.append(r)          
         last.append(p[-1])                                  

     p.clear()
     t.clear()

steps = []
for i in range(len(fig.data)):
    step = dict(
        method="update",
        args=[{"visible": [False] * len(fig.data)},
              {"title": "Population with ratio r: " + str(0.01*i+0.01)}],  # layout attribute
    )
    step["args"][0]["visible"][i] = True  # Toggle i'th trace to "visible"
    steps.append(step)

sliders = [dict(
    active=1,
    currentvalue={"prefix": "Start pop: "},
    pad={"t": 50},
    steps=steps
)]

fig.update_layout(
    sliders=sliders
)

fig.show()

fig2.add_trace(
             go.Scatter(
                 visible=True,
                 mode="markers",
                 marker=dict(color="Black",size=1),
                 name=" starting population ",
                 x=rate,
                 y=last,
                 ))

fig2.show()                 

fin=[]
c=298
for c in range(len(rate)-17):
    c=c+1
    co=0
    for d in range(16):
        d=d+1
        if last[c]!=last[c+d] and rate[c]==rate[c+d]:
            co=co+1
    if co==1 or co==3 or co==7 or co==15:
        fin.append(rate[c])   

#for c in range(len(rate)-17):
#   c=c+1
#   co=0
#   for d in range(16):
#       d=d+1
#       if rate[c]==rate[c+d]:
#           co=co+1
#   if co==1 or co==3 or co==7 or co==15:
#        fin.append(rate[c])  
#  
                 

# %%
from statistics import mode
from turtle import width
import plotly.graph_objects as go
import numpy as np
import matplotlib.pyplot as plt
from array import array

dif=1.0
r=0.0

p=[]
t=[]
last=[]
rate=[]
pos0=[]
pos1=[]
pos2=[]

fig = go.Figure()
fig2 = go.Figure()
fig3 = go.Figure()


while r<4:   
     r=r+0.01
     i=i+1
     x=0.5
     x1=0.0 
     x0=0.0  
     p.append(x)
     t.append(0)    
     for s in range(300):
           x1=r*x*(1-x)
           s=s+1 
           dif=abs(x1-x0)
           p.append(x1)
           t.append(s)
           if dif<1.0e-45:
               break
           x0=x 
           x=x1
     fig.add_trace(
             go.Scatter(
                 visible=False,
                 line=dict(color="black", width=2),
                 name=" starting population ",
                 x=t,
                 y=p
                 ))           
     if r>2.7:            
      for j in range(min(len(p),32)):
            j=j+1 
            for k in range(min(len(p),32)): 
                 k=k+1
                 if p[-j]==p[-k]: 
                     rate.append(r)          
                     last.append(p[-j])  
     else:
         rate.append(r)          
         last.append(p[-1])  
     a=0                                
     for a in range(len(p)):
       pos0.append(p[a])
       a=a+3

     a=1  
     for a in range(len(p)):
       pos1.append(p[a])
       a=a+3

     a=2  
     for a in range(len(p)):
       pos2.append(p[a])
       a=a+3 

     fig3.add_trace(
             go.Scatter3d(
                 visible=False,
                 mode="markers",
                 marker=dict(color="Black",size=1),
                 x=pos0,
                 y=pos1,
                 z=pos2
                 )) 

     pos0.clear()
     pos1.clear()
     pos2.clear()             
     p.clear()
     t.clear()

steps = []
for i in range(len(fig.data)):
    step = dict(
        method="update",
        args=[{"visible": [False] * len(fig.data)},
              {"title": "Population with ratio r: " + str(0.01*i+0.01)}],  # layout attribute
    )
    step["args"][0]["visible"][i] = True  # Toggle i'th trace to "visible"
    steps.append(step)

sliders = [dict(
    active=1,
    currentvalue={"prefix": "Start pop: "},
    pad={"t": 50},
    steps=steps
)]

fig.update_layout(
    sliders=sliders
)

fig3.update_layout(
    sliders=sliders
)

#fig.show()
fig3.show()

fig2.add_trace(
             go.Scatter(
                 visible=True,
                 mode="markers",
                 marker=dict(color="Black",size=1),
                 name=" starting population ",
                 x=rate,
                 y=last,
                 ))

#fig2.show()


#%%