#include<iostream>
#include<string>
using namespace std;
int find_peak(int arr[],int size){
    int i;
    int start,end,mid;
    start=0;
    end=size-1;
    mid=start + ((end-start)/2);
    while(start<=end){
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
            return mid;
        }
        else if(arr[mid]>arr[mid-1]){
            start=mid+1;
        }
        else{
            end=end-1;
        }
    mid = start + ((end-start)/2);
    }
}
main(){
int arr[4]={3,4,5,1};
cout<<"Peak Index: "<<find_peak(arr,4);
}