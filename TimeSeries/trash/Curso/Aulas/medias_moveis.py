import pandas as pd
import numpy as np
import matplotlib.pyplot as plt 

data_raw = pd.read_csv("all_stocks.csv", index_col = 'Date', parse_dates = ["Date"])

g_stock = data_raw.query('Name == "GOOGL"')
print(g_stock.describe())

g_stk = g_stock.copy()
g_stk['Ticks'] =  range(0, len(g_stk))
print(g_stk)


g_stk['rolling_mean'] =  g_stk['Open'].rolling(window = 80).mean()

g_stk.plot('Ticks', 'Open')
plt.show()