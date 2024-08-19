# include <iostream> 

int main(){

int x = 5; 
// imprime o valor 
std::cout << x << "\n";
// imprime o endereço de memória  
std::cout << &x << "\n"; 
// conteúdo do endereço de memória 
std::cout << *(&x) << "\n"; 

return 0; 

}