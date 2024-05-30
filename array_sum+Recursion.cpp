#include <iostream>
#include <string>

using namespace std;

  int sum(int arr[],int size,int count=0){
    static int ans=0;
    static int counter=0;
    if(counter==5){
        return 0;
    }
    ans=ans+arr[counter];
    counter++;
    sum(arr,size,counter);
    return ans;


  }

int main() {
    int arr[5]={3,2,5,1,6};
    cout<<"Sum of array : "<<sum(arr,5);
    return 0;
}