
concentracao <- co2
print(concentracao)
plot(concentracao)

# Decomposi??o
# install.packages('forecast')
library(forecast)
decomposicao <-   decompose(concentracao)
plot(decomposicao)

decomposicao <-  decompose(concentracao, type = "mult")
autoplot(decomposicao)




# Manchas Solares

manchas_solares <- sunspots
sunspots
plot(sunspots)

# Decomposi??o
decomposicao2 <- decompose(manchas_solares)
plot(decomposicao2)

decomposicao3 <- decompose(manchas_solares, type = "mult")
plot(decomposicao3)




# Suaviza??o (outliers)
suavizacao <- tsclean(manchas_solares)
plot(suavizacao)

# Compara??o com o original
plot(manchas_solares)
lines(suavizacao, col="red")




# Desvios da Temperatura Global 
install.packages('astsa')
library(astsa)
globtemp
temp_global <- ts(globtemp, start = 1 , end = 68, frequency = 2)
print(temp_global)
plot(temp_global, type="l", ylab="Desvios da Temperatura",col="blue")


# Decomposi??o
decomposicao4 <- decompose(temp_global)
autoplot(decomposicao4)




