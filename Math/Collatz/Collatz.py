#%%
import matplotlib.pyplot as plt
from array import array
seed=array('d')
steps=array('d')
path=[]
fig,ax = plt.subplots() 

for x in range(20):
 x=x+1      
 i=0   
 z=x
 path.append(z) 
 while z!=1:
     if z%2==0: 
         z=z/2  
     else:
         z=3*z+1
     i=i+1
     path.append(z)
 ax.plot(path,label=x)
 path.clear()
 seed.append(x)
 steps.append(i)


#plt.scatter(seed,steps)
leg= ax.legend(loc='upper right')
plt.show()

#%%
import matplotlib.pyplot as plt
from array import array
seed=array('d')
steps=array('d')
path=[]
fig,ax = plt.subplots() 

for x in range(300):
 x=x+1      
 i=0   
 z=x
 path.append(z) 
 while z!=1:
     if z%2==0: 
         z=z/2  
     else:
         z=3*z+1
     i=i+1
     path.append(z)
 #ax.plot(path,label=x)
 path.clear()
 seed.append(x)
 steps.append(i)


plt.scatter(seed,steps)
#leg= ax.legend(loc='upper right')
plt.show()


# %%
import plotly.graph_objects as go
import numpy as np
import matplotlib.pyplot as plt
from array import array
seed=[]
stepss=[]
path=[]
pathlenght=[]
fig = go.Figure()
y=100
#fig,ax = plt.subplots() 

for x in range(y):
 x=x+1      
 i=0   
 z=x
 path.append(z) 
 while 1==1:
     if z%2==0: 
         z=z/2  
     else:
         z=3*z+1
     i=i+1
     pathlenght.append(i)
     path.append(z)
     if z==1:
         i=i+1
         pathlenght.append(i)
         path.append(z)
         break
 if x==1:
     path.clear()
     pathlenght.clear()
     pathlenght.append(1)
     path.append(1)   
#ax.plot(path,label=x)
 fig.add_trace(
        go.Scatter(
            visible=False,
            line=dict(color="black", width=3),
            name=" seed ",
            x=pathlenght,
            y=path
            ))
 path.clear()
 pathlenght.clear()
 seed.append(x)
 stepss.append(i)

# Add traces, one for each slider step
#for step in np.arange(1, y, 1):


# Make 10th trace visible
fig.data[1].visible = True

# Create and add slider
steps = []
for i in range(len(fig.data)):
    step = dict(
        method="update",
        args=[{"visible": [False] * len(fig.data)},
              {"title": "Collatz conjecture path of num: " + str(i+1)}],  # layout attribute
    )
    step["args"][0]["visible"][i] = True  # Toggle i'th trace to "visible"
    steps.append(step)

sliders = [dict(
    active=1,
    currentvalue={"prefix": "Seed: "},
    pad={"t": 50},
    steps=steps
)]

fig.update_layout(
    sliders=sliders
)

fig.show()

histo = go.Figure(data=[go.Histogram2d(x=stepss,y=seed, nbinsx=max(stepss), nbinsy=y )])
histo.show()


#%%