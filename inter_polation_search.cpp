#include <iostream>
#include <string>

using namespace std;

int interpolation_search(int* arr,int k){
    int s = 0;
    int e = 4;
    int pos = s + (((k-arr[s])*(e-s))/(arr[e]-arr[s]));
    while(s<=e){
        if(arr[pos] == k ){
            return pos;
        }
        else if(arr[pos] > k){
            e = pos - 1;
        }
        else{
            s = pos + 1;
        }
        pos = s + (((k-arr[s])*(e-s))/(arr[e]-arr[s]));
    }
    return -1;
}

int main() {
    int arr[5] = {1,2,3,4,5};
    cout<<"index : "<<interpolation_search(arr,5);
    return 0;
}