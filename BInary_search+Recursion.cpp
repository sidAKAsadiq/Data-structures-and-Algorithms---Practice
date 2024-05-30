#include <iostream>
#include <string>

using namespace std;

bool Binary_search(int arr[],int start,int end, int key){
int ans;
int mid = (start+end)/2;
if(start>end){
    return false;
}

if(arr[mid]==key){
    return true;
}
else if(key>arr[mid]){
    ans=Binary_search(arr,mid+1,end,key);
    return ans;
}
else{
    ans=Binary_search(arr,start,mid-1,key);
    return ans;
}

}


int main() {
    int arr[5]={1,2,3,4,5};
    if(Binary_search(arr,0,5-1,200))
    cout<<"Found\n";
    else
    cout<<"Not found\n";
    return 0;
}