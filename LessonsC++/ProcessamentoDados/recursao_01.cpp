#include <iostream> 
using namespace std; 

int fatorial(int n){
    if(n > 1){
        return n * fatorial(n -1); 
    }else{

        return 1; 

    }
}

int main(){

    int n, resultado; 
    cout << "Digite um número não negativo: "; 
    cin >> n; 
    // função definida 
    resultado = fatorial(n); 
    cout << "Fatorial de " << n << " = " << resultado << endl; 

    return 0; 

}

