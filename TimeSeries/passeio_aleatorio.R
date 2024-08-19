

dados1 <- runif(41, min = 0, max = 100)
s1 <- ts(dados1, start = 1980, end=2020, frequency=1)
plot(s1)

# Com reposição 

dados2 <- sample(0:100, 41, replace = TRUE)
serie2 = ts(dados2, start = c(1980), end=c(2020), frequency=1)
plot(serie2)


passeio <- numeric()
passeio[1] <- rnorm(1,0,1) 
for(t in 2:2000){
  passeio[t]=passeio[t-1]+rnorm(1,0,1)
}

plot.ts(passeio, main="Passeio Aleatário",col="red")



