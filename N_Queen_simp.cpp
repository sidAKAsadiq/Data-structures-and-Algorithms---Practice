#include <iostream>
#include <string>

using namespace std;

bool is_safe(int** board , int n , int row , int col){
    if(row<0 || row>=n || col<0 || col>=n){
        return false;
    }
    for(int i = 0;i<n ; i++){
        if(board[row][i] == 1 || board[i][col] == 1 || board[i][i] == 1){
            return false;
        }
    }
    return true;
}


void solve(int** board , int n , int row , int &count){
    //Base case
    if(count == n){
        return;
    }

    for(int i=0 ; i<n ; i++){
        if(is_safe(board,n,row,i)){
            board[row][i] = 1;
            count++;
            solve(board,n,row+1,count);
            board[row][i] = 0;
            count--;
        }
    }
    return;


}


int main() {
    
    int n = 4;
    int** board = new int*[n];

        for (int i = 0; i < n; i++) {
        board[i] = new int[n];
    }

        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j] = 0;
        }
    }

            for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
            
        }
        cout<<endl;
    }
    int count = 0;

    solve(board,n,0,count);
    cout<<endl;

            for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
            
        }
        cout<<endl;
    }


    return 0;
}