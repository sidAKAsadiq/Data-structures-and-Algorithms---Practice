#include <iostream>
#include <string>

using namespace std;

void reverse(char arr[],int start,int end){
    cout<<"Start : "<<start<<" End "<<end<<endl;
    if(start>end){
        return;
    }
    //Processing 
    swap(arr[start],arr[end]);
    reverse( arr, start+1,end-1);
}

int main() {
    char arr[5]={'a','e','i','o','u'};
    for(int i=0;i<5;i++){
        cout<<arr[i];
    }
    reverse(arr,0,4);
    
     for(int i=0;i<5;i++){
        cout<<arr[i];
    }   
    return 0;
}