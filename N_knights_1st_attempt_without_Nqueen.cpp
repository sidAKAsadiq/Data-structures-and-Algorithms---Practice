#include <iostream>
#include <string>

using namespace std;


bool is_safe(int** board,int row,int col,int n){
    if((row>=0 && row<n) && (col>=0 && col<n) && (board[row+2][col+1]==0) && (board[row+1][col+2]==0) && (board[row+2][col-1]==0) && (board[row+1][col-2]==0) && (board[row-2][col+1]==0) && (board[row-1][col+2]==0) && (board[row-2][col-1]==0) && (board[row-1][col-2]==0)){
        return true;
    }
    return false;
}


void solve(int** board , int n , int max_knights , int &counter, int row, int col ){
    if(counter == max_knights){
        cout<<"In base case\n";
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }    
        return ;
    }
        board[row][col] = 1;
    counter++;
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    } 
    for(int coloum = 0 ; coloum < n ; coloum++){
        if(is_safe(board,row,col,n)){
            board[row][col] = 1;
            counter++;
            solve(board,n,max_knights,counter,row,col+1);
            board[row][col] = 0;
            counter--;            
        }
    }


    solve(board,n,max_knights,counter,row+1,col);
    board[row][col] = 0;
    counter--; 
  
}



int main() {
    int N = 5;
    int max_knights;
    if(N%2 == 0 ){
        max_knights = (N*N)/2;
    }
    else{
        max_knights = (N*N + 1)/2;
    }

    int** board = new int*[N];
    for(int i=0;i<N;i++){
        board[i] = new int[N];
    }
    //Initializing Chess board with zero
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j] = 0;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    int counter = 0;
    solve(board,N,max_knights,counter,0,0);
    cout<<"After placement: \n";
     for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }    

    return 0;
}