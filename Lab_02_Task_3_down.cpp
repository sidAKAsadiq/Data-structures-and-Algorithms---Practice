#include <iostream>
#include <climits>
using namespace std;
main(){
    //Selection sort algorithm
    int n = 5;
    int arr[5] = {64,25,12,22,11};
    int index_to_store_minimum_value;
    int index_to_be_swapped;
    int minimum_value = INT_MAX;
    for(int i=0;i<n-1;i++){
        index_to_store_minimum_value = i;
        for(int j = index_to_store_minimum_value ; j<n ; j++){
            if(arr[j]<minimum_value){
                minimum_value = arr[j];
                index_to_be_swapped = j;
            }
        }
        swap(arr[index_to_store_minimum_value],arr[index_to_be_swapped]);
        minimum_value = INT_MAX;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}