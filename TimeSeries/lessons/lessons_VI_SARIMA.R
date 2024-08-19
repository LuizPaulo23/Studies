# Carregar pacotes necessários
library(forecast)
library(ggplot2)
library(tseries)

# Carregar o conjunto de dados AirPassengers
data("AirPassengers")
passengers_ts <- AirPassengers

# Visualizar a série temporal
autoplot(passengers_ts) + ggtitle("Número de Passageiros Aéreos (1949-1960)") + xlab("Ano") + ylab("Milhares de Passageiros")

# Teste de Dickey-Fuller aumentado
adf_test <- adf.test(passengers_ts)
print(adf_test)

# Diferenciação não sazonal e sazonal
passengers_diff <- diff(passengers_ts, differences = 1)
passengers_diff_seasonal <- diff(passengers_diff, lag = 12)

# Visualizar a série diferenciada
autoplot(passengers_diff_seasonal) + ggtitle("Número de Passageiros Aéreos Diferenciado") + xlab("Ano") + ylab("Diferença no Número de Passageiros")

# Plotar ACF e PACF da série diferenciada
acf_passengers_diff_seasonal <- Acf(passengers_diff_seasonal, main = "ACF da Série Diferenciada Sazonalmente")
pacf_passengers_diff_seasonal <- Pacf(passengers_diff_seasonal, main = "PACF da Série Diferenciada Sazonalmente")

# Ajustar o modelo SARIMA
modelo_sarima <- auto.arima(passengers_ts, seasonal = TRUE)
summary(modelo_sarima)

# Diagnóstico dos resíduos
checkresiduals(modelo_sarima)

# Fazer previsões para os próximos 24 meses
previsao_sarima <- forecast(modelo_sarima, h = 24)
autoplot(previsao_sarima) + ggtitle("Previsão do Número de Passageiros Aéreos com SARIMA") + xlab("Ano") + ylab("Milhares de Passageiros")
