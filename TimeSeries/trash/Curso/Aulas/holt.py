import pandas as pd 
import numpy as np
import matplotlib.pyplot as plt 
import datetime as time
from statsmodels.tsa.api import ExponentialSmoothing, SimpleExpSmoothing, Holt

data_raw = pd.read_csv("AirPassengers.csv", parse_dates = ['Month'], index_col = 'Month', date_format = '%Y-%m')
data_raw.rename(columns = {'#Passengers': 'passengers'}, inplace = True)
print(data_raw.describe())

data_raw.index.freq = 'MS' # \ Frequência mensal

ES = ExponentialSmoothing(data_raw, seasonal_periods = 12, trend = "additive", use_boxcox = True).fit()
ES.fittedvalues.plot(style = '--', color = "purple")
plt.show()