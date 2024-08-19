#include<iostream> 
using namespace std; 

int main(){

// Declarar array de 5 posições 
int a[5];

//Variável para ordenação 
int temp = 0; 
cout << "Digite 5 números" << endl;

// Carrega os 5 números  no array
for (int i = 0; i < 5; i++){
    cin >> a[i];
}

cout << "Ordenando..." << endl;
// Ordenação do array em ordem ascedente 

for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
        if(a[i] < a[j]){
            temp = a[i]; 
            a[i] = a[j];
            a[j] = temp;
        }
    }
    
}

cout << "Array em Ordem Ascendente" << endl;
    
for (int i = 0; i < 5; i++){
    cout << endl;
    cout << a[i] << endl;
}
// Ordenação do array em ordem descendente 
for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
        if (a[i] > a[j]){
        
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
         }
    
    }
    
}

cout << "Array em Ordem Descendente" << endl;
for (int i = 0; i < 5; i++){
    cout << endl; 
    cout << a[i] << endl; 
}


}