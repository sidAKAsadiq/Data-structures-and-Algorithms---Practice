#include <iostream>
#include <string>

using namespace std;

int main() {
    int * arr = new int [5] {0};
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}