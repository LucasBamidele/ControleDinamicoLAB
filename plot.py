import matplotlib.pyplot as plt 
from math import *
import numpy as np 
import csv
from sklearn import linear_model
from scipy.ndimage.filters import gaussian_filter
filename = 'Triangular_Tr.csv'
delta_m = -0.3657
delta_p = 0.3286
Vk = []
Vm = []
Vm2 = []
times = []
with open(filename, 'rU') as csvfile:
	spamreader = csv.reader(csvfile, delimiter=',')
	lines_skip = 1
	for i in range(lines_skip):
		next(spamreader)
	for row in spamreader:
		if row:
			times += [float(row[0])]
			Vk+= [float(row[1])/331.68]
			#Vm+= [float(aux)]
			Vm2 += [float(row[-2])/2.0]
print max(Vm2)
plt.plot(Vk)
plt.plot(Vm2)
plt.show()