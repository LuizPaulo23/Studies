#include<iostream> 
using namespace std; 

class imprimeDados{
    public: 

    void print(int i){
        cout << "Imprimindo int: " << i << endl; 
    }

    void print(double f){
        cout << "Imprimindo double: " << f << endl; 
    }

    void print(char* c){
        cout << "Imprimindo caracter: " << c << endl; 
    }
}; 


int main(void){

    imprimeDados func1; 
    //imprimir valor do inteiro
    func1.print(7); 
    func1.print(362.25); 
    func1.print((char *) "Hello C++"); 
}
