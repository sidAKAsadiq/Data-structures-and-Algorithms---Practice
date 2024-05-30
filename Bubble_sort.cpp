#include <iostream>
using namespace std;
main(){
    int n,i,j,temp,min;
    n=5;
    int arr[n]={7,10,9,15,5};
    cout<<"Unsorted \n";
    for(i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }

    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){  
                swap(arr[j],arr[j+1]);
            }
            else{
                continue;
            }
        }
    }
    cout<<"\nSorted by Bubble sort: \n";
    for(i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
}