#include<iostream>
#include<string>
using namespace std;
//Array must be sorted either ascendingly or decendigly
//Ascendingly sorted more preferred
//Steps:
//1. Find mid -> 2.Compare -> 3.If found at mid index , execute the relevant code ELSE repeat the same
//Time complexity of Binary Search -> O(log(n))
//Time complexity of Linear Search -> O(n)


//Function for binary search in an array of integer that returns the index at which the key is found
//Otherwise it returns -1

int Binary_Search(int arr[],int length,int key){
    //Considering the array recieved is sorted ascendingly 

    int start=0;
    int end=length-1;
    int mid = start + ((end-start)/2); // It could have been simple formula , but this prevents overflowing of integer from its range

    while(start<=end){
       if(arr[mid]==key){
        return mid;
       }
        else if(key>arr[mid]){
        start=mid+1;
       }
       else{
        end=mid-1;
       }
     mid = start + ((end-start)/2);
    }
    //If start goes infront of end
    return -1; 
}
main(){
int arr1[5]={1,2,3,4,5};   
int arr2[6]={10,20,30,40,50,60};    //Both are sorted array ascendingly
cout<<"1.Index : "<<Binary_Search(arr1,5,4);
cout<<"\n2.Index : "<<Binary_Search(arr2,6,200);

}