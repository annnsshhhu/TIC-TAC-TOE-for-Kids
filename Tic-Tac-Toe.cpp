#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;
void drawBoard(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j];
            if (j < 2) {
                cout << "|";
            }
        }
        if (i < board.size() - 1) {
            cout << endl << "-----" << endl;
        }
    }
    cout << endl;
    return;
}

void randomized(vector<vector<char>>& board,char ch){ // C for Corners and central A for All and R for rest
    int iO, jO;
            for (int m = 0;; m++) {
                iO = rand() % 3;
                jO = rand() % 3;
                if (board[iO][jO] == ' ') {
                    if(ch == 'R' && (iO + jO) % 2 != 0){
                        board[iO][jO] = 'O';break;
                    }
                    if(ch == 'C' && (iO + jO) % 2 == 0){
                        board[iO][jO] = 'O';break;
                    }
                    if(ch == 'A'){
                        board[iO][jO] = 'O';break;
                    }
                }
            }
            cout << endl;
            drawBoard(board);
            cout << endl;
            return;
            
}

void entersUserValueCorrectly(vector<vector<char>>& board,char ch,int *iX,int *jX){
    if(ch == 'X'){
    for (int m = 0; ;m++) {
                cout <<endl<<"PlayerX , Enter the position (0-2) for row and column : ";
                cin >> *iX >> *jX;
                if (board[*iX][*jX] == ' ') {
                    board[*iX][*jX] = 'X';
                    break;
                }
            }
            cout << endl;
            drawBoard(board);
            cout << endl;
            return;
    }
    else{
        for (int m = 0;; m++) {
                cout <<endl<<"PlayerO , Enter the position (0-2) for row and column : ";
                cin >> *iX >> *jX;
                if (board[*iX][*jX] == ' ') {
                    board[*iX][*jX] = 'O';
                    break;
                }
            }
            cout << endl;
            drawBoard(board);
            cout << endl;
            return;
    }
}
bool checkGameOver(vector<vector<char>>& board, char ch) {
    int clarity1, clarity2;
    for (int i = 0; i < 3; i++) {

        clarity1 = 0, clarity2 = 0;
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ch) {
                clarity1++;
            }
            if (board[j][i] == ch) {
                clarity2++;
            }
        }
        if (clarity1 == 3 || clarity2 == 3) {
            return true;
        }
    }
    clarity1 = 0, clarity2 = 0;
    for (int i = 0, j = 0; i < 3, j < 3; i++, j++) {
        if (board[i][j] == ch) {
            clarity1++;
        } else {
            break;
        }
    }
    for (int i = 0, j = 2; i < 3, j >= 0; i++, j--) {
        if (board[i][j] == ch) {
            clarity2++;
        } else {
            break;
        }
    }
    if (clarity1 == 3 || clarity2 == 3) {
        return true;
    }
    return false;
}

bool protecting(vector<vector<char>>& board,char ch) {
    int clarity1, clarity2;
    for (int i = 0; i < board.size(); i++) {
        clarity1 = 0;
        int store1;
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == ch) {
                clarity1++;
            } else {
                store1 = j;
            }
        }
        if (clarity1 == 2 && board[i][store1] == ' ') {
            board[i][store1] = 'O';
            return true;
        }
    }
    for (int i = 0; i < board.size(); i++) {
        clarity2 = 0;
        int store2;
        for (int j = 0; j < board[i].size(); j++) {
            if (board[j][i] == ch) {
                clarity2++;
            } else {
                store2 = j;
            }
        }
        if (clarity2 == 2 && board[store2][i] == ' ') {
            board[store2][i] = 'O';
            return true;
        }
    }
    int clarity = 0;
    int store;
    for (int i = 0, j = 0; i < board.size(), j < board[0].size(); i++, j++) {
        if (board[i][j] == ch) {
            clarity++;
        } else {
            store = j;
        }
    }
    if (clarity == 2 && board[store][store] == ' ') {
        board[store][store] = 'O';
        return true;
    }
    clarity = 0;
    for (int i = 0, j = 2; i < board.size(), j >= 0; i++, j--) {
        if (board[i][j] == ch) {
            clarity++;
        } else {
            store = j;
        }
    }
    if (clarity == 2 && board[board.size() - 1 - store][store] == ' ') {
        board[board.size() - 1 - store][store] = 'O';
        return true;
    }

    return false;
}
bool isBoardFilled(vector<vector<char>>& board) {
    int attempt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                attempt++;
            }
        }
    }
    if (attempt == 9) {
        return true;
    }
    return false;
}

