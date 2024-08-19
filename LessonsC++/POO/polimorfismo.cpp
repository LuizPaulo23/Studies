#include<iostream> 
using namespace std; 

class Formato {

    protected: 
        int largura, altura; 

    public: 
    Formato(int a = 0, int b = 0){

        largura = a; 
        altura = b; 
        
    }

}; 

class Retangulo: public Formato{

    public: 
    Retangulo(int a = 0, int b = 0):Formato(a,b){ } 

int area(){
    cout << "Área do rentângulo: " << (largura * altura) << endl; 

return 0; 

    }

};

class Triangulo: public Formato{

    public: 
    Triangulo(int a = 0, int b = 0):Formato(a,b){ } 

int area(){
    cout << "Área do triângulo: " << (largura * altura/2) << endl; 

return 0; 

    }

};


int main(){

    Retangulo rec(12,5); 
    Triangulo tri(14,21); 
    tri.area(); 
    rec.area(); 
    return 0; 
}