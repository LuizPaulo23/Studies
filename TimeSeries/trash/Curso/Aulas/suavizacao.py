import pandas as pd 
import numpy as np
import matplotlib.pyplot as plt
from datetime import datetime 
from statsmodels.tsa.api import ExponentialSmoothing, SimpleExpSmoothing, Holt

data_raw = pd.read_csv("AirPassengers.csv", parse_dates = ['Month'], index_col = 'Month', date_format = '%Y-%m')
data_raw.rename(columns = {'#Passengers': 'passengers'}, inplace = True)
print(data_raw.describe())

data_raw.index.freq = 'MS' # \ Frequência mensal

# 20% de peso para observações mais recentes
# logo, passamos optimized como false 
SES = SimpleExpSmoothing(data_raw).fit(smoothing_level = 0.2, optimized = False)

forecast_ses = SES.forecast(12)

# Plotagem
plt.figure(figsize=(10, 6))
plt.plot(data_raw.index, data_raw, marker='o', color='black', label='Dados Originais')
plt.plot(SES.fittedvalues.index, SES.fittedvalues, marker='.', color='red', label='Valores Ajustados')
plt.plot(forecast_ses.index, forecast_ses, marker='.', color='blue', label='Previsão')
plt.legend()
plt.show()


# optimized = True

SES = SimpleExpSmoothing(data_raw).fit(optimized = True)

forecast_ses = SES.forecast(12)

# Plotagem
plt.figure(figsize=(10, 6))
plt.plot(data_raw.index, data_raw, marker='o', color='black', label='Dados Originais')
plt.plot(SES.fittedvalues.index, SES.fittedvalues, marker='.', color='red', label='Valores Ajustados')
plt.plot(forecast_ses.index, forecast_ses, marker='.', color='blue', label='Previsão')
plt.legend()
plt.show()


# O quanto a tendência influencia 
# Smoothing_trend (beta) 80%  de influência da tendência mais atual 

model_holt = Holt(data_raw).fit(smoothing_level = 0.2, smoothing_trend = 0.8, optimized = False)
forecast_holt = model_holt.forecast(12)

# Plotagem
plt.figure(figsize=(10, 6))
plt.plot(data_raw.index, data_raw, marker='o', color='black', label='Dados Originais')
# plt.plot(model_holt.fittedvalues.index, model_holt , marker='.', color='red', label='Valores Ajustados')
plt.plot(forecast_holt.index, forecast_holt, marker='.', color='blue', label='Previsão')
plt.legend()
plt.show()


# Amortização \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

model_holt = Holt(data_raw, damped_trend = True).fit(optimized = True)
forecast_holt = model_holt.forecast(12)

# Plotagem
plt.figure(figsize=(10, 6))
plt.plot(data_raw.index, data_raw, marker='o', color='black', label='Dados Originais')
# plt.plot(model_holt.fittedvalues.index, model_holt , marker='.', color='red', label='Valores Ajustados')
plt.plot(forecast_holt.index, forecast_holt, marker='.', color='blue', label='Previsão')
plt.legend()
plt.show()

# Holt Winters \\\\\\\\\\\
# Sazonal ++ aditivo 