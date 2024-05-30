#include<iostream>
using namespace std;

int main(){
int row;
cout<<"Input number of rows\n";
cin>>row;
int col;
int** jagged_array = new int*[row];
int* size_of_coloums = new int[row];
for(int i=0;i<row ; i++){
    cout<<"Enter Number of Coloums for row no."<<i+1<<endl;
    cin>>col;
    jagged_array[i] = new int[col];
    size_of_coloums[i] = col;
}
int count = 1;
for(int i = 0 ; i<row; i++){
    for(int j=0 ; j<size_of_coloums[i] ; j++){
        jagged_array[i][j] = count;
        count++; 
    }
}
for(int i = 0 ; i<row; i++){
    for(int j=0 ; j<size_of_coloums[i]  ; j++){
        cout<<jagged_array[i][j]<<" " ;
    }
    cout<<endl;
}

for(int i = 0; i<row ; i++){
    delete jagged_array[i];
    jagged_array[i] = NULL;
}
delete [] jagged_array;
jagged_array = NULL;

}