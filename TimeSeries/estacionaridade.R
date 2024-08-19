#' @title Testes de estacionariedade 
#' @author Luiz Paulo 

base::rm(list = ls())
graphics.off()
set.seed(123)

# Dependências 

pacman::p_load(stats, urca)

# Series 

serie <- stats::ts(rnorm(41), start = 1980, end = 2020, frequency = 1)
plot(serie)

# Teste KPSS (Kwiatkowski-Phillips-Schmidt-Shin)

# Ho = nao é estacionario: teste estatistico > valor critico
# Ha =  estacionario:  teste estatistico < valor critico

kpss <- urca::ur.kpss(serie)
summary(kpss)

# Teste pp (Philips-Perron)

# Ho =  é estacionario: p > 0.05
# Ha = nao  estacionario: p <= 0.05

pp <- urca::ur.pp(serie)
summary(pp)

# Teste df (Dickey Fuller)

# Ho = nao estacion?rio: teste estatistico > valor critico
# Ha = estacionario:  teste estatistico < valor critico

df <- ur.df(serie)
summary(df)
