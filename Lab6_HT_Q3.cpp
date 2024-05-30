#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include<algorithm>
#include <chrono>
using namespace std;
using namespace chrono;


void binary_search(int* arr,int k){
    int s = 0;
    int e = 999;
    int mid = s + ((e-s)/2);
    while(s<=e){
        if(arr[mid] == k ){
            return ;
        }
        else if(arr[mid] > k){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + ((e-s)/2);
    }
    return ;
}

void interpolation_search(int* arr,int k){
    int s = 0;
    int e = 999;
    int pos = s + (((k-arr[s])*(e-s))/(arr[e]-arr[s]));
    while(s<=e){
        if(arr[pos] == k ){
            return ;
        }
        else if(arr[pos] > k){
            e = pos - 1;
        }
        else{
            s = pos + 1;
        }
        pos = s + (((k-arr[s])*(e-s))/(arr[e]-arr[s]));
    }
    return ;
}

int calculate_uniformity(int*arr){
int dev = 0;
int min = arr[0];
int max = arr[999];
int range = (max - min)+1;
int* freq = new int[range] {0};
for(int i=0;i<1000;i++){
    freq[arr[i]-min]++;

}
int max_freq = -1;
for(int i=0;i<range;i++){
    if(freq[i] > max_freq){
        max_freq = freq[i];
    }
}
for(int i=0;i<range;i++){
    dev = dev + (max_freq-freq[i]);
}
return dev;
}

int main() {
    //This code will run correctly only on online compiler only for unknown reasons!
    clock_t s,e;
    srand(time(0));
    int arr[1000];
    //Initializing array b/w 0-100 
    for(int k=0;k<100;k++){
    for(int i=0;i<1000;i++){
        arr[i] = rand()%100;
    }
    //Sorting array so that we can implement binary and IP search later on
    for(int i=0;i<1000-1;i++){
        for(int i=0;i<1000-1;i++){
            if(arr[i+1] < arr[i]){
                swap(arr[i+1],arr[i]);
            }
        }
    }
    cout<<endl;
    cout<<endl;
    //This will tell us the deviation
    int deviation = calculate_uniformity(arr);
    cout<<"Implementing Binary and Interpolation search on array having deviationn : " << deviation <<endl<<endl;
    int key = rand()%100;   //A random value to be searched in array
    auto start = high_resolution_clock :: now();
     binary_search(arr,key);
    auto end = high_resolution_clock :: now();
    cout<<"Time taken by Binary search: "<<duration_cast<nanoseconds>(end-start).count()<<"\t";
    start = high_resolution_clock :: now();
    interpolation_search(arr,key);
    end = high_resolution_clock :: now();
    cout<<"Time taken by Interpolation search: "<<duration_cast<nanoseconds>(end-start).count()<<"\t";
    cout<<endl;
    }
    /*
    Explaination : 
    Note that here the time taken by IPS is lesser than the time taken by BS. This is due to the fact that IPS tries
    to target the exact location of the key while BS doesnt. However, we know that IPS performs better on data with less deviation or we can say data with more uniformity , but here IPS is also beating BS at places when the deviation is much higher i.e 1000+ , this shows that IPS is indeed a better algorithm
    */
    }