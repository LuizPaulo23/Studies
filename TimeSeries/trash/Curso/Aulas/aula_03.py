import pandas as pd
import numpy as np
import janitor
import matplotlib.pyplot as plt 


# Import Dataset 

data_raw = pd.read_csv("avocado.csv", parse_dates=["Date"])
data_clean = janitor.clean_names(data_raw)

# Summarizando 

data_summary = data_clean.groupby('date')['total_volume'].mean().reset_index()

print(data_summary)

#data_summary.set_index('date').plot()
# plt.show()

summr = data_summary.set_index('date')
summr['month'] = summr.index.month
print(summr)

grouped = summr.groupby('month')['total_volume'].agg(['mean', 'median', 'min', 'max'])
grouped.plot()
plt.show()
