#' @title Bootstrap Automatizado 
#' @author Luiz Paulo Tavares Gonçalves 

# Configurando ambiente de trabalho ============================================

base::rm(list = ls())
grDevices::graphics.off()

# Dependências 

pacman::p_load(tidyverse, crypto2, stats, boot)

# Constante Global 

START_PRICE = "20140101" # A partir do período no qual há volume transacionado registrado na API
TODAY = Sys.Date() |> print()

# Importando database ==========================================================

coins <- crypto2::crypto_list(only_active = TRUE) %>% 
         dplyr::filter(name %in% c("Bitcoin"))

# Primeira função 
# Retorna os preços/cotações organizada e com o lag desejado 

get_price_lag  <- function(coins, t_lag){
  
price_clean <- crypto2::crypto_history(coin_list = coins, 
                                       start_date = START_PRICE) %>% 
               janitor::clean_names() %>% 
               dplyr::arrange(timestamp) %>% 
               dplyr::mutate(close_t = lag(close, n = t_lag), 
                             interval = (high + low)/2,
                             vmc = (volume/market_cap)*100, 
                             amplitude = (high - low)) %>% 
               dplyr::select(timestamp, 
                             interval,
                             close, close_t, 
                             amplitude, vmc) %>% stats::na.omit()
     
  return(price_clean)
          
} 


# Visualizando a relação t-30

data_coin =  get_price_lag(coins, t_lag = 30)


# Definindo regressão linear 

model_linear = stats::lm(log(interval) ~ log(vmc), data = data_coin)
summary(model_linear)
shapiro.test(model_linear$residuals)
hist(model_linear$residuals)
model_boot <- car::Boot(model_linear, R = 1000)

betas_boots <- data.frame(model_boot[["t"]]) %>% 
  janitor::clean_names()


print(confint(model_boot, level = .95, type = "norm"))
hist(model_boot)

# print(model_linear)
# summary(model_linear)
# confint(model_linear)