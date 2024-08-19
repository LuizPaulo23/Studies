#include <iostream> 
using namespace std; 

void imprimeArray1(int *array, int size){

    //imprime os valores do array
    cout << "Os valores no array são: "; 
    for (int i = 0; i < size; i++){
        cout << array[i] << " "; 
    }

    cout << "\n"; 
    


}

void imprimeArray2(int array[], int size){

    //imprime os valores do array
    cout << "Os valores no array são: "; 
    for (int i = 0; i < size; i++){
        cout << array[i] << " "; 
    }

    cout << "\n"; 
    


}

void imprimeArray3(int array[5], int size){

    //imprime os valores do array
    cout << "Os valores no array são: "; 
    for (int i = 0; i < size; i++){
        cout << array[i] << " "; 
    }

    cout << "\n"; 
    


}

int main(){

//declarar array 
int lista[] = {1,2,3,4,5}; 
int size = 5; 
cout << "\n"; 

//Chamar a função e passar o array como argumento
imprimeArray1(lista, size); 
imprimeArray2(lista, size); 
imprimeArray3(lista, size); 

}

