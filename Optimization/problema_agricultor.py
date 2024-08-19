from plotly import graph_objects as go 
from cvxopt.modeling import op, variable
from cvxopt import solvers

milho = variable(1, "Área alocada para o plantio de milho")
aveia = variable(1, "Área alocada para o plantio de aveia")

# Definindo a FOB 
# Receita: 150*8x + 120*10x
# Custo: 200*3x + 200*2x
# Problema de maximização inverte o sinal 

fob = - 600 * milho[0] - 800 * aveia[0]

# Definindo restrições 

restrictions = []
restrictions.append(milho[0] + aveia[0] <= 100)
restrictions.append(3*milho[0] + 2*aveia[0] <= 240)
restrictions.append(milho[0] <= 60)
restrictions.append(aveia[0] <= 80)
restrictions.append(milho[0] >= 0)
restrictions.append(aveia[0] >= 0)

agricultor = op(fob, restrictions)
agricultor.solve("dense", "glpk")

print(f'O Lucro projetado para o agricultor é de {-fob.value()[0]:.2f}')
print(f'{milho.name} é de {milho[0].value()[0]}')
print(f'{aveia.name} é de {aveia[0].value()[0]}')

# Multiplicadores de Lagrange 

print("Variável Dual associado ao limite de área", restrictions[0].multiplier.value)
print("Variável Dual associado ao limite de hh", restrictions[1].multiplier.value)
print("Variável Dual associado ao limite de milho", restrictions[2].multiplier.value)
print("Variável Dual associado ao limite de aveia", restrictions[3].multiplier.value)

# fig = go.Figure(data = go.Bar(y = [milho[0].value()[0], aveia[0].value()[0]], x = ["Milho", "Aveia"]))
# fig.show()