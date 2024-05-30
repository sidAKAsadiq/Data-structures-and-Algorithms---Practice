#include <iostream>
using namespace std;
main(){
//Bubble sort Algorithm
int arr [10] = {4, 5, 6, 9, 1, 3, 1, 4, 5, 7};
int n = 10;

for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1-i;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
}

for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}



}   