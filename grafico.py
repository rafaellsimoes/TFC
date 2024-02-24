import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression

x1 = np.empty(1,dtype=object)

x1 = [10,25,50,100,150,200,250,300,350,400,450,500,550,700,800,900,1100,1500,2000,2500,3000,3500,4000,
      5000,6000,8000,12000,15000,20000,25000,30000,35000,40000,45000,50000,55000,60000,65000]

x2 = np.empty(1,dtype=object)

x2 = [0,0,0,0,0,0,0,0,0,0,0.012,0.0153,0.024,0.0309,0.0389,0.0569,0.0763,0.1425,0.3001,0.4251,0.6345,0.8427,
     1.1412,1.7119,2.4195,4.3125,9.4988,17.192,30.0413,46.5014,67.3234,98.0739,122.3442,146.7056,200.3288,234.7388,281.3392,
        317.4973]



df = pd.DataFrame({'X1':x1,'X2':x2})

#print(df.describe())
'''

plt.scatter(df['X1'],df['X2'],color='lightcoral')
plt.title('Tempo de processamento por tamano')
plt.xlabel('Tamanho do vetor')
plt.ylabel('Tempo')
plt.box(True)
plt.show()

#separação de variaveis
'''
x = df.iloc[:, :-1]  
y = df.iloc[:, -1] 

print(x)
print(y)

lr = LinearRegression()
lr.fit(x,y)

pol = PolynomialFeatures(degree=2)
x_pol = pol.fit_transform(x)
lr_2 = LinearRegression()
lr_2.fit(x_pol,y)

y_pred = lr.predict(x)
y_prd_pol = lr_2.predict(x_pol)

plt.scatter(x,y,color='purple')
#plt.plot(x,lr.predict(x),color='firebrick')
plt.plot(x, lr_2.predict(x_pol), color = 'red')
plt.title('Previsão com Regressão Polinomial (grau =2)')
plt.grid(True)
plt.show()
