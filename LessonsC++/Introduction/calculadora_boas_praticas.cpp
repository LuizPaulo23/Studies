#include <iostream>
using namespace std;

int main() {
    int seletor;

    // Loop para obter uma opção válida
    do {
        cout << "\nPor favor, escolha a opção desejada: \n";
        cout << "1 - Soma\n";
        cout << "2 - Subtração\n";
        cout << "3 - Multiplicação\n";
        cout << "4 - Divisão\n";
        cin >> seletor;
    } while (seletor != 1 && seletor != 2 && seletor != 3 && seletor != 4);

    int num1;
    int num2;

    cout << "Digite o primeiro número: ";
    cin >> num1;

    cout << "Digite o segundo número: ";
    cin >> num2;

    // Usando uma estrutura switch-case para resolver o problema
    switch (seletor) {
        case 1:
            cout << "A soma dos números é: " << num1 + num2 << "\n\n";
            break;
        case 2:
            cout << "A subtração dos números é: " << num1 - num2 << "\n\n";
            break;
        case 3:
            cout << "A multiplicação dos números é: " << num1 * num2 << "\n\n";
            break;
        case 4:
            if (num2 == 0) {
                cout << "Não há divisão por zero\n\n";
            } else {
                cout << "A divisão dos números é: " << num1 / num2 << "\n\n";
            }
            break;
        default:
            cout << "Opção inválida\n\n";
            break;
    }

    return 0;
}
