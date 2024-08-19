// Desafio Game TicTacToe

// Diretivas
#include <iostream>
#include <stdlib.h>

// Namespace
using namespace std;

// Struct para armazenar a posição no tabuleiro.
struct Move{ 
    int row, col; 
}; 
 
// Computador e jogador são definidos globalmente e vamos atribuir "X" a quem for o primeiro a jogar.
char computer, player; 

// Array de posição é usado para mapear a posição dada pelo jogador para a célula apropriada do tabuleiro.
int position[9][2] = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};

// Esta função é usada para imprimir o tabuleiro sempre que o usuário faz um movimento.
void drawBoard(char board[3][3]){
    cout << "----++---++----" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << "| ";
            if(board[i][j] == '-'){
                cout << " " << " |";
            }
            else{
                if(board[i][j]=='X') cout << "X |";
                else cout << "O |";
            }
        }
        cout << "\n----++---++----" << endl;
    }
}

/*
Esta função é usada para verificar se o tabuleiro está vazio ou não.
Retorna verdadeiro se qualquer célula estiver vazia.
Retorna falso se o tabuleiro estiver cheio.
*/ 
bool isBoardEmpty(char board[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j]=='-') return true;
        }
    }
    return false; 
} 
 
/*
Esta função retorna 1 se o computador ganhar, -1 se o jogador ganhar e 0 se ninguém ganhar.
Estamos retornando 1 e -1 porque essa função é posteriormente usada na otimização, onde precisamos subtrair ou adicionar profundidade,
uma vez que a profundidade máxima do tabuleiro pode ser 9. Portanto, 1 parece ser a escolha ideal.
*/
int winner(char board[3][3]){ 
    for (int i = 0; i < 3; i++){ 

        // Verifica se alguém ganha ou não em cada coluna.
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2]){ 
            if (board[i][0]==computer) return 1; 
            else if (board[i][0]==player) return -1; 
        } 
    } 
  
    for (int j = 0; j < 3; j++){ 

        // Verifica se alguém ganha ou não em cada linha.
        if (board[0][j]==board[1][j] && board[1][j]==board[2][j]){ 
            if (board[0][j]==computer) return 1; 
            else if (board[0][j]==player) return -1; 
        } 
    } 

    // Verificação diagonal.
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2]){  
        if (board[0][0]==computer) return 1; 
        else if (board[0][0]==player) return -1; 
    } 

    // Verificação diagonal.
    if (board[0][2]==board[1][1] && board[1][1]==board[2][0]){ 
        if (board[0][2]==computer) return 1; 
        else if (board[0][2]==player) return -1; 
    } 
    return 0; 
}  

// Esta função é usada para encontrar a célula oposta de uma célula.
Move opposite(int p){
    Move pos;
    if(p==1){
        pos.row = 2; pos.col = 2;
        return pos;
    }
    else if(p==3){
        pos.row = 2; pos.col = 0;
        return pos;
    }
    else if(p==7){
        pos.row = 0; pos.col = 2;
        return pos;
    }
    else if(p==9){
        pos.row = 0; pos.col = 0;
        return pos;
    }
    return pos;
}

// Esta função é chamada para realizar apenas movimentos válidos.
// Células já preenchidas não podem ser inseridas novamente.
void allowedMove(char board[3][3], int mv){
    while(board[position[mv-1][0]][position[mv-1][1]] != '-'){
        cout << "Espaço Preenchido. (Escolha apenas os espaços em branco) : \n";
        cin >> mv;
    }
    return;
} 

// Esta função é usada para verificar se o computador pode vencer dando um lance específico.
// Retorna a posição da célula onde o computador pode fazer a primeira jogada e ganhar.
Move attack(char board[3][3]){
    Move pos;
    for(int i = 0; i < 3 ; i++){
        for(int j = 0; j < 3 ; j++){
            if(board[i][j]=='-'){
                board[i][j]=computer;
                if(winner(board)==1){
                    pos.row = i;
                    pos.col = j;
                    return pos;
                }
                board[i][j]='-';
            }
        }
    }
    pos.row = -1;
    pos.col = -1;
    return pos;
}

