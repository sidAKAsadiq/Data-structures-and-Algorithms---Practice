#include<iostream>
using namespace std;
//Pivot -> Min element -> element from which an array is rotated
int find_pivot_element(int rot_arr[],int size){
    int i,start,end,mid;
    start=0;
    end=size-1;
    mid=start+((end-start)/2);
    while(start<=end){
        if(rot_arr[mid]<rot_arr[mid-1] && rot_arr[mid]<rot_arr[mid+1]){
            return mid;
        }
        else if(rot_arr[mid]>=rot_arr[0]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    mid=start+((end-start)/2);
    }
}
main(){
    int rot_arr[6]={7,9,10,1,2,3};
    cout<<"Pivot element index : "<<find_pivot_element(rot_arr,6);
}