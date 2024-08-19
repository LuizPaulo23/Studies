#include <iostream> 
using namespace std; 

int main(){

    cout << "\n"; 

    // declarar um array de inteiros 
    int array[5] = {9,7,5,3,1}; 

    cout << "\n"; 

    cout << "Conteúdo do array: " << array << "\n"; 
    cout << "\n"; 

    // imprimir cada elemento do array 
    cout << "Os valores no array são: "; 
    for (int i = 0; i < 5; i++){
    
        cout << array[i] << " "; 

    }

    cout << "\n"; 
    cout << "Endereço do array: " << &array << "\n";

    cout << "Primeiro elemento: " << array[1] << "\n"; 
    cout << "Primeiro elemento: " << &array[1] << "\n"; 

    //Declarar a variável do tipo ponteiro e incializar  com o array

    int *ptr = array; 
    cout << "\n"; 

    //imprimir o valor da variável ponteiro 
    cout << "valor do ponteiro: " << ptr << "\n"; 


    //array é trato como um ponteiro 
    //tudo em CC+ é um ponteiro

}