// Esta função é usada para verificar se o jogador pode ganhar dando um lance específico.
// Então o computador bloqueia aquele local e impede o jogador de ganhar.
// Ele retorna a posição da célula onde o computador pode efetuar a jogada e impedir o jogador de ganhar.
Move defend(char board[3][3]){
    Move pos;
    for(int i = 0; i < 3 ; i++){
        for(int j = 0; j < 3 ; j++){
            if(board[i][j]=='-'){
                board[i][j]=player;
                if(winner(board)==-1){
                    pos.row = i;
                    pos.col = j;
                    return pos;
                }
                board[i][j]='-';
            }
        }
    }
    pos.row = -1;
    pos.col = -1;
    return pos;
}

// Esta função retorna uma posição de onde o jogo pode continuar.
// Também evita que o jogador ganhe.
Move stay(char board[3][3]){
    Move pos;
    for(int i = 0; i < 3 ; i++){
        for(int j = 0; j < 3 ; j++){
            if(board[i][j]=='-'){
                pos.row = i;
                pos.col = j;
                return pos;
            }
        }
    }
    return pos;
}

// Esta função é usada quando o jogador / usuário efetua a jogada primeiro.
void automateBoard1(char board[3][3]){
    int mv;
    
    Move pos;
    
    cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
    
    cin >> mv;
    
    board[position[mv-1][0]][position[mv-1][1]] = player; 
    
    // Casos em que o jogador escolhe a posição central como a primeira jogada
    if(mv==5){          
        board[0][0] = computer;
        
        cout << "\nTabuleiro após movimento do computador:\n";
        
        drawBoard(board);
        
        cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
        
        cin >> mv;
        
        allowedMove(board, mv);
        
        board[position[mv-1][0]][position[mv-1][1]] = player;
        
        if(mv==9){
            board[0][2] = computer;
            
            cout << "\nTabuleiro após movimento do computador:\n";
            
            drawBoard(board);
            
            cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
            
            cin >> mv;
            
            allowedMove(board, mv);
            
            board[position[mv-1][0]][position[mv-1][1]] = player;
            
            while(true){
                pos = attack(board);
                if(pos.row != -1){
                    board[pos.row][pos.col] = computer;
                    drawBoard(board);
                    cout << "Você Perdeu :( .\n";
                    return;
                }
                
                pos = defend(board);
                
                if(pos.row == -1) pos = stay(board);
                
                board[pos.row][pos.col] = computer;
                
                cout << "\nTabuleiro após movimento do computador:\n";
                
                drawBoard(board);
                
                if(!isBoardEmpty(board)) break;
                
                cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
                
                cin >> mv;
                
                allowedMove(board, mv);
                
                board[position[mv-1][0]][position[mv-1][1]] = player;                
            }            
            cout << "Deu Empate :| \n";
            
            return;
        }
        while(true){
            pos=attack(board);
            if(pos.row != -1){
                board[pos.row][pos.col] = computer;
                drawBoard(board);
                cout << "Você Perdeu :( .\n";
                return;
            }
            
            pos = defend(board);
            
            if(pos.row == -1) pos = stay(board);
            
            board[pos.row][pos.col] = computer;
            
            cout << "\nTabuleiro após movimento do computador:\n";
            
            drawBoard(board);
            
            if(!isBoardEmpty(board)) break;
            
            cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
            
            cin >> mv;
            
            allowedMove(board, mv);
            
            board[position[mv-1][0]][position[mv-1][1]] = player;                
        }            
        cout << "Deu Empate :| \n";
        return;
    }
    else if(mv==1 or mv==3 or mv==7 or mv==9){          

        // Casos em que o jogador escolhe qualquer posição de canto como primeira entrada
        Move opp = opposite(mv);
        
        board[1][1] = computer;
        
        cout << "\nTabuleiro após movimento do computador:\n";
        
        drawBoard(board);
        
        cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
        
        cin >> mv;
        
        allowedMove(board, mv);
        
        board[position[mv-1][0]][position[mv-1][1]] = player;
        
        if(position[mv-1][0]==opp.row and position[mv-1][1]==opp.col){
            board[0][1] = computer;
            
            cout << "\nTabuleiro após movimento do computador:\n";
            
            drawBoard(board);
            
            cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
            
            cin >> mv;
            
            allowedMove(board, mv);
            
            board[position[mv-1][0]][position[mv-1][1]] = player;
            
            while(true){
                pos=attack(board);
                if(pos.row != -1){
                    board[pos.row][pos.col] = computer;
                    drawBoard(board);
                    cout << "Você Perdeu :( .\n";
                    return;
                }
                
                pos = defend(board);
                
                board[pos.row][pos.col] = computer;
                
                cout << "\nTabuleiro após movimento do computador:\n";
                
                drawBoard(board);
                
                if(!isBoardEmpty(board)) break;
                
                cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
                
                cin >> mv;
                
                allowedMove(board, mv);
                
                board[position[mv-1][0]][position[mv-1][1]] = player;
                
            }            
            cout << "Deu Empate :| \n";
            return;
        }
        else{
            while(true){
                pos=attack(board);
                if(pos.row != -1){
                    board[pos.row][pos.col] = computer;
                    drawBoard(board);
                    cout << "Você perdeu :( .\n";
                    return;
                }
                
                pos = defend(board);
                
                if(pos.row == -1) pos = stay(board);
                
                board[pos.row][pos.col] = computer;
                
                cout << "\nTabuleiro após movimento do computador:\n";
                
                drawBoard(board);
                
                if(!isBoardEmpty(board)) break;
                
                cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
                
                cin >> mv;
                
                allowedMove(board, mv);
                
                board[position[mv-1][0]][position[mv-1][1]] = player;                
            }            
            cout << "Deu Empate :| \n";
            return;                
        }
    }
    else if(mv==2 or mv==4){           

        // Casos em que o usuário escolhe a 2ª ou 4ª posição como primeira jogada
        board[0][0] = computer;
        
        cout<<"\nTabuleiro após movimento do computador:\n";
        
        drawBoard(board);
        
        cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
        
        cin >> mv;
        
        allowedMove(board, mv);
        
        board[position[mv-1][0]][position[mv-1][1]] = player;
        
        if(mv != 5){
            board[1][1] = computer;
            
            cout << "\nTabuleiro após movimento do computador:\n";
            
            drawBoard(board);
            
            cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
            
            cin >> mv;
            
            allowedMove(board, mv);
            
            board[position[mv-1][0]][position[mv-1][1]] = player;
            
            while(true){
                pos=attack(board);
                if(pos.row != -1){
                    board[pos.row][pos.col] = computer;
                    drawBoard(board);
                    cout << "Você Perdeu :( .\n";
                    return;
                }
                
                pos = defend(board);
                
                if(pos.row == -1) pos = stay(board);
                
                board[pos.row][pos.col] = computer;
                
                cout << "\nTabuleiro após movimento do computador:\n";
                
                drawBoard(board);
                
                if(!isBoardEmpty(board)) break;
                
                cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
                
                cin >> mv;
                
                allowedMove(board, mv);
                
                board[position[mv-1][0]][position[mv-1][1]] = player;                
            }            
            cout << "Deu Empate :| \n";
            return;
        }
        else{
            while(true){
                pos=attack(board);
                if(pos.row != -1){
                    board[pos.row][pos.col] = computer;
                    drawBoard(board);
                    cout << "Você Perdeu :( .\n";
                    return;
                }
                pos = defend(board);
                
                if(pos.row == -1) pos = stay(board);
                
                board[pos.row][pos.col] = computer;
                
                cout << "\nTabuleiro após movimento do computador:\n";
                
                drawBoard(board);
                
                if(!isBoardEmpty(board)) break;
                
                cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
                
                cin >> mv;
                
                allowedMove(board, mv);
                
                board[position[mv-1][0]][position[mv-1][1]] = player;                
            }            
            cout << "Deu Empate :| \n";
            return;
        }
    }

    else{           
        board[2][2] = computer;
        
        cout << "\nTabuleiro após movimento do computador:\n";
        
        drawBoard(board);
        
        cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
        
        cin >> mv;
        
        allowedMove(board, mv);
        
        board[position[mv-1][0]][position[mv-1][1]] = player;
        
        if(mv != 5){
            board[1][1] = computer;
            
            cout << "\nTabuleiro após movimento do computador:\n";
            
            drawBoard(board);
            
            cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
            
            cin >> mv;
            
            allowedMove(board, mv);
            
            board[position[mv-1][0]][position[mv-1][1]] = player;
            
            while(true){
                pos=attack(board);
                if(pos.row != -1){
                    board[pos.row][pos.col] = computer;
                    drawBoard(board);
                    cout << "Você Perdeu :( .\n";
                    return;
                }
                
                pos = defend(board);
                
                if(pos.row == -1) pos = stay(board);
                
                board[pos.row][pos.col] = computer;
                
                cout << "\nTabuleiro após movimento do computador:\n";
                
                drawBoard(board);
                
                if(!isBoardEmpty(board)) break;
                
                cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
                
                cin >> mv;
                
                allowedMove(board, mv);
                
                board[position[mv-1][0]][position[mv-1][1]] = player;                
            }            
            cout << "Deu Empate :| \n";
            return;
        }
        else{
            while(true){
                pos=attack(board);
                if(pos.row != -1){
                    board[pos.row][pos.col] = computer;
                    drawBoard(board);
                    cout << "Você Perdeu :( \n";
                    return;
                }
                
                pos = defend(board);
                
                if(pos.row == -1) pos = stay(board);
                
                board[pos.row][pos.col] = computer;
                
                cout << "\nTabuleiro após movimento do computador:\n";
                
                drawBoard(board);
                
                if(!isBoardEmpty(board)) break;
                
                cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
                
                cin >> mv;
                
                allowedMove(board, mv);
                
                board[position[mv-1][0]][position[mv-1][1]] = player;                
            }            
            cout << "Deu Empate :| \n";
            return;
        }
    }  
}

