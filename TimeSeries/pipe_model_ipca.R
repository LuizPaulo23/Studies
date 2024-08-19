#' @title Model IPCA
#' @author Luiz Paulo Tavares Gonçalves 

base::rm(list = ls())
grDevices::graphics.off()

# Dependências =================================================================
# update.packages(ask = FALSE, checkBuilt = TRUE)
# install.packages()
# library(pacman)

pacman::p_load(tidyverse,
               forecast,
               DataExplorer, 
               sidrar,
               janitor,
               stats,
               TSstudio, 
               BETS, 
               urca)

# Importando a base de dados do IPCA ===================================================
# https://www.ibge.gov.br/estatisticas/economicas/precos-e-custos/9256-indice-nacional-de-precos-ao-consumidor-amplo.html?=&t=series-historicas

ipca_raw = BETS::BETSget(433, from = "2000-01-01", data.frame = TRUE) %>% 
           dplyr::rename(rate = value) %>% 
                  mutate(year = base::substr(date, start = 1, stop = 4),
                         month = base::substr(date, start = 6, stop = 7)) %>% 
                  relocate(rate, .after = month)

# Última atualização: 10/2023
# writexl::write_xlsx(ipca_raw, base::paste0("ipca", "_", Sys.Date(), ".xlsx"))

ts_ipca = stats::ts(ipca_raw$rate, start = c(2000, 1), end = c(2023,10), frequency = 12)
print(ts_ipca)

# Análise exploratória =========================================================

TSstudio::ts_plot(ts.obj = ts_ipca, title = "Variação mensal do IPCA", color = "red")

# Distribuição dos dados -------------------------------------------------------

# Distribuição geral  
# Testando a normalidade 

ggplot2::ggplot(ipca_raw, aes(x = rate)) +                           
         geom_histogram(aes(y = ..density..),
                        fill = "blue", alpha = 0.5) +
        geom_density(alpha = 0.5, fill = "red")+
        labs(title = "Densidade: IPCA", 
             subtitle = paste0("Teste de Shapiro-Wilk com o p-valor: ", stats::shapiro.test(ipca_raw$rate)[2]),
             x = "Variação mensal do IPCA", 
             y = "Densidade")+
        theme_bw()

# Sazonalidade -----------------------------------------------------------------

TSstudio::ts_seasonal(ts_ipca, type = "box", title = "BoxPlot - Sazonalidade") 
TSstudio::ts_heatmap(ts_ipca, padding = T, title = "HeatMap - Sazonalidade")

forecast::ggseasonplot(ts_ipca, polar = T)+
          labs(title = "Verificando possíveis pontos de sazonalidade", 
               caption = "Fonte: elaboração de Luiz Paulo Tavares Gonçalves",
               x = "Meses",
               y = "IPCA")+
          theme_bw()+
          theme(legend.position = "none", 
                plot.caption = element_text(hjust = 0))

forecast::ggseasonplot(ts_ipca)+
          labs(title = "",
               col = "", 
               y = "Variação do IPCA")+
          theme_bw()

forecast::ggsubseriesplot(ts_ipca)+
          labs(title = "",
               col = "",
               y = "Variação do IPCA")+
          theme_bw()

# Espera-se um aumento no final do ano 

# Autocorrelação ---------------------------------------------------------------
# Há um evidente autocorrelação 

forecast::ggAcf(ts_ipca) + 
          labs(title = "ACF - IPCA") + theme_bw()

forecast::ggPacf(ts_ipca)+
          labs(title = "PACF - IPCA") + theme_bw()

TSstudio::ts_lags(ts_ipca, lags = 1:12) # Autocorrelação 

# gglagplot(ts_ipca)

# Teste de raíz unitária -------------------------------------------------------

# Teste KPSS (Kwiatkowski-Phillips-Schmidt-Shin)

# Ho = nao é estacionario: teste estatistico > valor critico
# Ha =  estacionario:  teste estatistico < valor critico

kpss <- urca::ur.kpss(ts_ipca)
summary(kpss)

# Teste pp (Philips-Perron)

# Ho =  é estacionario: p > 0.05
# Ha = nao  estacionario: p <= 0.05

pp <- urca::ur.pp(ts_ipca)
summary(pp)

# Teste df (Dickey Fuller)

# Ho = nao estacion?rio: teste estatistico > valor critico
# Ha = estacionario:  teste estatistico < valor critico

df <- ur.df(ts_ipca)
summary(df)

# Decomposição e ajuste sazonal ------------------------------------------------

TSstudio::ts_decompose(ts_ipca)# Decomposição da série

