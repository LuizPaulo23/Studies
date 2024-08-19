
set.seed(8)
dados = rnorm(72)
serie = ts(dados,start = c(2015,1), end=c(2020,12), frequency=12)
print(serie)
plot(serie)
acf(serie)
pacf(serie)

# Teste de Autocorrelação (Ljung-Box)

# Ho = não é autocorrelacionado: p > 0.05
# Ha = é autocorrelacionado: p <= 0.05

Box.test (serie, type = "Ljung")
