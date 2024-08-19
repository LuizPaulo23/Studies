###################################################################
###    SÉRIES TEMPORAIS COM REDES NEURAIS ALIMENTADAS ADIANTE   ###
###           (FEED-FORWARD) COM UMA CAMADA OCULTA              ###
###################################################################

###############################################
######   Desvios da Temperatura Global   ######
###############################################

### IMPORTAÇÃO DA SÉRIE TEMPORAL

install.packages('astsa')
library(astsa)
?globtemp
temp_global <- ts(globtemp, start = 1880, end = 2015,
                  frequency = 1)
print(temp_global)
plot(temp_global, type="l", ylab="Desvios da Temperatura",
     col="blue")


### CRIAÇÃO DO MODELO
library(forecast)
?nnetar
modelo <- nnetar(temp_global,p = 19, size = 10)
print(modelo)

checkresiduals(modelo)

plot(temp_global)
lines(temp_global-modelo$resid, col= "red")




### PREVISÃO
previsao <- forecast(modelo, h = 12)
print(previsao)

plot(previsao)
lines(temp_global-modelo$resid, col= "red")




### CRIAÇÃO DE UM DATAFRAME COM VALORES REAIS E AJUSTADOS

library(dplyr)
ajuste <- fitted.values(modelo)
print(ajuste)

metrica <- as.data.frame(ajuste)
View(metrica)

metrica <- rename(metrica, valores_ajustados = x)
metrica$valores_reais <- temp_global
metrica <- slice(metrica, -c(1:19))



### MÉTRICAS DE DESEMPENHO ###

install.packages('MLmetrics')
library(MLmetrics)

# ERRO MÉDIO ABSOLUTO (MAE)
MAE(metrica$valores_ajustados, metrica$valores_reais)

# ERRO QUADRÁTICO MÉDIO (MSE)
MSE(metrica$valores_ajustados, metrica$valores_reais)

# RAIZ DO ERRO QUADRÁTICO MÉDIO (RMSE)
RMSE(metrica$valores_ajustados, metrica$valores_reais)










# SEPARANDO EM DADOS DE TREINO E TESTE

# Desvios da Temperatura Global

# TREINO
temp_treino <- ts(globtemp, start = 1880, end = 2000,
                  frequency = 1)
print(temp_treino)

# TESTE
library(dplyr)
temp_teste <- globtemp
print(temp_teste)
temp_teste <- as.data.frame(temp_teste)
View(temp_teste)
temp_teste <- slice(temp_teste, c(122:136))


# Criação do Modelo
modelo2 <- nnetar(temp_treino,p = 19, size = 10)
print(modelo2)

### PREVISÃO
previsao2 <- forecast(modelo2, h=15)
plot(previsao2)


### CRIAÇÃO DE UM DATAFRAME COM VALORES REAIS E PREVISTOS

previsao2 <- as.data.frame(previsao2)
View(previsao2)


### MÉTRICAS DE DESEMPENHO ###

# Juntar dois dataframes
metrica2 <- bind_cols(previsao2,temp_teste)
View(metrica2)

metrica2 <- rename(metrica2, previsao = 'Point Forecast')
metrica2 <- rename(metrica2, real = x)

glimpse(metrica2)


library(MLmetrics)
# ERRO MÉDIO ABSOLUTO (MAE)
MAE(metrica2$previsao, metrica2$real)

# ERRO QUADRÁTICO MÉDIO (MSE)
MSE(metrica2$previsao, metrica2$real)

# RAIZ DO ERRO QUADRÁTICO MÉDIO (RMSE)
RMSE(metrica2$previsao, metrica2$real)























