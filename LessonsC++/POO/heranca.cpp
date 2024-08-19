#include<iostream> 
using namespace std; 

class Formato{
    // função 
    // dentro da classe é método 
    public: 
    void setLargura(int l){
        largura = l; 
    }

    void setAltura(int a){
        altura = a; 
    }

    protected: 
        int largura; 
        int altura; 

}; 

// Classe derivada
class Retangulo: public Formato {

    public: 
    int getArea(){
        return(largura * altura); 
    }

}; 

int main(void){

// Instância da Classe
Retangulo Ret1; 

//método da classe
Ret1.setAltura(7); 
Ret1.setLargura(4); 

cout << "Área do retângulo: " << Ret1.getArea() << endl; 

return 0; 

} 