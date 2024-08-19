import pandas as pd
import matplotlib.pyplot as plt
from pandas.plotting import register_matplotlib_converters
register_matplotlib_converters()

dateparse = lambda dates: pd.to_datetime(dates, format="%Y-%m")
data_raw = pd.read_csv("AirPassengers.csv", parse_dates=["Month"], index_col="Month", date_parser=dateparse)
print(data_raw.head())


# Plotar os dados
plt.plot(data_raw)
plt.title('Air Passengers Over Time')
plt.xlabel('Date')
plt.ylabel('Number of Passengers')
plt.show()
