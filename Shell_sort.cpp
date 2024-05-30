b#include <iostream>
#include <string>

using namespace std;

int main() {
    int N = 9;
    int* arr = new int[N] {23,29,15,19,31,7,9,5,2};
    int gap;

    for(gap = N/2 ; gap>0 ; gap=gap/2){
        for(int j = gap ; j<N ; j++){
                 for(int i=j-gap ; i>=0 ; i = i-gap){
                if(arr[i+gap]<arr[i]){
                    swap(arr[i+gap],arr[i]);
                }
                else{
                    break;
                }
            }
        }
    }

    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}