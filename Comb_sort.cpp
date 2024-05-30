#include <iostream>
#include <string>

using namespace std;

int main() {
    int N = 10;
    int* arr = new int [N] {8,4,1,56,3,-44,23,-6,28,0};

    int gap;

    for(gap = N/1.3 ; gap>0 ; gap = gap/1.3){
        for(int i = gap ; i<N ; i++){
            for(int j = i-gap ; j<N-1 ; j++){
                if(arr[j]>arr[i]){
                    swap(arr[j],arr[i]);
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