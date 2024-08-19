#include <iostream>
using namespace std; 

int main(){

    // inicializando apenas com 3 elementos 
    // deve ser evitado

    int lista_num1[5] = {100, 200, 300}; 

    cout << lista_num1 << "\n";
    cout << "\n\nImprime Array 1:\n";

    for (int i = 0; i <= 4; i++){
    cout << "Elemento do array no índice " << i << " é igual a " << lista_num1[i] << "\n";
    }
    
    // tamanho em aberto 

    int list_num2[] = {1,25,25,58,69,25,14,25,36,14}; 

    cout << "\n\nImprime Array 2:\n"; 
    for (int i = 0; i < 10; i++){
        cout << "Elemento do array no índice " << i << " é igual a " << list_num2[i] << "\n";
    }
    

    // Válido para string e outras estruturas 

    // string names[] = {}

}