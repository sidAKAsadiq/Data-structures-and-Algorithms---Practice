#include <iostream>
#include <string>

using namespace std;

void merge(int arr1[],int length_of_arr1,int arr2[],int length_of_arr2,int temp[]){
int length_of_temp=length_of_arr1+length_of_arr2;
//1. Stopping condition will be for the one with smaller length
//2. Copying condition will be for the one with larger length
int i,j,k;  //i for arr1 , j for arr2, k for temp
i=0;j=0,k=0;
if(length_of_arr1>length_of_arr2){
    while(j<length_of_arr2){
        if(arr1[i]<arr2[j]){
            temp[k]=arr1[i];
            i++;
            k++;
        }
        else{
            temp[k]=arr2[j];
            j++;
            k++;
        }
    }
    //Copying remaining elements of the larger array into temp
    while(i<length_of_arr1){
        temp[k]=arr1[i];
        i++;
        k++;
    }
}
else if(length_of_arr2>length_of_arr1){
      while(i<length_of_arr1){
        if(arr1[i]<arr2[j]){
            temp[k]=arr1[i];
            i++;
            k++;
        }
        else{
            temp[k]=arr2[j];
            j++;
            k++;
        }
    }
    //Copying remaining elements of the larger array into temp
    while(j<length_of_arr2){
        temp[k]=arr2[j];
        j++;
        k++;
    }      
}
//For equal lengths
else{
      while(i<length_of_arr1 || j<length_of_arr2){
        if(arr1[i]<arr2[j]){
            temp[k]=arr1[i];
            i++;
            k++;
        }
        else{
            temp[k]=arr2[j];
            j++;
            k++;
        }
    }
    //No copying needed

}
}

int main() {
    int arr1[2]={1,3};
    int arr2[2]={2,4};
    int temp[4]={0,0,0,0};
    merge(arr1,2,arr2,2,temp);

    for(int i=0;i<4;i++){
        cout<<temp[i]<<" ";
    }

    return 0;
}