// Esta função é usada quando o computador faz a primeira jogada.
void automateBoard2(char board[3][3]){
    int mv;
    
    Move pos;
    
    cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
    
    cin >> mv;
    
    allowedMove(board, mv);
    
    board[position[mv-1][0]][position[mv-1][1]] = player;
    
    if(mv==5){              

        // Casos em que o jogador dá a posição central como a primeira entrada
        board[2][2] = computer;
        
        cout << "\nTabuleiro após movimento do computador:\n";
        
        drawBoard(board);
        
        cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
        
        cin >> mv;
        
        allowedMove(board, mv);
        
        board[position[mv-1][0]][position[mv-1][1]] = player;
        
        if(mv==3 or mv==7){
            Move opp = opposite(mv);
            
            board[opp.row][opp.col] = computer;
            
            cout<<"\nTabuleiro após movimento do computador:\n";
            
            drawBoard(board);
            
            cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
            
            cin >> mv;
            
            allowedMove(board, mv);
            
            board[position[mv-1][0]][position[mv-1][1]] = player;
            
            pos = attack(board);
            
            board[pos.row][pos.col] = computer;
            
            drawBoard(board);
            
            cout << "Você Perdeu :( \n";
            
            return;
        }
        else{
            while(true){
                pos = defend(board);
                
                board[pos.row][pos.col] = computer;
                
                cout << "\nTabuleiro após movimento do computador:\n";
                
                drawBoard(board);
                
                if(!isBoardEmpty(board)) break;
                
                cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
                
                cin >> mv;
                
                allowedMove(board, mv);
                
                board[position[mv-1][0]][position[mv-1][1]] = player;
                
                pos=attack(board);
                
                if(pos.row != -1){
                    board[pos.row][pos.col] = computer;
                    drawBoard(board);
                    cout << "Você Perdeu :( \n";
                    return;
                }
            }            
            cout << "Deu Empate :| \n";
            return;
        }

    }

    else if(mv==4 or mv==7){            

        // Casos em que o jogador escoplhe a 4ª ou 7ª posição como a primeira jogada
        board[0][2] = computer;
        
        cout << "\nTabuleiro após movimento do computador:\n";
        
        drawBoard(board);
        
        cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
        
        cin >> mv;
        
        allowedMove(board, mv);
        
        board[position[mv-1][0]][position[mv-1][1]] = player;
        
        if(mv==2){
            board[2][2] = computer;
            
            cout << "\nTabuleiro após movimento do computador:\n";
            
            drawBoard(board);
            
            cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
            
            cin >> mv;
            
            allowedMove(board, mv);
            
            board[position[mv-1][0]][position[mv-1][1]] = player;
            
            pos = attack(board);
            
            board[pos.row][pos.col] = computer;
            
            drawBoard(board);
            
            cout << "Você Perdeu :( \n";
            
            return;
        }
        else{
            board[0][1] = computer;
            drawBoard(board);
            cout << "Você Perdeu :( \n";
            return;
        }

    }

    else{         
        board[2][0] = computer;
        
        cout << "\nTabuleiro após movimento do computador:\n";
        
        drawBoard(board);
        
        cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
        
        cin >> mv;
        
        allowedMove(board, mv);
        
        board[position[mv-1][0]][position[mv-1][1]] = player;
        
        if(mv==4){
            board[2][2] = computer;
            
            cout << "\nTabuleiro após movimento do computador:\n";
            
            drawBoard(board);
            
            cout << "Digite sua jogada (escolha apenas entre os espaços em branco): \n";
            
            cin >> mv;
            
            allowedMove(board, mv);
            
            board[position[mv-1][0]][position[mv-1][1]] = player;
            
            pos = attack(board);
            
            board[pos.row][pos.col] = computer;
            
            drawBoard(board);
            
            cout << "Você Perdeu :( \n";
            
            return;
        }
        else{
            board[1][0] = computer;
            drawBoard(board);
            cout << "Você Perdeu :( \n";
            return;
        }
    }        
}


