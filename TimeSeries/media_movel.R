########################
###    MÉDIA MÓVEL   ###
########################


# Desvios da Temperatura Global 
install.packages('astsa')
library(astsa)
?globtemp
temp_global <- ts(globtemp, start = c(1880), end = c(2015), frequency = 1)
print(temp_global)
plot(temp_global, type="l", ylab="Desvios da Temperatura",col="blue")


# Média móvel
library(forecast)
?ma
temp_global2 <- ma(temp_global, order = 7)
plot(temp_global2)

temp_global3 <- ma(temp_global, order = 20, centre = TRUE)
plot(temp_global3)

temp_global4 <- ma(temp_global, order = 51, centre = TRUE)
plot(temp_global4)

plot(temp_global)
lines(temp_global2, col = "red")
lines(temp_global3, col = "green")
lines(temp_global4, col = "blue")




