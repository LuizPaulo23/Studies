from plotly import graph_objects as go
from cvxopt.modeling import op, variable 
from cvxopt import solvers

mesa = variable(1, "Quantifade de mesas por dia")
cadeira = variable(1, "Quantidade de cadeiras por dia")

# Definindo FOB 
# Problema minimização  

fob = -34*mesa[0] - 18*cadeira[0]

# Definindo restrições 

restricoes = []
restricoes.append(12*mesa[0] + 10*cadeira[0] <= 480)
restricoes.append(3*mesa[0] + 1*cadeira[0] <= 72)

# Restrições de canalização 

restricoes.append(mesa[0] >= 0)
restricoes.append(cadeira[0] >= 0)

prob = op(fob, restricoes)
prob.solve('dense', 'glpk')

# Formatando a saída
lucro = -fob.value()[0]
qtd_mesas = mesa[0].value()[0]
qtd_cadeiras = cadeira[0].value()[0]

print(f"O lucro projetado diário será de R$ {lucro:.2f}")
print(f"Quantidade de mesas por dia deve ser {qtd_mesas:.2f}")
print(f"Quantidade de cadeiras por dia deve ser {qtd_cadeiras:.2f}")

# fig = go.Figure(data = go.Bar())