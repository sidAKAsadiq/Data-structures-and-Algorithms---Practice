	#include <iostream>
using namespace std;


int divide_arr(int* arr,int start,int end){
    //This returns index of pivot element
    int element = arr[end];
    int index = start;
    int i = index;
    while(i<end){
        if(arr[i] < element){
            swap(arr[index],arr[i]);
            i++;
            index++;
        }
        else{
            i++;
        }
    }
    swap(arr[end],arr[index]);
    return index;
}

void quick_sort(int* arr,int start , int end){
    if (start >= end){
        return;
    }

    int pivot = divide_arr(arr,start,end);
    quick_sort(arr,start,pivot-1);
    quick_sort(arr,pivot+1,end);

}

int main(){
    int arr[8] = {5,6,2,-2,6,10,12,15};
    cout<<"Before QS: \n";
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int start = 0;
    int end = 7;
    quick_sort(arr,start,end);
    cout<<"After QS: \n";
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }    
    return 0;
}