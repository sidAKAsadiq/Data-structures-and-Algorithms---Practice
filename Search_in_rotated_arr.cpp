#include<iostream>
using namespace std;
//Pivot -> Min element -> element from which an array is rotated
int find_pivot_element(int arr[],int size){
    int i,start,end,mid;
    start=0;
    end=size-1;
    mid=start+((end-start)/2);
    while(start<=end){
        if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1]){
            return mid;
        }
        else if(arr[mid]>arr[0]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    mid=start+((end-start)/2);
    }
}
int search_in_rotated_array(int arr[],int size,int key){
    int pivot = find_pivot_element(arr,size);
    cout<<"Pivot index : "<<pivot<<endl;
    int start=0;
    int end=size-1;
    int mid;
    mid = start + ((end-start)/2);
    if(key<arr[0]){\
        //B.S in 1st line
        start=pivot;
        end=size-1;
        mid = start + ((end-start)/2);
        while(start<=end){
            if(arr[mid]==key){
                return mid;
            }
            else if(key<arr[mid]){
                end=mid-1;
            }
            else{
                start=start+1;
            }
        mid = start + ((end-start)/2);
        }
    }
    else{
       // cout<<"here";
        //B.S in 2nd line
        start=0;
        end=pivot-1;
        mid = start + ((end-start)/2);
        while(start<=end){
            if(arr[mid]==key){
                return mid;
            }
            else if(key<arr[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        mid = start + ((end-start)/2);
        }        
    }

}
main(){
    int rot_arr[6]={7,9,10,1,2,3};
    cout<<"Searched element index : "<<search_in_rotated_array(rot_arr,6,7);
}