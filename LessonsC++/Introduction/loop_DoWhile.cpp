#include <iostream>
using namespace std; 

int main(){

    // Declarar a variável 
    int seletor; 

    // Loop
    do{
        cout << "\nSelecione uma opção: \n"; 
        cout << "1 - Soma\n"; 
        cout << "2 - Subtração\n";
        cout << "3 - Multiplicação\n"; 
        cout << "4 - Divisão\n"; 
        cin >> seletor; 
    }
    while (seletor != 1 && seletor != 2 && seletor != 3 && seletor != 4);

    cout << "Você escolheu a opção: " << seletor << endl;
}