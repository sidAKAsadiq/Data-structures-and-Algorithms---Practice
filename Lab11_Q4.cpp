#include <iostream>
#include <string>
#include <climits>
using namespace std;

class hash_map{
    public:
    int* arr;
    int size;
    hash_map(int s){
        size = s;
        arr = new int[size] {0};
    }
    void add(int k){
    int index = k % size;
    while(arr[index] != 0){
        index++;
    }
    arr[index] = k;
}
int ret_ind(char k){
    int index = int(k) % size;
    while(arr[index] != 0){
        index++;
    }
    return index;
}
bool search(int k){ 
    int index = k % size;
    while(arr[index] != k){
        index++;
        if(index >= size){
           // cout<<"Key not found\n";
            return false;
        }
    }
   // cout<<"key found\n";
    return true;
}
    void print(){
        for(int i = 0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


int main() {
    string s = "ADOBECODEBANC";
    int m = s.length();
    string t = "ABC";
    int n = t.length();
    int have = 0;
    int need = t.length();
    int result = INT_MAX;
    hash_map window(t.length());
    hash_map T(t.length());
    for(int i=0;i<t.length() ; i++){
       int index = T.ret_ind    (t[i]);
       T.arr[index]++;
    }
    T.print();
    
    return 0;


}