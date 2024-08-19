# Carregar pacotes necessários
library(forecast)
library(ggplot2)
library(tseries)

# Criar uma série temporal fictícia de vendas mensais com tendência
set.seed(123)
vendas <- cumsum(rnorm(120, mean = 10, sd = 5))
vendas_ts <- ts(vendas, start = c(2020, 1), frequency = 12)

# Criar duas variáveis exógenas fictícias (ex: campanhas de marketing e promoções)
marketing <- rnorm(120, mean = 20, sd = 5)
promocoes <- rnorm(120, mean = 15, sd = 3)
marketing_ts <- ts(marketing, start = c(2020, 1), frequency = 12)
promocoes_ts <- ts(promocoes, start = c(2020, 1), frequency = 12)

# Visualizar a série temporal e as variáveis exógenas
autoplot(vendas_ts) + ggtitle("Vendas Mensais") + xlab("Ano") + ylab("Vendas")
autoplot(marketing_ts) + ggtitle("Campanhas de Marketing Mensais") + xlab("Ano") + ylab("Gastos em Marketing")
autoplot(promocoes_ts) + ggtitle("Promoções Mensais") + xlab("Ano") + ylab("Gastos em Promoções")

# Teste de Dickey-Fuller aumentado para a série de vendas
adf_test_vendas <- adf.test(vendas_ts)
print(adf_test_vendas)

# Teste de Dickey-Fuller aumentado para as variáveis exógenas
adf_test_marketing <- adf.test(marketing_ts)
print(adf_test_marketing)

adf_test_promocoes <- adf.test(promocoes_ts)
print(adf_test_promocoes)

# Diferenciar a série de vendas (primeira diferença)
vendas_diff <- diff(vendas_ts)
marketing_diff <- diff(marketing_ts)
promocoes_diff <- diff(promocoes_ts)

# Visualizar as séries diferenciadas
autoplot(vendas_diff) + ggtitle("Vendas Mensais Diferenciadas") + xlab("Ano") + ylab("Diferença nas Vendas")
autoplot(marketing_diff) + ggtitle("Campanhas de Marketing Mensais Diferenciadas") + xlab("Ano") + ylab("Diferença nos Gastos em Marketing")
autoplot(promocoes_diff) + ggtitle("Promoções Mensais Diferenciadas") + xlab("Ano") + ylab("Diferença nos Gastos em Promoções")

# Ajustar o modelo ARIMAX com duas variáveis exógenas
xreg <- cbind(marketing_ts, promocoes_ts)
modelo_arimax <- auto.arima(vendas_ts, xreg = xreg)
summary(modelo_arimax)

# Diagnóstico dos resíduos
checkresiduals(modelo_arimax)

# Previsão para os próximos 24 meses (assumindo valores futuros das variáveis exógenas)
future_marketing <- rnorm(24, mean = 20, sd = 5)
future_promocoes <- rnorm(24, mean = 15, sd = 3)
future_xreg <- cbind(future_marketing, future_promocoes)

previsao_arimax <- forecast(modelo_arimax, xreg = future_xreg, h = 24)
autoplot(previsao_arimax) + ggtitle("Previsão de Vendas com ARIMAX") + xlab("Ano") + ylab("Vendas")

