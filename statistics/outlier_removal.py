import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

f = open("outlier.txt","r")

datapoint = 5
arr = []
i = 0
x = np.zeros(datapoint)
yerr = np.zeros(datapoint)
for s in f:
    inp = s.split(' ')
    j = 0
    temp = []
    for k in inp:
        try:
            temp.append(float(k))
        except:
            break
        j += 1
    
    temp = np.array(temp)
    temp = temp.reshape(j,1)
    df = pd.DataFrame(temp,columns = ['A'])
    df.plot.box(grid='True')
    plt.show()
    Q1 = df.quantile(0.25)
    Q3 = df.quantile(0.75)
    IQR = Q3 - Q1
    df = df[~((df < (Q1 - 1.5 * IQR)) |(df > (Q3 + 1.5 * IQR))).any(axis=1)]
    x[i] = df.mean()
    #print(x[i])
    yerr[i] = 2*(df.std()/np.sqrt(j))
    print("{:.2f}".format(x[i]),"{:.2f}".format(yerr[i]))

    # df.plot.box(grid='True')
    # plt.show()
    # arr.append(temp)


# arr = arr.transpose()
# df = pd.DataFrame(arr)
# df.plot.box(grid='True')




