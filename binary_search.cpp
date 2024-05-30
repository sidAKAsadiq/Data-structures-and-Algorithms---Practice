#include <iostream>
#include <string>

using namespace std;

int binary_search(int* arr,int k){
    int s = 0;
    int e = 4;
    int mid = s + ((e-s)/2);
    while(s<=e){
        if(arr[mid] == k ){
            return mid;
        }
        else if(k < arr[mid]){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + ((e-s)/2);
    }
    return -1;
}

int main() {
    int arr[5] = {1,2,3,4,5};
    cout<<"index : "<<binary_search(arr,4);
    return 0;
}