# Aplicar ajuste sazonal usando a decomposição da serie

ts_decompose = stats::decompose(ts_ipca, type = "additive")

ipca_raw <- ipca_raw %>% 
            mutate(rate_sazonal = rate - ts_decompose$seasonal)

# Estatística Descritiva  ------------------------------------------------------

ipca_stats = ipca_raw %>%
             dplyr::group_by(month) %>%
                    summarise(mean = mean(rate),
                              mean_rate_sazonal = mean(rate_sazonal),
                              mediana = median(rate),
                              mediana_rate_sazonal = median(rate_sazonal),
                              Desvio = sd(rate), 
                              Desvio_sazonal = sd(rate_sazonal)) %>% print()

# BootStrap ====================================================================
# rate_mean = base::mean(ipca_raw$rate) %>% print()

boot_mean <- function(data, indices) {
  
  mean_value <- mean(data[indices])
  return(mean_value)
  
}

n_iterations = 10000 # Número de repetições para o bootstrap

# Executando o bootstrap

boot_geral <- boot::boot(data = ipca_raw$rate,
                         statistic = boot_mean,
                         R = n_iterations)

ipca_month = ipca_raw %>% filter(month == "11") 

boot_month <- boot::boot(data = ipca_month$rate,
                         statistic = boot_mean,
                         R = n_iterations)

# Visualizando os resultados do bootstrap 

hist(boot_geral)
hist(boot_month)
base::mean(boot_geral[["t"]])
base::mean(boot_month[["t"]])

## Ajuste sazonal X13 - ARIMA 

# ajuste <- seasonal::seas(x = ts_ipca)
# summary(ajuste)
# 
# seasonal::final(ajuste) 
# plot(ajuste)

# Suavização exponencial simples (SES) =========================================
# Estacionária e sem a presença de sazonalidade 
# beta e gamma == FALSE

model_ses = HoltWinters(ipca_raw$rate_sazonal, beta = F, gamma = F)
print(model_ses)
plot(model_ses)
model_ses$alpha # valor longe de zero
# informação recente explicam muito os movimentos da série

forecast_ses = forecast::forecast(model_ses, h = 12, level = 95)

# previsão 

plot(forecast_ses, main = "Previsão SES")

# Suavização Exponencial de Holt (SEH)
# previsões em séries que apresentam o efeito de tendência linear

model_seh <- stats::HoltWinters(ipca_raw$rate_sazonal, gamma = F)
print(model_seh)

# encontrou alfa e beta 
# pesos maiores em observações recentes
# tendência representa o oposto 

plot(model_seh)

forecast_seh = forecast::forecast(model_seh, h = 12, level = 95)
print(forecast_seh)
plot(forecast_seh)

# Suavização exponencial sazonal de holt-winters 

model_hw = stats::HoltWinters(ipca_raw$rate_sazonal)
print(model_hw)
plot(model_hw)

forecast_hw = forecast::forecast(model_hw, h = 12, level = 95)
print(forecast_hw)
# Model: Neural Network Autoregressive Model (NNAR)

model_nnar = forecast::nnetar(ipca_raw$rate_sazonal, p = 2, size = 10)
print(model_nnar)
checkresiduals(model_nnar)

plot(ipca_raw$rate_sazonal)
lines(ipca_raw$rate_sazonal - model_nnar$residuals, col= "red")

previsao <- forecast::forecast(model_nnar, h = 12, level = 95)
print(previsao)
plot(previsao)

##### Análise ------------------------------------------------------------------

model_linear <- stats::lm(formula = rate ~ date, ipca_raw)
summary(model_linear)

ipca_raw %>% glimpse()



ggplot(ipca_raw, aes(x = date, y = rate)) +
  geom_line(color = "steelblue") +
  scale_y_continuous(labels = scales::number_format()) +
  geom_smooth(method = lm)+
  #geom_line(aes(y = predict(model_linear))) + 
  theme_bw()

# Primeira diferença 
ipca_modificado = ipca_raw %>% 
mutate(primeira_diferenca = rate - lag(rate)) %>% 
    na.omit()

acf(ipca_modificado$primeira_diferenca)

# média móvel 
library(data.table)
ipca_modificado <- ipca_modificado %>%
  mutate(
    media_movel_3_meses = frollmean(rate, 3),
    media_movel_6_meses = frollmean(rate, 6),
    media_movel_9_meses = frollmean(rate, 9),
    media_movel_12_meses = frollmean(rate, 12)
  )

# dataset %>%
#   kbl() %>%
#   kable_material() %>%
#   scroll_box(width = "800px", height = "350px")


