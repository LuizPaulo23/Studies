import pandas as pd 
import numpy as np 
import matplotlib.pyplot as plt 
from pandas.plotting import register_matplotlib_converters
import statsmodels.tsa
import statsmodels.tsa.stattools
register_matplotlib_converters()
from matplotlib.pylab import rcParams
from datetime import datetime
import janitor

# Importar o dataset e fazer a limpeza

data_raw = pd.read_csv("AirPassengers.csv", parse_dates = ["Month"], index_col = 'Month', date_format = "%Y-%m")
data_raw.rename(columns = {'#Passengers': 'passengers'}, inplace = True)


# Visualizando a série

#plt.plot(data_raw['passengers'])
#plt.xlabel('Date')
#plt.ylabel('Number of Passengers')
#plt.title('Monthly Number of Air Passengers')
#plt.show()

from statsmodels.tsa.seasonal import seasonal_decompose
from statsmodels.tsa.stattools import adfuller
# import statsmodels

decompose = seasonal_decompose(data_raw, model = 'aditive')
decompose.plot()
plt.show()


data_log = np.log(data_raw)

data_log.plot()
plt.show()

#data_diff = np.diff(data_raw['passengers'], n = 1)

#data_diff.plot()
#plt.show()

adf_nominal = adfuller(data_raw)
adf_log = adfuller(data_log)
#adf_diff = adfuller(data_diff)

print(adf_nominal[1])
print(adf_log[1])
print(adf_diff[1])
