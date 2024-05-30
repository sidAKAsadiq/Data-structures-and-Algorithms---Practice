#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cout<<"Enter number of crates\n";
    cin>>n;
    int* crates_and_times = new int[n];
    for(int i=0 ; i<n ;i++){
        cout<<"Enter time for crate.no "<<i+1<<" to be moved out (24 Hrs format)\n";
        cin>>crates_and_times[i];
    }
cout<<"Crates before re-arrangement\n";
     for(int i=0 ; i<n ;i++){
    cout<<crates_and_times[i];
    if(crates_and_times[i]>=12){
        cout<<"P.M";
    }
    else{
        cout<<"A.M";
    }
    cout<<" ";
    
    }
    cout<<endl;

    //As cost of swapping>cost of compare, insertion sort would be best as we need lowest possible no.of swaps

    //Implementing insertion sort

    for(int i=0;i<n-1;i++){
        if(crates_and_times[i]>crates_and_times[i+1]){
                swap(crates_and_times[i],crates_and_times[i+1]);
                if(i!=0){
                    //Track back
                    for(int j=i; j>0 ; j--){
                        if(crates_and_times[j]<crates_and_times[j-1]){
                            swap(crates_and_times[j],crates_and_times[j-1]);
                        }
                        else{
                            break;
                        }
                    }
                }
        }

    }
cout<<"Crates after re-arrangement\n";
 for(int i=0 ; i<n ;i++){
    cout<<crates_and_times[i];
    if(crates_and_times[i]>=12){
        cout<<"P.M";
    }
    else{
        cout<<"A.M";
    }
    cout<<" ";
    }

    return 0;
}