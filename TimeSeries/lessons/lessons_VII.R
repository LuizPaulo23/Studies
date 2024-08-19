# Carregar pacotes necessários
library(forecast)
library(ggplot2)

# Carregar e visualizar os dados (exemplo: série mensal de vendas)
data("AirPassengers")
passengers_ts <- AirPassengers

# Ajustar modelo SES
modelo_ses <- ses(passengers_ts)
previsao_ses <- forecast(modelo_ses, h = 24)

# Ajustar modelo DES
modelo_des <- Holt(passengers_ts)
previsao_des <- forecast(modelo_des, h = 24)

# Ajustar modelo TES
modelo_tes <- stlm(passengers_ts, s.window = "periodic")
previsao_tes <- forecast(modelo_tes, h = 24)

# Plotar previsões
autoplot(previsao_ses) + autolayer(passengers_ts, series = "Série Original") + ggtitle("Previsão com SES") + xlab("Ano") + ylab("Número de Passageiros")
autoplot(previsao_des) + autolayer(passengers_ts, series = "Série Original") + ggtitle("Previsão com DES") + xlab("Ano") + ylab("Número de Passageiros")
autoplot(previsao_tes) + autolayer(passengers_ts, series = "Série Original") + ggtitle("Previsão com TES") + xlab("Ano") + ylab("Número de Passageiros")
