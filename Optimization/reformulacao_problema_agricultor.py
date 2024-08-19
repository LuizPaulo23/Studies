from cvxopt.modeling import op, variable
from cvxopt import solvers

milho = variable(1, "Área alocada para o plantio de milho")
aveia = variable(1, "Área alocada para o plantio de aveia")
gap = variable(4, "Variável de folga")

# Definindo a FOB 
# Receita: 150*8x + 120*10x
# Custo: 200*3x + 200*2x
# Problema de maximização inverte o sinal 

fob = - 600 * milho[0] - 800 * aveia[0]

# Definindo restrições 

restrictions = []
restrictions.append(milho[0] + aveia[0] + gap[0] == 100)
restrictions.append(3*milho[0] + 2*aveia[0] + gap[1] == 240)
restrictions.append(milho[0] + gap[2] == 60)
restrictions.append(aveia[0] + gap[3] == 80)
restrictions.append(milho[0] >= 0)
restrictions.append(aveia[0] >= 0)
restrictions.append(gap[0] >= 0)
restrictions.append(gap[1] >= 0)
restrictions.append(gap[2] >= 0)
restrictions.append(gap[3] >= 0)

agricultor = op(fob, restrictions)
agricultor.solve("dense", "glpk")


if agricultor.status == "optimal":

    print(f'O Lucro projetado para o agricultor é de {-fob.value()[0]:.2f}')
    print(f'{milho.name} é de {milho[0].value()[0]}')
    print(f'{aveia.name} é de {aveia[0].value()[0]}')

    print("\n")
    print("******Variáveis de Folga******")
    print("\n")

    for i in range(len(gap)): 
        print(f'Valor da variável de folha {i} é {gap[i].value()}')

    print("\n")
    print("******Multiplicadores de Lagrange******")
    print("\n")
    
    print("Variável Dual associado ao limite de área", restrictions[0].multiplier.value)
    print("Variável Dual associado ao limite de hh", restrictions[1].multiplier.value)
    print("Variável Dual associado ao limite de milho", restrictions[2].multiplier.value)
    print("Variável Dual associado ao limite de aveia", restrictions[3].multiplier.value)

    # fig = go.Figure(data = go.Bar(y = [milho[0].value()[0], aveia[0].value()[0]], x = ["Milho", "Aveia"]))
    # fig.show()
else:
    print("O problema não tem uma solução viável.")
