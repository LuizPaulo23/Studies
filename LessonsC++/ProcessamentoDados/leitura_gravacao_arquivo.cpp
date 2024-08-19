#include <iostream> 
#include <fstream>
using namespace std; 

int main(){

// criar um novo e abrir em modo de gravacao 
ofstream meuArquivo("teste.txt"); 

// gravar uma frase no arquivo

meuArquivo << "Teste de gravação e leitura de arquivo em C++"; 

// fechar o arquivo 
meuArquivo.close(); 

// Abrir o arquivo 
ifstream meuArquivoLeitura("teste.txt"); 

// Criar uma variável do tipo string para receber o texto do arquivo

string meuTexto; 

// Fazer a leitura do arquivo 
while (getline(meuArquivoLeitura, meuTexto)){
    
    cout << meuTexto << endl; 

}


// Fechar arquivo 
meuArquivoLeitura.close(); 


}
