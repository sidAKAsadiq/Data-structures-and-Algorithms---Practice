//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include<algorithm>
#include <chrono>
using namespace std;
using namespace chrono;


void merge_both(int* arr,int s,int mid,int e){
    int* left = new int[mid+1];
    int* right = new int[e-mid];
    for(int i=0;i<=mid;i++){
        left[i] = arr[i];
    }
    int j = 0;
    for(int i=mid+1 ; i<=e ; i++){
        right[j] = arr[i];
        j++;
    }
    int i = 0;
    j = 0;
    int k = 0;
    
    while(i<(mid+1) && j<(e-mid)){
        if(left[i] < right[j]){
            arr[k] = left[i];
            i++;
            k++;
        }
        else{
            arr[k] = right[j];
            j++;
            k++;
        }
    }

    if(i == mid+1){
        while(j<(e-mid)){
            arr[k] = right[j];
            j++;
            k++;            
        }
    }
    else{
        while(i<(mid+1)){
            arr[k] = left[i];
            i++;
            k++;            
        }
    }


}


void merge_sort(int* arr, int s , int e){
    //Base case
    if(s>=e){
        return;
    }
    int mid = s + ((e-s)/2);
    merge_sort(arr,s,mid);
    merge_sort(arr,mid+1,e);
    merge_both(arr,s,mid,e);
}



int divide_arr(int* arr,int s,int e){
int element = arr[e];
int index = s;
int i = s;
while(i<e){
    if(arr[i] < element){
        swap(arr[index],arr[i]);
        i++;
        index++;
    }
    else{
        i++;
    }
}
swap(arr[e],arr[index]);
return index;


}

void quick_sort(int* arr,int s,int e){
    //Base case
    if(s>=e){
        return;
    }
    int pivot = divide_arr(arr,s,e);
    quick_sort(arr,s,pivot-1);
    quick_sort(arr,pivot+1,e);
}



int main() {
    srand(time(0));
    int arr[1000];
    int copy[1000]; //This array will save the original unsorted array as we need the same array for merge and quick sort both
    clock_t s,e;
    //Running 20 iterations
    for(int j=0;j<20;j++){
        cout<<"Iteration no . "<<j+1<<endl;
        //Adding 1000 random elements form 0-100
    for(int i=0;i<1000;i++){
        arr[i] = rand()%100;
        copy[i] = arr[i];
    }
   // s = clock();
    auto start = high_resolution_clock :: now();
    merge_sort(arr,0,999);
   // e = clock();
    auto end = high_resolution_clock :: now();
   // cout<<"Time taken by MS: "<<fixed<<double(e-s)/double(CLOCKS_PER_SEC)<<"\t";
    cout<<"Time taken by MS: "<<duration_cast<nanoseconds>(end-start).count()<<"\t";
    //Re-filling array
    for(int i=0;i<1000;i++){
        arr[i] = copy[i];
    }
   // s = clock();
     start = high_resolution_clock :: now();
    quick_sort(arr,0,999);
    //e = clock();        
     end = high_resolution_clock :: now();
    cout<<"Time taken by QS: "<<duration_cast<nanoseconds>(end-start).count()<<"\t";

//    cout<<"Time taken by QS: "<<fixed<<double(e-s)/double(CLOCKS_PER_SEC)<<"\t";
    cout<<endl;
    }

    cout<<endl<<"Now sorting 900 elemets first and repeating the same work\n\n";
    
    //Running 20 iterations
    for(int j=0;j<20;j++){
        cout<<"Iteration no . "<<j+1<<endl;
        //Adding 1000 random elements form 0-100
    for(int i=0;i<1000;i++){
        arr[i] = rand()%100;
        copy[i] = arr[i];
    }
    //This will sort first 900 elemets in the array
    merge_sort(arr,0,899);

    auto start = high_resolution_clock :: now();
    merge_sort(arr,0,999);
   // e = clock();
    auto end = high_resolution_clock :: now();
   // cout<<"Time taken by MS: "<<fixed<<double(e-s)/double(CLOCKS_PER_SEC)<<"\t";
    cout<<"Time taken by MS: "<<duration_cast<nanoseconds>(end-start).count()<<"\t";
    // s = clock();
    // merge_sort(arr,0,999);
    // e = clock();
    // cout<<"Time taken by MS: "<<fixed<<double(e-s)/double(CLOCKS_PER_SEC)<<"\t";
    //Re-setting array
    for(int i=0;i<1000;i++){
        arr[i] = copy[i];
    }
    //This will sort first 900 elemets in the array
    merge_sort(arr,0,899);

     start = high_resolution_clock :: now();
    quick_sort(arr,0,999);
    //e = clock();        
     end = high_resolution_clock :: now();
    cout<<"Time taken by QS: "<<duration_cast<nanoseconds>(end-start).count()<<"\t";
    // s = clock();
    // quick_sort(arr,0,999);
    // e = clock();        
    // cout<<"Time taken by QS: "<<fixed<<double(e-s)/double(CLOCKS_PER_SEC)<<"\t";
    cout<<endl;
    }    
    return 0;
    
}