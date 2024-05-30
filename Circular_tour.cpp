#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main() {
    vector<int> petrol_array(3);
    vector<int> dist_array(3);
    int n = 3;
    int i=0;
    int j = 0;
    petrol_array[0] = 1;
    petrol_array[1] = 10;
    petrol_array[2] = 3;
    dist_array[0] = 10;
    dist_array[1] = 20;
    dist_array[2] = 10;
    int total_petrol = 0;
    while(j<n){
    total_petrol = total_petrol + petrol_array[i];
    if(total_petrol<dist_array[i]){
        j++;
        i=j;
        total_petrol = 0;
        continue;
    }
    else{
        total_petrol = total_petrol - dist_array[i];
        if(total_petrol<0){
            j++;
            i=j;
            total_petrol = 0;
            continue;
        }
        else{
            if(i==n-1){
                i=0;
            }
            else{
                i++;
            }
            if(i==j){
                cout<<j<<endl;
                break;
            }
        }
    }
    }
    cout<<"-1"<<endl;
    return 0;
}