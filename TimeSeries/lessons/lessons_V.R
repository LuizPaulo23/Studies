# Carregar pacotes necessários
library(forecast)
library(ggplot2)
library(tseries)

# Criar uma série temporal fictícia de vendas mensais com tendência
set.seed(123)
vendas <- cumsum(rnorm(120, mean = 10, sd = 5))  # Vendas mensais com tendência
vendas_ts <- ts(vendas, start = c(2020, 1), frequency = 12)

# Criar uma variável exógena fictícia (por exemplo, campanhas de marketing)
marketing <- rnorm(120, mean = 20, sd = 5)
marketing_ts <- ts(marketing, start = c(2020, 1), frequency = 12)

# Visualizar a série temporal e a variável exógena
autoplot(vendas_ts) + ggtitle("Vendas Mensais") + xlab("Ano") + ylab("Vendas")
autoplot(marketing_ts) + ggtitle("Campanhas de Marketing Mensais") + xlab("Ano") + ylab("Gastos em Marketing")

# Teste de Dickey-Fuller aumentado para a série de vendas
adf_test_vendas <- adf.test(vendas_ts)
print(adf_test_vendas)

# Teste de Dickey-Fuller aumentado para a variável exógena
adf_test_marketing <- adf.test(marketing_ts)
print(adf_test_marketing)

# Diferenciar a série de vendas (primeira diferença)
vendas_diff <- diff(vendas_ts)
marketing_diff <- diff(marketing_ts)

# Visualizar a série diferenciada
autoplot(vendas_diff) + ggtitle("Vendas Mensais Diferenciadas") + xlab("Ano") + ylab("Diferença nas Vendas")
autoplot(marketing_diff) + ggtitle("Campanhas de Marketing Mensais Diferenciadas") + xlab("Ano") + ylab("Diferença nos Gastos em Marketing")

# Ajustar o modelo ARIMAX
modelo_arimax <- auto.arima(vendas_ts, xreg = marketing_ts)
summary(modelo_arimax)

# Diagnóstico dos resíduos
checkresiduals(modelo_arimax)


