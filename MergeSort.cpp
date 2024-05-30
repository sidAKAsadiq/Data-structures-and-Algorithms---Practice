#include <iostream>
#include <string>

using namespace std;

void merge(int* arr,int s,int mid,int e){
    //Length of 2 arrays being created
    int len1 = mid - s + 1;
    int len2 = e - mid;

    //Creating 2 array
    int* first = new int[len1];
    int* sec = new int[len2];
    
    //Filling 1st array from s->mid
    int index_of_org_arr = s;
    for(int i=0;i<len1;i++){
        first[i] = arr[index_of_org_arr];
        index_of_org_arr++;
    }
    
    //Filling 2nd array from mid+1 -> e
    index_of_org_arr = mid+1;
    for(int i=0;i<len2;i++){
        sec[i] = arr[index_of_org_arr];
        index_of_org_arr++;
    }

    //Merge both created arrays into main array in sorted order
    int i = 0; //1st arr
    int j = 0; //2nd arr
    int k = s; //main arr

    while(i < len1 && j < len2){
        if(first[i] < sec[j]){
            arr[k] = first[i];
            k++;
            i++;
        }
        else{
            arr[k] = sec[j];
            k++;
            j++;            
        }
    }

    while(i < len1){
            arr[k] = first[i];
            k++;
            i++;       
    }
    while (j < len2){
            arr[k] = sec[j];
            k++;
            j++;         
    }

}

void merge_sort(int* arr,int s,int e){
    //base case
    if(s==e){
        return;
    }
    int mid = (s+e)/2;

    //Sort left part
    merge_sort(arr,s,mid);
    //Sort right part
    merge_sort(arr,mid+1,e);
    //Merge both arrays
    merge(arr,s,mid,e);
}


int main() {
    int n = 6; 
    int arr[6] = {5,4,3,2,1,0};
    int s = 0;
    int e = n-1;
    merge_sort(arr,s,e);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}