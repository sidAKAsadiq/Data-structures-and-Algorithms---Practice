#include <iostream>
#include <string>

using namespace std;

class Safe_array{
public:
int* arr;
int size;
Safe_array(){
    arr = NULL;
    size = 0;
}
Safe_array(int s){
    size = s;
    arr = new int[size];
}
int& operator [] (int index){
    if(index<0 || index>=size){
        cout<<"Out of range index\n";
        exit(1);
    }
    else{
        return arr[index];
    }
}
};

int main() {
    Safe_array s1(3);
    s1[0] = 1;
    s1[1] = 2;
    s1[2] = 3;
    cout<<s1[1];
    return 0;
}