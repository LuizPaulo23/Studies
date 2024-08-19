# Carregar pacotes
library(ggplot2)
library(forecast)

# Criando dados fictícios de vendas mensais com tendência
set.seed(123)
vendas <- cumsum(rnorm(120, mean = 10, sd = 5))  # Vendas mensais com tendência
vendas_ts <- ts(vendas, start = c(2020, 1), frequency = 12)

# Visualizando a série temporal
plot(vendas_ts, main = "Vendas Mensais", xlab = "Ano", ylab = "Vendas")

# Plotar ACF e PACF da série original
acf_vendas <- Acf(vendas_ts, main = "Função de Autocorrelação (ACF) - Série Original")
pacf_vendas <- Pacf(vendas_ts, main = "Função de Autocorrelação Parcial (PACF) - Série Original")

# Diferenciar a série (primeira diferença)
vendas_diff <- diff(vendas_ts)

# Visualizar a série diferenciada
plot(vendas_diff, main = "Vendas Mensais Diferenciadas", xlab = "Ano", ylab = "Diferença nas Vendas")

# Plotar ACF e PACF da série diferenciada
acf_vendas_diff <- Acf(vendas_diff, main = "Função de Autocorrelação (ACF) - Série Diferenciada")
pacf_vendas_diff <- Pacf(vendas_diff, main = "Função de Autocorrelação Parcial (PACF) - Série Diferenciada")

# Ajustar modelo ARIMA
modelo_arima <- auto.arima(vendas_ts)
summary(modelo_arima)

# Diagnóstico dos resíduos
checkresiduals(modelo_arima)


#################################################################################

# Carregar pacotes necessários
library(forecast)
library(ggplot2)

# Carregar o conjunto de dados AirPassengers
data("AirPassengers")
passengers_ts <- AirPassengers

# Visualizar a série temporal
autoplot(passengers_ts) + ggtitle("Número de Passageiros Aéreos (1949-1960)") + xlab("Ano") + ylab("Milhares de Passageiros")
# Teste de Dickey-Fuller aumentado
library(tseries)
adf_test <- adf.test(passengers_ts)
print(adf_test)

# Se o p-valor do teste for menor que 0.05, rejeitamos a hipótese nula de que a série possui uma raiz unitária (não estacionária).
# Caso contrário, não rejeitamos a hipótese nula.

# Diferenciar a série (primeira diferença)
passengers_diff <- diff(passengers_ts, differences = 1)

# Visualizar a série diferenciada
autoplot(passengers_diff) + ggtitle("Número de Passageiros Aéreos Diferenciado (1949-1960)") + xlab("Ano") + ylab("Diferença no Número de Passageiros")

# Plotar ACF e PACF da série diferenciada
acf_passengers_diff <- Acf(passengers_diff, main = "ACF da Série Diferenciada")
pacf_passengers_diff <- Pacf(passengers_diff, main = "PACF da Série Diferenciada")

# Ajustar o modelo ARIMA
modelo_arima <- auto.arima(passengers_ts)
summary(modelo_arima)
# Diagnóstico dos resíduos
checkresiduals(modelo_arima)

# Fazer previsões para os próximos 24 meses
previsao <- forecast(modelo_arima, h = 24)
autoplot(previsao) + ggtitle("Previsão do Número de Passageiros Aéreos") + xlab("Ano") + ylab("Milhares de Passageiros")


