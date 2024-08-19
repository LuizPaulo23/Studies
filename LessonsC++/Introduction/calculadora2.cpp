#include <iostream>
using namespace std; 

int main(){

    int seletor; 

    //loop
    do
    {
       cout << "\nPor favor escolha a opção desejada: \n";
       cout << "1 - Soma\n";
       cout << "2 - Subtração\n"; 
       cout << "3 - MUltiplicação\n"; 
       cout << "4 - Divisão\n";
       cin >> seletor; 
    } while (seletor != 1 && seletor != 2 && seletor !=3 && seletor !=4);

    int num1; 
    int num2; 

    // Lendo os números de input do usuário 

    cout << "Digite o primeiro número: "; 
    cin >> num1; 

    cout << "Digite o segundo número: "; 
    cin >> num2;

    // Condicionais da calculadora 

    if(seletor == 1){
        cout << "A soma entre os números é: " << num1 + num2 << "\n\n";
    } else if(seletor == 2){
        cout << "A subtração entre os números é: " << num1 - num2 << "\n\n";
    } else if(seletor == 3){
        cout << "A multipicação entre os números é: " << num1 * num2 << "\n\n";
    } else{
        if (num2 == 0){
           cout << "Não há divisão por zero, é indeterminado matematicamente" << "\n\n";
        }
        
        cout << "A divisão entre os número é: " << num1 / num2 << "\n\n";
    }

}