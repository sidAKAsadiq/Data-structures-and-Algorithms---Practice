//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


void merge_both(int* arr,int s,int mid,int e){
    int* left = new int[mid+1];
    int* right = new int[e-mid];
    for(int i=0;i<=mid;i++){
        left[i] = arr[i];
    }
    int j = 0;
    for(int i=mid+1 ; i<=e ; i++){
        right[j] = arr[i];
        j++;
    }
    int i = 0;
    j = 0;
    int k = 0;
    
    while(i<(mid+1) && j<(e-mid)){
        if(left[i] < right[j]){
            arr[k] = left[i];
            i++;
            k++;
        }
        else{
            arr[k] = right[j];
            j++;
            k++;
        }
    }

    if(i == mid+1){
        while(j<(e-mid)){
            arr[k] = right[j];
            j++;
            k++;            
        }
    }
    else{
        while(i<(mid+1)){
            arr[k] = left[i];
            i++;
            k++;            
        }
    }


}


void merge_sort(int* arr, int s , int e){
    //Base case
    if(s>=e){
        return;
    }
    int mid = s + ((e-s)/2);
    merge_sort(arr,s,mid);
    merge_sort(arr,mid+1,e);
    merge_both(arr,s,mid,e);
}

int divide_arr(int* arr,int s,int e){
int element = arr[e];
int index = s;
int i = s;
while(i<e){
    if(arr[i] < element){
        swap(arr[index],arr[i]);
        i++;
        index++;
    }
    else{
        i++;
    }
}
swap(arr[e],arr[index]);
return index;


}




void quick_sort(int* arr,int s,int e){
    //Base case
    if(s>=e){
        return;
    }
    int pivot = divide_arr(arr,s,e);
    quick_sort(arr,s,pivot-1);
    quick_sort(arr,pivot+1,e);
}




int main(){
    int arr[8] = {3,1,6,8,4,5,2,7};
    cout<<"unsorted\n";
    for(int i =0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quick_sort(arr,0,7);
    cout<<"sorted\n";
    for(int i =0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}