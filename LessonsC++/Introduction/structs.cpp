#include <iostream>
using namespace std; 

// Declara um struct 

struct Funcionario{
    int id; 
    int idade; 
    double salario; 
};

// Função 

void imprimeFunc(Funcionario func){

    cout << "ID: " << func.id << "\n";
    cout << "Idade " << func.idade << "\n";
    cout << "Salário " << func.salario << "\n";
}

int main(){
    // inicializando a variável chamada 
    Funcionario bob = {10012,42,4512.36}; 
    Funcionario maria = {12125,25,2358.62}; 

    cout << "\nDados do Bob:" << "\n";
    imprimeFunc(bob); 
    cout << "\nDados da Maria" << "\n"; 
    imprimeFunc(maria); 
}

