#include <iostream>
bool isSafe(int **arr, int col, int row , int n) {
    if((col-1 >=0)) {
        if(arr[row][col - 1]==1) {
            return false; 
        }
    }
    if((col+1 < n) ) {
        if(arr[row][col + 1]==1) {
            return false ; 
        }
    }
    if((row-1 >=0) ) {
      if(arr[row - 1][col]==1) {
        return false; 
      }
    }
    if((row+1 < n)) {
        if(arr[row + 1][col]==1){
             return false; 

        }
    }
    return true ; 
}
void nKnightsProblem(int **arr , int n ,int noOfKnights ) {
         static int counter=0;
         static int row = 0 ; 
         if(counter==noOfKnights || row==n) {
            return ; 
         }
        for(int i = 0; i < n ; i++) {
            if(isSafe(arr, i ,row, n )) {
                arr[row][i] = 1 ; 
                counter++ ; 
            }
        }
        row++ ; 
        nKnightsProblem(arr, n, noOfKnights) ; 
}
int main() {
    int **arr ; 
    arr = new int*[4] ; 
      int n = 4 ; 
    for(int i = 0 ; i < 4 ; i++) {
        arr[i] = new int[4] ; 
        for(int j = 0 ; j < n ; j++) {
            arr[i][j] = 0 ; 
        }
    }
for(int i = 0 ; i < 4 ; i++) {
        for(int j = 0 ; j < 4 ; j++) {
                std::cout <<"\n" << "row: " << i << "  " << "col: " << j << "\n"<<  arr[i][j] ; 
        }
    }
  
    int noOfKnights = (n%2 == 0) ? (n *n) / 2 : ((n * n ) / 2) + 1 ;
    nKnightsProblem(arr , n , noOfKnights) ; 
    for(int i = 0 ; i < 4 ; i++) {
        for(int j = 0 ; j < 4 ; j++) {
                std::cout <<"\n" << "row: " << i << "  " << "col: " << j <<  arr[i][j] ; 
        }
    }
}