#include<iostream> 
using namespace std; 

class Calculadora{
    public: 
    // Construtor
    Calculadora(int i = 0){
        total = i; 
    }

    //interface
    void addNumb(int number){
        total += number; 
    }

    int getTotal(){
        return total; 
    }; 

    private: 
    // não é visível externamente 
    int total; 
}; 


int main(){

    Calculadora calc1; 
    calc1.addNumb(10); 
    calc1.addNumb(20); 
    calc1.addNumb(30); 

    cout << "Total: " << calc1.getTotal() << endl; 
}