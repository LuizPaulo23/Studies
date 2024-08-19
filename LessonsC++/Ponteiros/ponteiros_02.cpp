#include <iostream> 
using namespace std; 

int main(){
// declara a variável num 
int num = 10; 

// inicializa ptr com o endereço da variável num 
// aponta para o endereço de memória 
int *ptr = &num; 

//imprimi o valor da variável num 
cout << num << "\n"; 
cout << &num << "\n"; 

// imprime o valor da variável ptr
cout << ptr << "\n"; 

return 0; 

}