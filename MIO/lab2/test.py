import numpy as np
import matplotlib.pyplot as plt
import random
from sklearn.linear_model import Perceptron

n = [2, 5, 10, 20, 100]

# Proszę wygenerować po 400 2-wymiarowych
# punktów przypisanych do dwóch klas K1 i K2, 
# pochodzących z rozkładów normalnych N([0,-1],1) i N([1,1],1) i podzielić je losowo na zbiory uczące i testujące w proporcji N do 400-N.

K1 = np.random.multivariate_normal([0, -1], [[1, 0], [0, 1]], 400)
K2 = np.random.multivariate_normal([1, 1], [[1, 0], [0, 1]], 400)

j = 0
for i in n:
  K1_train = K1[:i]
  K1_test = K1[i:]
  K2_train = K2[:i]
  K2_test = K2[i:]
  y = [0]*i + [1]*i # przyporządkowanie klasy do punktów K1 i K2

  j+=1
  neuron = Perceptron(tol=1e-3, max_iter = 20)
  neuron.fit(np.concatenate((K1_train, K2_train)), y)
  x1 = np.linspace(-2,2,100)
  x2 = -(1./neuron.coef_[0][1])*(neuron.coef_[0][0]*x1+neuron.intercept_[0])
  
  plt.plot(x1, x2, '-r')
  plt.scatter(K1_train[:,0], K1_train[:,1], c='b', label='K1_train')
  plt.scatter(K2_train[:,0], K2_train[:,1], c='g', label='K2_train')
  plt.grid(True)
  plt.show()

	#print wzór prostej
  print("y="+str(-neuron.coef_[0][0]/neuron.coef_[0][1])+"x+"+str(-neuron.intercept_[0]/neuron.coef_[0][1]))
  print(neuron.score(np.concatenate((K1_test, K2_test)), [0]*len(K1_test) + [1]*len(K2_test)))