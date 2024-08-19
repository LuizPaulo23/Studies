#include <iostream>

int main(){

    // variavel externa 
    int externa = 1; 

    // loop externo 
    while (externa <= 5){
        
    // interna 
    int interna = 1; 
    while (interna <= externa){

        std::cout << interna << " ";
        ++interna;

    }
    
        // print 
        std::cout << "\n"; 
        ++externa;

    }


}