#include <iostream>
#include <string>

using namespace std; 

// Enum 

enum Cor{
    cor_azul, 
    cor_marrom,
    cor_verde
}; 

string getCorName(Cor cor){
    if (cor == cor_azul)
        return "Azul"; 
    
    if (cor == cor_marrom)
        return "Marrom"; 

    if (cor == cor_verde)
        return "Verde";

    return "?";  
    
}

int main(){

    // Declara variável do tipo enum
    Cor cor_carro = {cor_azul}; 

    // Imprime na tela 
    cout << "\nID da cor do seu carro: " << cor_carro << "\n\n";
    cout << "\nCor do seu carro: " << getCorName(cor_carro) << "\n\n";

}
