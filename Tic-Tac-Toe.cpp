#include<iostream>
#include <cstdlib>
#include <ctime>
#include<vector>
using namespace std;
void drawBoard(vector<vector<char>>& board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
             cout<<board[i][j];
            if(j<2){
           cout<<"|";
            }
        }
        if(i < board.size()-1){
        cout<<endl<<"-----"<<endl;
        }
    }
    cout<<endl;
    return;
}

bool check(vector<vector<char>>& board,char ch){
    int clarity1,clarity2;
    for(int i=0;i<3;i++){
        
        clarity1 = 0,clarity2 = 0;
        for(int j=0;j<3;j++){
            if(board[i][j] == ch){
                clarity1++;
            }
            if(board[j][i] == ch){
                clarity2++;
            }
        }
        if(clarity1 == 3 || clarity2 == 3){
            return true;
    }
    }
    clarity1 = 0,clarity2 = 0;
    for(int i=0,j=0;i<3,j<3;i++,j++){
        if(board[i][j] == ch){
            clarity1++;
        }
        else{
            break;
        }
    }
    for(int i=0,j=2;i<3,j>=0;i++,j--){
        if(board[i][j] == ch){
            clarity2++;
        }
        else{
            break;
        }
    }
    if(clarity1 == 3 || clarity2 == 3){
            return true;
    }
        return false;
}

int main(){
    vector<vector<char>>board(3,vector<char>(3,' '));
    srand(time(0)); 
    cout<<"Welcome to TIC-TAC-TOE Game : "<<endl<<endl;
    drawBoard(board);
    cout<<endl<<"Which version you want to play : "<<endl;
    cout<<endl<<"1. Playing as a kid "<<endl;
    cout<<"2. Playing with a friend "<<endl;
    int choice ;
    cout<<endl<<"Enter choice : ";
    cin>>choice;
    if(choice == 1){
    for(int k=0; ;k++){
        int attempt = 0;
        int iX,jX;
        int iO,jO;
        for(int m=0; ;m++){
    cout<<"PlayerX , Enter the position (0-2) for row and column : ";
    cin>>iX>>jX;
    if(board[iX][jX] == ' '){
        board[iX][jX] = 'X';
        break;
    }
        }
    cout<<endl;
    drawBoard(board);
    cout<<endl;
    if(check(board,'X')){
        cout<<"You Won "<<endl;
        break;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] != ' '){
                attempt++;
            }
        }
    }
    
    if(attempt == 9){
        cout<<"Tie"<<endl;
        break;
        
    }
    for(int m=0; ;m++){
    iO = rand() % 3;
    jO = rand() % 3;
    if(board[iO][jO] == ' '){
        board[iO][jO] = 'O';
        break;
    }
    }
    cout<<endl;
    drawBoard(board);
    cout<<endl;
    if(check(board,'O')){
        cout<<"You lost "<<endl;
        break;
    }
    }
    }
    if(choice == 2){
        for(int k=0; ;k++){
        int attempt = 0;
        int iX,jX;
        int iO,jO;
        for(int m=0; ;m++){
    cout<<"PlayerX , Enter the position (0-2) for row and column : ";
    cin>>iX>>jX;
    if(board[iX][jX] == ' '){
        board[iX][jX] = 'X';
        break;
    }
        }
    cout<<endl;
    drawBoard(board);
    cout<<endl;
    if(check(board,'X')){
        cout<<"Player X won"<<endl;
        break;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] != ' '){
                attempt++;
            }
        }
    }
    if(attempt == 9){
        cout<<"Tie"<<endl;
        break;
    }
    for(int m=0; ;m++){
    cout<<"PlayerO , Enter the position (0-2) for row and column : ";
    cin>>iO>>jO;
    if(board[iO][jO] == ' '){
        board[iO][jO] = 'O';
        break;
    }
        }
    cout<<endl;
    drawBoard(board);
    cout<<endl;
    if(check(board,'O')){
        cout<<"Player O won"<<endl;
        break;
    }
    }
    }
}
