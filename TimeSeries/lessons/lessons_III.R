base::rm(list = ls())
# Carregar pacotes
library(ggplot2)
library(forecast)

# Criando dados fictícios de vendas mensais
vendas <- c(200, 215, 230, 245, 260, 275, 290, 305, 320, 335, 350, 365,
            380, 395, 410, 425, 440, 455, 470, 485, 500, 515, 530, 545)

# Convertendo os dados em uma série temporal
vendas_ts <- ts(vendas, start = c(2020, 1), frequency = 12)

# Visualizando a série temporal
plot(vendas_ts, main = "Vendas Mensais", xlab = "Ano", ylab = "Vendas")

# Ajustar modelo AR(1)
modelo_ar1 <- Arima(vendas_ts, order = c(1, 0, 0))
summary(modelo_ar1)

# Ajustar modelo MA(1)
modelo_ma1 <- Arima(vendas_ts, order = c(0, 0, 1))
summary(modelo_ma1)

# Ajustar modelo ARMA(1,1)
modelo_arma11 <- Arima(vendas_ts, order = c(1, 0, 1))
summary(modelo_arma11)

# Plotar diagnósticos do modelo AR(1)
checkresiduals(modelo_ar1)

# Plotar diagnósticos do modelo MA(1)
checkresiduals(modelo_ma1)

# Plotar diagnósticos do modelo ARMA(1,1)
checkresiduals(modelo_arma11)


