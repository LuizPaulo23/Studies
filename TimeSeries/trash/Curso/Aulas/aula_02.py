import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Ler o CSV e converter a coluna "Time" para datetime
data_raw = pd.read_csv("italy_earthquakes.csv")
data_raw["Time"] = pd.to_datetime(data_raw["Time"])

# Definir a coluna "Time" como índice
data_raw = data_raw.set_index("Time")

# Plotar a série temporal da coluna "Magnitude"
#plt.plot(data_raw.index, data_raw["Magnitude"])
#plt.xlabel('Time')
#plt.ylabel('Magnitude')
#plt.title('Magnitude of Earthquakes Over Time in Italy')
#plt.show()

res = data_raw["Magnitude"].resample("D").apply([np.mean])
#plt.plot(res)
#plt.show()

