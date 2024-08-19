import pandas as pd 
import numpy as np 
import matplotlib.pyplot as plt 
from sklearn.linear_model import LinearRegression

# Importar o dataset e fazer a limpeza

data_raw = pd.read_csv("AirPassengers.csv", parse_dates = ["Month"], index_col = 'Month', date_format = "%Y-%m")
data_raw.rename(columns = {"#Passengers" : "passengers"}, inplace = True)

X = np.array(range(len(data_raw))).reshape(-1,1)
y = data_raw.values

model_lm = LinearRegression()
model_lm.fit(X, y)

trend = model_lm.predict(X)
detrended = y - trend

plt.plot(y, label = "Série Original")
plt.plot(trend, label = "Tendência")
plt.plot(detrended, label = "Sem Tendência")
plt.legend()
plt.show()


seasonal_difference = detrended[12:] - detrended[:-12]
deseasonalized = seasonal_difference

plt.plot(detrended, label = "Original sem tendência")
plt.plot(deseasonalized, label = "Dessaz")
plt.legend()
plt.show()