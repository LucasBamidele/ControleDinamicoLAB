import matplotlib.pyplot as plt 
from math import *
import numpy as np 
import csv
from sklearn import linear_model
from scipy.ndimage.filters import gaussian_filter
filename = 'Quad_Tr.csv'
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
			aux = float(row[-2])
			if(aux < delta_m):
				aux += delta_m
			elif(aux <delta_p):
				aux = 0
			else :
				aux += delta_p
			#print aux
			times += [float(row[0])]
			Vk+= [float(row[1])]
			Vm+= [float(aux)]
			Vm2 += [float(row[-2])]
sigma = 10
saida_filtrada = gaussian_filter(Vk, sigma)

#Plot comparando saida Vk com a saida filtrada
#plt.plot(Vk)
#plt.plot(saida_filtrada)
#plt.show()

#comentar essa linha para ver efeito sem o filtro
Vk = saida_filtrada

#Vk1 tem que comecar no segundo elemento e terminar no penultimo
Vk1 = Vk[1:]
Vk1 = Vk1[:-1]

#Vk2 tem que terminar no ante-penultimo elemento
Vk2 = Vk[:-2]

#Vm e Vk tem que comecar a partir o terceiro elemento
Vm = Vm[2:]
Vk = Vk[2:]


#dados de entrada
my_x = [(a, b, c) for a,b,c in zip(Vk1,Vk2, Vm)]
#print my_x


#dados de saida
my_y = Vk
#print myy

#fit linear usando biblioteca sklearn
fitted_model = linear_model.LinearRegression(fit_intercept=False)
fitted_model.fit(my_x, my_y)

#printa os coeficientes e o termo independente (que no caso foi forcado a ser 0)
print 'Intercept: \n', fitted_model.intercept_
print 'Coefficients: \n', fitted_model.coef_

#atribui os coeficientes as variaveis a, b e c, sendo que o modelo seria dado por
#Vk = aVk1 + bVk2 + cVm
a = fitted_model.coef_[0]
b = fitted_model.coef_[1]
c = fitted_model.coef_[2]

pred = []
real = []
#compara os resultados reais com os resultados da regressao
for i in range(len(Vk)):
	#pode-se usar a funcao predict para achar a saida da regressao
	#pred += [fitted_model.predict([[Vk1[la], Vk2[la], Vm[la]]])[0]]

	#ou pode-se fazer manualmente isso, usando a formula do modelo
	pred += [a*Vk1[i] + b*Vk2[i] + c*Vm[i]]
	real += [Vk[i]]

#podemos plotar o grafico da regressao vs real
#plt.plot(pred, real)

#ou podemos plotar ambos os graficos na ordem em que aparecem
plt.plot(pred, 'bo')
plt.plot(real, 'r-')
plt.show()

#aqui usamos as formulas deduzidas para os parametros A, B e C, coeficientes do sistema continuo
#no caso
#         A
#   ------------
#   s^2 + Bs + C
T = 0.002
B = (-a/b - 2.)/T
A = (-c/b)/(T**2)
C = (-1.0/b - 1.0 - B*T)/(T**2)

#aqui, printamos o resultado.lucas
print 'A: ', A
print 'B: ', B
print 'C: ', C




#y = np.array()

	
