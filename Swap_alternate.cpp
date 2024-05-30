#include <iostream>
using namespace std;
main(){
    int n,i,j,temp;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }    
    cout<<"\n";
    if(n%2==0){
        for(i=0;i<n-1;i+=2){
            temp=arr[i+1];
            arr[i+1]=arr[i];
            arr[i]=temp;
            cout<<"herhe\n";

        }
    }
    else{
            for(i=0;i<n-2;i+=2){
            temp=arr[i+1];
            arr[i+1]=arr[i];
            arr[i]=temp;
        
        }
    }
            cout<<"herhe\n";

        for(i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }    
    cout<<"\n";
}