#include <iostream>
#include <string>

using namespace std;

int main() {
    //Reducing T.C of bubble sort for an already sorted array from O(n^2) to O(n)
    int n = 5;
    int* sorted_array = new int[n] {1,2,3,4,5};

    bool is_swapped;

    for(int i=0;i<n-1;i++){
        is_swapped = false;
        for(int j=0;j<n-i-1;j++){
            if(sorted_array[j]>sorted_array[j+1]){
                swap(sorted_array[j],sorted_array[j+1]);
                is_swapped = true;
            }
        }
        //If no swapping occured i.e array is already sorted, so break the loop!
        if(!is_swapped){
            cout<<"Breaking Loop when i = "<<i<<endl; // i should be equal to zero when breaking loop on already sorted array
            break;
        }
    }


    return 0;
}