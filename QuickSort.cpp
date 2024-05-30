#include <iostream>
#include <string>

using namespace std;

int partition(int* arr,int s,int e){
    int pivot = arr[s];
    int count = 0;
    for(int i = s+1;i<=e;i++){
        if(arr[i] < pivot){
            count++;
        }
    }

    int pivot_index = s + count;
    swap(arr[s],arr[pivot_index]);
    int i = s ; //Pivot ko count nahi kareingay , start par pivot hai iss liye start + 1 kara
    int j = e;
    while(i < pivot_index && j > pivot_index){
        if (arr[i] <= pivot){
            i++;
        }
        if(arr[j] > pivot){
            j++;
        }
        if(i < pivot_index && j > pivot_index){
            swap(arr[i],arr[j]);
        }
    }  
    return pivot_index;
}




void quick_sort(int*arr,int s,int e){
    if(s>=e){
        return;
    }
    int p = partition(arr,s,e);
    quick_sort(arr,s,p-1);
    quick_sort(arr,p+1,e);
}


int main() {
    int n = 5; 
    int arr[5] = {3,1,4,5,2};
    int s = 0;
    int e = n-1;
    quick_sort(arr,s,e);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}