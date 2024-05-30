#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class hash_map{
    public:
    string* arr;
    int size;
    hash_map(){}
    hash_map(int s){
        size = s;
        arr = new string[size] ;
        for(int i=0;i<size;i++){
            arr[i] = "empty";
        }
    }
    void print(){
        for(int i = 0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void add(string s){
        int val = 0;
        for(int i = 0;i<s.length() ; i++){
        val = val + (i * int(s[i]));
    }  
        int index = val % size;
        while(arr[index] != "empty"){
            index = (index + 1) % size;
        }      
        arr[index] = s;
    }
    bool search(string s){
        int val = 0;
        for(int i = 0;i<s.length() ; i++){
        val = val + (i * int(s[i]));
    }         
        int index = val % size;
        int start = index;
        while(arr[index] != s){
            index = (index+1)%size;
            if(index == start){
            //cout<<"not found\n";
            return false;
            }

        }
     //   cout<<"found\n";
        return true;
    }




    // ["abcd","dcba","lls", "sll"]           
};  //    0      1      2      3                



int main() {
    int n = 4;
    hash_map h1(n);
    string* arr = new string[n];
    string* pairs = new string[n];
    int ind_pairs = 0;
    cout<<"Fill array\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
        h1.add(arr[i]);
    }
    for(int i=0;i<n;i++){
        string str = arr[i];
        string palindrome = arr[i];
        reverse(palindrome.begin(),palindrome.end());
        if(h1.search(palindrome)){
            string p = str + palindrome;
            pairs[ind_pairs] = p;
            ind_pairs++;
        }
    }
    for(int i=0;i<ind_pairs;i++){
        cout<<pairs[i]<<"   ";
    }

 
 
 
 
 
 
 
    // hash_map h1(4);
    // //h1.print();   
    // cout<<h1.arr[0][0]; //abcd = 596 , dcba = 586
    // string s = "dcba";
    // int val = 0;
    // for(int i = 0;i<s.length() ; i++){
    //     val = val + (i * int(s[i]));
    // }
    // cout<<596%4;

    
    return 0;
}