import matplotlib.pyplot as plt
import numpy as np
#f = open("successVSagents","r")
f = open("runtimeVSagents","r")
#f = open("weightVSagents","r")
#f = open("costVSagents","r")
datapoints = 10
x = np.zeros(datapoints)
y1 = np.zeros(datapoints)
y2 = np.zeros(datapoints)
y3 = np.zeros(datapoints)
yerr1 = np.zeros(datapoints)
yerr2 = np.zeros(datapoints)
yerr3 = np.zeros(datapoints)
#y3 = np.zeros(6)

#agents,CBS,CBSH,pibt
i = 0
for s in f:
	inp = s.split(' ')
	x[i] = float(inp[0])
	y1[i] = float(inp[1])
	yerr1[i] = float(inp[2])
	y2[i] = float(inp[3])
	yerr2[i] = float(inp[4])
	y3[i] = float(inp[5])
	yerr3[i] = float(inp[6])
	i += 1

fig,ax = plt.subplots()

ax.errorbar(x, y1, yerr=yerr1, label='ECBS',solid_capstyle='projecting', capsize=20,linewidth = 5, color='red')
ax.errorbar(x, y2, yerr=yerr2, label='SWA-ECBS',solid_capstyle='projecting', capsize=20, linewidth = 5, color='green')
ax.errorbar(x, y3, yerr=yerr3, label='DWA-ECBS',solid_capstyle='projecting', capsize=20, linewidth = 5, color='blue')

# ax.plot(x,y1,label='ECBS',color='red',linewidth = 5)
# ax.plot(x,y2,label='SWA',color='green',linewidth = 5)
# ax.plot(x,y3,label='DWA',color='blue',linewidth = 5)

#ax.setp(ax.get_xticklabels(), rotation='vertical', fontsize=7)

# ax.tick_params(which="major",labelsize=10)

for label in ax.get_xticklabels():
	#label.set_fontweight('bold')
	label.set_fontsize(30)

for label in ax.get_yticklabels():
	#label.set_fontweight('bold')
	label.set_fontsize(30)

xticks = x

# xticks = np.zeros(10)
# st = 0
# for j in range(20,201,20):
# 	xticks[st] = j
# 	st += 1

ax.set_xticks(xticks)

legend_properties = {'size':30}

plt.legend(prop=legend_properties,loc='upper left')

plt.xlabel("Number of agents",fontsize=30, labelpad=3)
#plt.xlabel("weight",fontsize=30, labelpad=2)
#plt.ylabel("runtime_ratio",fontsize=30, labelpad = 20)
plt.ylabel("runtime (ms)",fontsize=30, labelpad=20)
#plt.ylabel("Sum of costs")
plt.show()