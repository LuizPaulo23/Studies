# include <iostream>
using namespace std; 

int main(){

    // cria um array de números inteiros 
    int lista[5]; 
    
    // Atribui valores a cada elemento do array 

    lista[0] = 1;
    lista[1] = 2;
    lista[2] = 3;
    lista[3] = 4;
    lista[4] = 5;

    for (int count = 0; count <= 4; ++ count){
       cout << "Elemento do array no índice " << count << " é igual a " << lista[count] << "\n"; 
    }
    

}