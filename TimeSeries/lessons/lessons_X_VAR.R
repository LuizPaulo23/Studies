# Carregar pacotes necessários
library(vars)
library(tsibble)
library(ggplot2)

# Carregar dados de exemplo (vendas mensais e preço)
dados <- as_tsibble(economics)

# Ajustar o modelo VAR
modelo_var <- VAR(dados[, c("pce", "pop")], p = 5)

# Análise de impulso-resposta
impulso_resposta <- irf(modelo_var, impulse = "pce", response = "pop", boot = TRUE)

# Plotar impulso-resposta
# autoplot(impulso_resposta, ncol = 2, facets = TRUE) +
#   theme_minimal() +
#   labs(title = "Análise de Impulso-Resposta: Efeito de Variações no Consumo sobre a População")

plot(impulso_resposta)



