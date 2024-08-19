# include <iostream>

int main(){

    // Declarando as variáveis 
    
    int x; 
    double y; 
    int resultado_int; 
    double resultado_double; 

    // Inicializando as variáveis 

    x = 2; 
    y = 3.1;

    // Operação 

    resultado_int = x + y; 
    resultado_double = x + y; 

    // Imprime o resultado 
    std::cout << "Resultado Int: " <<  resultado_int << std::endl; 
    std::cout << "Resultado Double: " << resultado_double << std::endl; 


}