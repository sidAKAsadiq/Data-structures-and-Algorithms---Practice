#include <iostream>
#include <string>

using namespace std;

bool check_safety(int (*array)[4],int (*check)[4],int row,int coloum){
    if(row < 0 || row >2 || coloum < 0 || coloum >3){
        return false;
    }
    if(array[row][coloum] == 0){
        return false;
    }
    if(check[row][coloum] == 1){
        return false;
    }
    return true;
    
}
void total_paths(int (*array)[4], int &number_of_paths, int (*check)[4],int row,int coloum,int &moves,int (*best_way)[4],int &min_moves) {
    //Base case -> Ruk jao!
    if(row == 0 && coloum == 3){
        number_of_paths++;
        if(moves < min_moves){
            min_moves = moves;
            //moves = 0;
            for(int i = 0;i<3;i++){
                for(int j=0;j<4;j++){
                    best_way[i][j] = check[i][j];
                }
            }
        }
            best_way[0][3] = 1;
        return;
    }
    check[row][coloum] = 1;
    moves++;
    if(check_safety(array,check,row,coloum+1)){
        total_paths(array,number_of_paths,check,row,coloum+1,moves,best_way,min_moves);
    }
    if(check_safety(array,check,row,coloum-1)){
        total_paths(array,number_of_paths,check,row,coloum-1,moves,best_way,min_moves);
    }
    if(check_safety(array,check,row+1,coloum)){
        total_paths(array,number_of_paths,check,row+1,coloum,moves,best_way,min_moves);
    }
    if(check_safety(array,check,row-1,coloum)){
        total_paths(array,number_of_paths,check,row-1,coloum,moves,best_way,min_moves);
    }        
    check[row][coloum] = 0; 
    moves--;
}

int main() {
    int array[3][4] = {{1,0,0,1},{1,1,1,1},{0,1,1,0}};
    cout<<"Given Maze : "<<endl;
                    for(int i = 0;i<3;i++){
                for(int j=0;j<4;j++){
                    cout<<array[i][j]<<" ";
                }
                cout<<endl;
            }
    int number_of_paths = 0;
    int moves = 0;
    int min_moves = 1000;
    int check[3][4] = {0}; //This will help in Backtracking
    int best_way[3][4] = {0};    total_paths(array,number_of_paths,check,0,0,moves,best_way,min_moves);
    cout<<"Possible Paths: "<<number_of_paths<<endl;
    cout<<"Best possible path :\n";
                    for(int i = 0;i<3;i++){
                for(int j=0;j<4;j++){
                    cout<<best_way[i][j]<<" ";
                }
                cout<<endl;
            }
    return 0;
}