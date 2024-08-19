import pandas as pd 
import numpy as np

ex_csv = pd.read_csv("female_birth.csv", parse_dates = [0], index_col = 0)
# print(ex_csv.head())

#t = ex_csv.squeeze("columns")
#print(t)

print(ex_csv.describe())

