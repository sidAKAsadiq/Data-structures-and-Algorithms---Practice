#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

void merge_left_right(int* arr,int*left,int*right,int left_size,int right_size){
int i = 0;//for left arr
int j = 0;//for right arr
int k = 0;//for org arr

while(i<left_size && j<right_size){
    if(left[i] < right[j]){
        arr[k] = left[i];
        k++;
        i++;
    }
    else{
        arr[k] = right[j];
        k++;
        j++;
    }
}

if(i==left_size){
    //copy remaing right arr
    while(j<right_size){
        arr[k] = right[j];
        j++;
        k++;
    }
}
else{
    while(i<left_size){
        arr[k] = left[i];
        i++;
        k++;
    }    
}

}

void merge_sort(int arr[],int size){
    //Base case -> Rukjao!
    if(size <= 1){ //When length of array = 1 that means its already sorted!
        return;
    }
    int middle = (size) / 2;
    int* left = new int[middle];
    for(int i=0;i<middle;i++){
        left[i] = arr[i];
    }
    int* right = new int[size - middle];
    int j = 0;
    for(int i = middle ; i<size ; i++){
        right[j] = arr[i];
        j++;
    }
    merge_sort(left,middle); //for left
    merge_sort(right,size-middle); //for right
    merge_left_right(arr,left,right,middle,size-middle); //for merging left & right

}



int main(){
    int arr[8] = {3,1,6,8,4,5,7,2};
    int start = 0;
    int end = 7;
    cout<<"Before MS: "<<endl;
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    merge_sort(arr,8);
    cout<<"After MS : "<<endl;
    for(int j=0;j<8;j++){
        cout<<arr[j]<<" ";
    }
    return 0;
}