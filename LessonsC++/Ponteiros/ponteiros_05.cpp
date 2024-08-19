#include <iostream> 
using namespace std; 

int main(){
 
 int num; 
 int *ptr; 
 int **pptr; 

 num = 100; 

 // endereço da variável num 
 ptr = &num;

 pptr = &ptr; 

 // print 

cout << "Valor de num: " << num << endl; 
cout << "Endereço de num: " << &num << endl; 
cout << "Endereço armazenamento em ptr: " << ptr << endl; 
cout << "Valor para o qual *ptr aponta: " << *ptr << endl; 
cout << "Endereço de pptr: " << pptr << endl;
cout << "Valor para o qual **pptr aponta: " << **pptr << endl; 

return 0; 


}