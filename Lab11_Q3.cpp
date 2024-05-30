#include <iostream>
#include <string>

using namespace std;


class hash_map{
public:
int* arr;
int size;
hash_map(){}
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
void remove(int k){
    int index = k % size;
    while(arr[index] != k){
        index++;
    }
    arr[index] = 0;
}
};


int main() {
    int pairs = 0;
    int n = 4;
    int target = 6;
    hash_map h1(4);
    int* arr = new int[n];
    cout<<"fill array\n";
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        h1.add(arr[i]);
    }
    for(int i = 0 ; i<n ; i++){
        int num = arr[i];
        int diff = target - arr[i];
        if(h1.search(diff)){
            h1.remove(diff);
            pairs++;
        }
    }
    cout<<"Pairs found : "<<pairs<<endl;
    string s1 = "hi";
    string s2 = "hi";
    cout<<s1+s2;
    return 0;
}