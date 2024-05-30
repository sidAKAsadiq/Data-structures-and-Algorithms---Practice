#include <iostream>
#include <string>

using namespace std;
    //Same case as merge sort
void Quick_sort(int arr[],int start,int end){
int length = (start+end)/2;
//Base case
if(start>=end){
    return;
}
//Partition;

int index = partition(arr,start,end);

//Recursive Call

Quick_sort(arr,start,index-1); // For left side
Quick_sort(arr,index+1,end); // For right side
}

int partition(int arr[],int start,int end){
int count=0;
int pivot = arr[start];
for(int k=start;k<=end;k++){
    if(arr[k]<= pivot){
        count++;
    }
}





}
int main() {
        int arr[5]={3,4,2,1,6};
        Quick_sort(arr,0,4);
        for(int i=0;i<5;i++){
            cout<<arr[i]<<" ";
        }

    return 0;
}   