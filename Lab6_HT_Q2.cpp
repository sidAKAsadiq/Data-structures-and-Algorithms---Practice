#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

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
    int arr[10000];
    clock_t s,e;
    for(int i=0;i<20;i++){
        cout<<"Iteration no. "<<i+1<<endl;;
        //Filling array with 0-1000 nums
        for(int i=0;i<10000;i++){
            arr[i] = rand()%1000;
        }
        s = clock();
        quick_sort(arr,0,10000-1);
        e = clock();
        cout<<"Time taken by MS on UNsorted array: "<<fixed<<double(e-s)/double(CLOCKS_PER_SEC)<<"\t";
        s = clock();
        quick_sort(arr,0,10000-1);
        e = clock();
        cout<<"Time taken by MS on sorted array: "<<fixed<<double(e-s)/double(CLOCKS_PER_SEC)<<"\t";
        cout<<endl;
    }
    /*Explaination:
    Note that here the time taken by Merge sort on sorted array is almost double than the time taken by it on UNsorted array. I think this is due to the fact that merge sort doesnt checks if the array is already sorted or not and the time complexity of MS on already sorted array is almost O(n^2) i.e Worst case scenario
    */

    return 0;
}