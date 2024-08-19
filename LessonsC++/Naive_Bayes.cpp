#pragma GCC diagnostic push 
#pragma GCC diagnostic ignored "-Wsign-compare"

// Libs []

#include <iostream>
#include <chrono>
#include <fstream>				
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>			
#include <cmath>				
#include <math.h>	

// namespace

using namespace std; 
using namespace std::chrono; 

// índice de início dos dados de teste
const int starTest = 900; 

// Número de previsões que serão mostradas 

const int num0fIterations = 5; 

// Função main - importar arquivo 

//int main(){

    // nome do arquivo 
//    string fileName = "/Github/Projetos/ML/ML/dados/dataset.csv"; 
//    ifstream inputFile; // objeto para receber o conteúdo do arquivo
    
    //abrir arquivo 
//    inputFile.open(fileName); 

    // Verificar se há algum erro 
//    if(!inputFile.is_open()){
//        cout << "Falha ao abrir o arquivo." << endl; 
//        return 0; 
//    }

//}

int main() {
    // Obter o diretório pessoal do usuário
    const char* homeDir = getenv("HOME");
    if (homeDir == nullptr) {
        cerr << "Erro ao obter o diretório pessoal do usuário." << endl;
        return 1;
    }

    // Construir o caminho completo para o arquivo
    string fileName = string(homeDir) + "/Github/Projetos/ML/ML/dados/dataset.csv";
    ifstream inputFile;

    // Abrir arquivo
    inputFile.open(fileName);

    // Verificar se há algum erro
    if (!inputFile.is_open()) {
        cout << "Falha ao abrir o arquivo." << endl;
        return 0;
    }

    // Seu código para manipular o arquivo vai aqui...

    // Não se esqueça de fechar o arquivo quando terminar de usá-lo
    //inputFile.close();

    //return 0;


// Declarar variável 

double idVal; 
double tipo_docVal; 
double classeVal; 
double cert_validoVal; 
double uso_diasVal; 

// Variável do tipo vetor para todos os elementos de cada coluna do dataset 

vector <double> id; 
vector <double> tipo_doc;
vector <double> classe;
vector <double> certificado_valido;
vector <double> uso_dias;

// Variável para armazenar o cabeçalho do arquivo

string header; 

// Variável para armazenar cada célula do arquivo csv

string cell; 

// recuperar o cabeçalho para desconsiderar a linha 

getline(inputFile, header); 

//Loop de carga e limpeza dos dadosa 

while (inputFile.good()){
    // Leitura da coluna id 

    getline(inputFile, cell, ","); 
    getline()
    // Remova aspas 
    cell.erase(remove(cell.begin(), cell.end(), '\"'), cell.end());


}


}