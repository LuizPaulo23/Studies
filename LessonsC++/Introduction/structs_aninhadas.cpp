#include <iostream>
#include <cstdint>
using namespace std; 

// Primeira Struct 

struct Funcionario
{
    int16_t id; 
    int32_t idade; 
    double salario; 
};

// segunda Struct 

struct Empresa
{
    Funcionario CEO; 
    int numFun; 
};

// Função 

void imprimeEmpresa(Empresa empresa){

    cout << "ID do CEO: " << empresa.CEO.id << "\n";
    cout << "Idade do CEO: " << empresa.CEO.idade << "\n";
    cout << "Salário do CEO: " << empresa.CEO.salario << "\n";
    cout << "Número de Funcionários: " << empresa.numFun << "\n";
}

// Função 

void imprimeFunc(Funcionario func){
    cout << "ID do Funcionário: " << func.id << "\n";
    cout << "Idade do Funcionário: " << func.idade << "\n";
    cout << "Salário do Funcionário" << func.salario << "\n";
}

// Inicializa a variável 

int main(){

Empresa ABC; 

// Atribui valores às variáveis 

ABC.CEO.id = 1; 
ABC.CEO.idade = 62;
ABC.CEO.salario = 75000.00; 
ABC.numFun = 120; 

// Imprime ABC 
cout << "\nDados da Empresa ABC:" << "\n"; 
imprimeEmpresa(ABC); 

// Inicializa a variável chamada XPTO do tipo Empresa 
Empresa XPTO = {{10,58,8500.0},140}; 

// Imprime XPTO

cout << "\nDados da Empresa XPTO:" << "\n"; 
imprimeEmpresa(XPTO); 

// Inicializa a variável 

Funcionario bob = {1001,42,35849.22};

cout << "\nDados do bob:" << "\n";
imprimeFunc(bob);


}