bool ifXhastwoPaths(vector<vector<char>>& board){
    int clarity1,store1,store2,clarity2,clarity3,store3,store4,clarity4;
    for (int i = 0; i < board.size(); i++) {           //if row wise has possibility
        clarity1 = 0;
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'X') {
                clarity1++;
            }
            else{
                store1 = j;
            }
        }
        if(board[i][store1] == ' ' && clarity1 == 2){
            break;
        }
        else {
            clarity1 = 0;
        }
    }
    
    for (int i = 0; i < board.size(); i++) {           //if column wise has possibility
        clarity2 = 0;
        for (int j = 0; j < board[i].size(); j++) {
            if (board[j][i] == 'X') {
                clarity2++;
            }
            else{
                store2 = j;
            }
        }
        if(board[store2][i] == ' ' && clarity2 == 2){
            clarity2 = clarity2;
            break;
        }
        else{
            clarity2 = 0;
        }
    }
    
    if((clarity1 == 2 && clarity2 == 2)){
        return true;
    }
    
    clarity3 = 0;                                  //if main diagional wise has possibility
    for (int i = 0, j = 0; i < board.size(), j < board[0].size(); i++, j++) {
        if (board[i][j] == 'X') {
            clarity3++;
        }
        else{
            store3 = i;
        }
    }
    if(board[store3][store3] != ' '){
        clarity3 = 0;
    }
    if((clarity1 == 2 && clarity3 == 2) || (clarity2 == 2 && clarity3 == 2)){
        return true;
    }
    clarity4 = 0;                                  // if non main diagonal has possibility
    for (int i = 0, j = 2; i < board.size(), j >= 0; i++, j--) {
        if (board[i][j] == 'X') {
            clarity4++;
        }
        else{
            store4 = i;
        }
    }
    if(board[store4][2-store4] != ' '){
        clarity4 = 0;
    }
    if((clarity1 == 2 && clarity4 == 2) || (clarity2 == 2 && clarity4 == 2)){
        return true;
    }
    return false;
    
}
bool fixingIndexFor2paths(vector<vector<char>>& board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if((i+j)%2 != 0){
                continue;
            }
            if(board[i][j] == ' '){
                board[i][j] = 'X';
                int temp = ifXhastwoPaths(board);
                if(temp){
                    board[i][j] = 'O';
                    cout << endl;drawBoard(board);cout << endl;
                    return true;
                }
                else if(!temp){
                    board[i][j] = ' ';
                }
            }
        }
    }
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if((i+j)%2 == 0){
                continue;
            }
            if(board[i][j] == ' '){
                board[i][j] = 'X';
                int temp = ifXhastwoPaths(board);
                if(temp){
                    board[i][j] = 'O';
                    cout << endl;drawBoard(board);cout << endl;
                    return true;
                }
                else if(!temp){
                    board[i][j] = ' ';
                }
            }
        }
    }
    return false;
}
void playingtoTieorLose(vector<vector<char>>& board,int pole){
    int r=0,c=0;
    int duck = 0;
        while(!isBoardFilled(board)){
            if(pole == 0){randomized(board,'A');}
            if(isBoardFilled(board)){break;}
            
        entersUserValueCorrectly(board,'X',&r,&c);
        
        if(protecting(board,'O')){
            cout << endl;drawBoard(board);cout << endl;
           cout<<"You lost";
            return;
        }
        else if(protecting(board,'X')){
            cout << endl;drawBoard(board);cout << endl;
            pole = 1;
            duck = 1;
        }
        else if(pole == 1 && duck == 0){
            int countCorners = 0;
            for(int i=0;i<=2;i=i+2){
                for(int j=0;j<=2;j=j+2){
                    if(board[i][j] == 'X'){
                        countCorners++;
                    }
                }
            }
            
            if(countCorners != 2){
            if(!fixingIndexFor2paths(board)){
                pole = 0;
            }
            else{
                pole = 1;
            }
            }
            else{
                randomized(board,'R');
            }
           
            duck = 1;
        }
        else{
            pole = 0;
            duck = 1;
        }
        }
        cout<<"Tie";
}
void playingtoLose(vector<vector<char>>& board,int row,int col) {
    if((row + col) % 2 != 0 ){
        int r = row,c = col;
        board[1][1] = 'O';cout << endl;drawBoard(board);cout << endl;
            entersUserValueCorrectly(board,'X',&r,&c);
            if(protecting(board,'O')){
                cout << endl;
            drawBoard(board);
            cout << endl;
                cout<<"You lost";
                return;
            }
            if(row == 1){board[0][2] = 'O';}
            else if(col == 1){board[2][0] = 'O';}
            cout << endl;
            drawBoard(board);
            cout << endl;
            entersUserValueCorrectly(board,'X',&r,&c);
            if(protecting(board,'O')){
                cout << endl;
            drawBoard(board);
            cout << endl;
                cout<<"You lost";
                return;
            }
    }
    else if(row != 1 && col != 1){
        int r = row,c = col;
        if(row!=col){board[2][2] = 'O';cout << endl;drawBoard(board);cout << endl;
            entersUserValueCorrectly(board,'X',&r,&c);
            if(protecting(board,'O')){
                cout << endl;
            drawBoard(board);
            cout << endl;
                cout<<"You lost";
                return;
            }
            board[col][row] = 'O';cout << endl;drawBoard(board);cout << endl;
            entersUserValueCorrectly(board,'X',&r,&c);
            if(protecting(board,'O')){
                cout << endl;
            drawBoard(board);
            cout << endl;
                cout<<"You lost";
                return;
            }
    }
    else{
        board[row-2][col] = 'O';cout << endl;drawBoard(board);cout << endl;
        entersUserValueCorrectly(board,'X',&r,&c);
        if(protecting(board,'O')){
                cout << endl;
            drawBoard(board);
            cout << endl;
                cout<<"You lost";
                return;
            }
        board[col][row-2] = 'O';cout << endl;drawBoard(board);cout << endl;
        entersUserValueCorrectly(board,'X',&r,&c);
        if(protecting(board,'O')){
                cout << endl;
            drawBoard(board);
            cout << endl;
                cout<<"You lost";
                return;
            }
    }
    }
    else if(row == 1 && col == 1){
        playingtoTieorLose(board,0);
    }
}


