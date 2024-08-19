#include <iostream> 
using namespace std; 

class funcionario {

    //atributo privado
    int salario; 

    public: 
    //setter
    void setSalario(int s){
        salario = s; 
    }

    //getter
    int getSalario(){
        return salario; 
    }

}; 

int main(){
    funcionario luiz; 
    luiz.setSalario(2800); 

    cout << luiz.getSalario() << endl; 
    return 0; 
}

