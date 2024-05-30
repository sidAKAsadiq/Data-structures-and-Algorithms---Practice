#include <iostream>
#include <string>

using namespace std;

bool is_safe(int** maze , int row,int col,int n){
    if(row >= n || col >= n){
        return false;
    }
    else if(maze[row][col] == 1){
        return true;
    }
    else{
        return false;
    }

}

bool solve(int** maze , int** path , int row , int col , int n){
    //Base case 
    if(row == n-1 && col== n-1){    //Destination Reached
        return true;
    }
    if(path[0][0] == 0){
        return false; //No ways exisit
    }
        //For right
        if(is_safe(maze,row,col+1,n)){
            path[row][col+1] = 1;
            if(solve(maze,path,row,col+1,n)){
                return true;
            }
            path[row][col+1] = 0;
        }
        //For down
        if(is_safe(maze,row+1,col,n)){
            path[row+1][col] = 1;
            if(solve(maze,path,row+1,col,n)){
                return true;
            }
            path[row+1][col] = 0;
        }
        return false;


}



int main() {
    int n = 5; // Size of the maze
    int** maze = new int*[n];
    int** path = new int*[n];

    for (int i = 0; i < n; i++) {
        maze[i] = new int[n];
        path[i] = new int[n];
    }

    cout<<"fill maze array : "<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            path[i][j] = 0;
        }
    }
    path[0][0] = 1;    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>maze[i][j];
        }
    }
    cout<<endl;
        for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<maze[i][j]<<" ";
            
        }
        cout<<endl;
    }
    cout<<solve(maze,path,0,0,5);

    return 0;
}