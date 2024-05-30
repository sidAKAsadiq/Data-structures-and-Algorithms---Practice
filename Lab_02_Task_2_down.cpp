#include <iostream>
using namespace std;
main(){
//Insertion sort Algorithm
    int n=5;
    int* arr  = new int[n] {12,11,13,5,6};
    cout<<"Before Insertion Sort : ";
        for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
                //Wapis anay wala kaam till we get the element to its right position
                for(int j=i;j>0;j--){
                    if(arr[j]<arr[j-1]){
                        swap(arr[j],arr[j-1]);
                    }
                    else{
                        //peechay    wala part is sorted
                        break;
                    }
                }
        }
    }
    cout<<"After Insertion Sort : ";

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}