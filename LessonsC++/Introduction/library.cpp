#include <iostream> 

int main(){

    // define a variável inteira x com o valor 
    int x = 5; 
    //int x(5); 

    std::cout << "\nValor da variável x:" << x << std::endl;

    // solicite que o usuário digite o número 
    std::cout << "\nDigite um número: ";

    // define a variável x para a entrada do usuário (inicializa-a com zero)
    int y;

    std::cin >> y; 

    // Mensagem de saída 
    // recomendável usar /n no lugar de endl 
    // em alto processamento 
    // aspas duplas sempre!!! 
    std::cout << "\nO usuário digitou: " << y << "\n\n";
    // 2 = newline 
}