int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    srand(time(0));
    cout << "Welcome to TIC-TAC-TOE Game : " << endl << endl;
    drawBoard(board);
    cout << endl << "Which version you want to play : " << endl;
    cout << endl << "1. Playing as a kid " << endl;
    cout << "2. Playing with a friend " << endl;
    cout << "3. Playing with pro (Either you are going to lose or the match is going to tie)" << endl;
    int choice;
    cout << endl << "Enter choice : ";
    cin >> choice;
    if (choice == 1) {
        for (int k = 0;; k++) {
            int iX=-1, jX=-1;
            entersUserValueCorrectly(board,'X',&iX,&jX);
            if (checkGameOver(board, 'X')) {
                cout << "You Won " << endl;
                break;
            }
            if (isBoardFilled(board)) {
                cout << "Tie" << endl;
                break;
            }
            randomized(board,'A');
            if (checkGameOver(board, 'O')) {
                cout << "You lost " << endl;
                break;
            }
        }
    }

    if (choice == 2) {
        for (int k = 0;; k++) {
            int iX=-1, jX=-1;
            int iO=-1, jO=-1;
            entersUserValueCorrectly(board,'X',&iX,&jX);
            if (checkGameOver(board, 'X')) {
                cout << "Player X won" << endl;
                break;
            }
            if (isBoardFilled(board)) {
                cout << "Tie" << endl;
                break;
            }
            entersUserValueCorrectly(board,'O',&iO,&jO);
            if (checkGameOver(board, 'O')) {
                cout << "Player O won" << endl;
                break;
            }
        }
    }
    if (choice == 3) {
        int num;
        cout <<endl<< "Choose a number between 0 and 1 : ";
        cin >> num;
        int guess = rand() % 2;
        if (guess != num) {
            cout <<endl<<"Oops! Computer will make its first move" << endl;
            board[0][0] = 'O';
            cout << endl;
            drawBoard(board);
            cout << endl;
            int iX=0, jX=0;
            entersUserValueCorrectly(board,'X',&iX,&jX);
            playingtoLose(board,iX,jX);
        }
        else{
            cout<<endl<<"Congrats! you will make first move "<<endl;
            int iX=0, jX=0;
            entersUserValueCorrectly(board,'X',&iX,&jX);
            if(iX != 1 || jX != 1){
                board[1][1] = 'O';
                cout << endl;
            drawBoard(board);
            cout << endl;
                playingtoTieorLose(board,1);
            }
            else{
                randomized(board,'C');
                 playingtoTieorLose(board,1);
            }
        }
        
    }
}
