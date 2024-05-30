#include <iostream>
#include <string>

using namespace std;

bool linear_Search(int arr[],int size,int key){

    //Base case
    if(arr[0]==key){
        return true;
    }
    else if(size==0){
        return false;
    }

    int ans = linear_Search(arr+1,size-1,key);
    return ans;

}

int main() {

    int arr[5]={1,2,3,4,5};
    if(linear_Search(arr,5,2))
    cout<<"Found";
    else
    cout<<"Not found";    

    return 0;
}