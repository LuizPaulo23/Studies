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

    cout << "Digite o primeiro número: "; 
    cin >> num1; 

    cout << "Digite o segundo número: "; 
    cin >> num2;

    // Forma inicial de resolver o problema 
    // Sem usar boas práticas 

    if(seletor == 1){
        cout << "A soma dos números é: " << num1 + num2 << "\n\n";
    }

    if(seletor == 2){
        cout << "A subtração dos número é: " << num1 - num2 << "\n\n"; 

    }

    if(seletor == 3){
        cout << "A multiplicação dos números é: " << num1 * num2 << "\n\n";


    }

    if(seletor == 4){
        if(num2 == 0){
            cout << "Não há divisão por zero" << "\n\n";

        }
        else{
            cout << "A divisão dos números é: " << num1 / num2 << "\n\n";
        }

    }

}