#include <iostream>
using namespace std;


int calculate_sq(int n){
    int ans  = 0;
    for(int i = 0 ; i<n ; i++){
        ans+=n;
    }
    return ans;
}

void print_series(int i){
    //Base case
    if(i == 11){
        return;
    }
    cout<<calculate_sq(i)<<" ";
    print_series(i+1);
}


main(){
    print_series(1);
}