int main(){
    char play = 'y';
    while(play=='y'){
        cout << "\nBem-Vindo(a) ao TicTacToe:\n";
        char board[3][3]={{'-','-','-'},{'-','-','-'},{'-','-','-'}};          

        // Declarando um Tabuleiro TicTacToe vazio
        drawBoard(board);
        
        cout << "Digite 1 Para Jogar Primeiro ou Digite 2 Para o Computador Jogar Primeiro:"<<endl;
        
        int inp_mv;
        
        cin >> inp_mv;
        
        if(inp_mv==1){
            
            // Inicializando o jogador como 'X', pois o jogador está dando o primeiro movimento
            player = 'X';                       

            computer = 'O';
            
            automateBoard1(board);
        }
        else if(inp_mv==2){

            // Inicializando o computador como 'X', pois o computador está dando o primeiro movimento
            computer = 'X';   

            player = 'O';
            
            board[0][0] = computer;
            
            cout << "\nTabuleiro após movimento do computador:\n";
            
            drawBoard(board);
            
            automateBoard2(board);
        }
        else{
            cout << "Escolha 1 ou 2 e tente novamente"<<endl;
        }
        cout << "Se você quiser jogar novamente digite 'y', para sair digite qualquer tecla :"<<endl;

        // A variável de reprodução recebe a entrada se o jogador deseja jogar ou não.
        cin >> play;                         
    }	
	return 0;
}

// Fim

