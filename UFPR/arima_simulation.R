
get_arima_stationary <- function(n, phi){
  
  set.seed(123)
  
  epsilon <- rnorm(n)
  Y <- numeric(n)
  Y[1] <- epsilon[1]
  
  # Gerar a série temporal AR(1)
  
  for(t in 2:n) {
    Y[t] <- phi * Y[t-1] + epsilon[t]
  }
  
  return(Y)
  
}

ar = get_arima_stationary(n = 200, phi = 0.7) %>% as.data.frame()


plot(ar$., type = "l", main = "Série Temporal AR(1)", ylab = "X_t", xlab = "Tempo")


