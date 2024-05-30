#include <iostream>
using namespace std;
//used when we have small sized arrays
main(){
    int temp;
    int n=5;
    int arr[n]={11,22,33,5,1};
    int min;
    min=arr[0];
    int i,j;
    cout<<"Un sorted\n";
    for(i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"\nSorted by selection sort\n";
        for(i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
}