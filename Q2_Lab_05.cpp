#include <iostream>
using namespace std;

int find_fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }

    int ans = find_fibonacci(n-1) + find_fibonacci(n-2);
    return ans;

}
void print_fibonacci(int n){
    int i;
    for( i = 0 ; i<n ;i++){
        cout<<find_fibonacci(i)<<" ";
    }
}



main(){
print_fibonacci(13);

}