# Assimetria e Curtose 
# Author: Luiz Paulo Tavares 

# 1º Coeficiente de Assimetria de Pearson 

def first_asymmetry_coef(mean, moda, std): 
    if std == 0: 
        print("Resultado infefinido!")
        return None
    return (mean - moda)/std

# 2º Coeficiente de Assimetria de Pearson 

def second_asymmetry_coef(mean, median, std):
    if std == 0:
        print("Resultado indefinido!")
        return None
    return 3 * (mean - median) / std

#print(first_asymmetry_coef(moda=8, mean=7.8, std=1))
print(second_asymmetry_coef(mean=16, median=15.4, std=6))



