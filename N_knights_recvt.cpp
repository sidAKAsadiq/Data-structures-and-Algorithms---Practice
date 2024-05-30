#include <iostream>
#include <string>

using namespace std;

bool is_valid(int(*chess)[5],int n,int row,int col){
    if(row < 0 || row > n-1 || col < 0 || col > n-1){
        return false;
    }
    if(chess[row][col+1] == 1 || chess[row][col-1] == 1 || chess[row+1][col] == 1 || chess[row-1][col] == 1){
        return false;
    }
    return true;
}

bool all_spots_checked(int(*checked)[5],int n,int row,int col){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(checked[i][j]==0){
                return false;
            }
        }
    }
    return true;
}

void place_k(int(*chess)[5],int(*checked)[5],int n,int row,int &count){
    //Base case 
    if(count == n){   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }       
        return;
    }
    for(int i=0 ; i<n ; i++){
        if(is_valid(chess,n,row,i)){
            chess[row][i] = 1;
        }
    }
    count++;
    place_k(chess,checked,n,row+1,count);
    for(int i=n-1;i>=0;i--){
        swap(checked[row][i],checked[row][i-1]);
    }
}


int main() {
    const int n = 5;
    int max_k;
    if(n%2==0){
        max_k = (n*n)/2;
    }
    else{
        max_k = ((n*n)+1)/2;
    }
    int k_placed = 0;
    int row = 0;
    int col = 0;
    int count = 0;
    cout<<"Before : \n";
    int chess[n][n] = {0};
    int checked[n][n] = {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }
    //chess[0][0] = 1;
    place_k(chess,checked,n,row,count);
    cout<<"After : \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}