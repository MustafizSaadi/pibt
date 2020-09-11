from matplotlib import pyplot
from matplotlib import colors
import numpy as np
data = np.zeros((8,8))

for i in range(8):
    for j in range(8):
        data[i][j] = i

colormap = colors.ListedColormap(["red","green","blue","violet","indigo","yellow","orange","white"])
pyplot.imshow(data,
             cmap=colormap)
pyplot.show()