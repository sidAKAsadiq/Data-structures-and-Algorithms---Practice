#include <iostream>
#include <string>

using namespace std;
//Fibonacci series
int fibonacci_series(int n){
    // base case 
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }

    //Recurisve call
    return fibonacci_series(n-1)+fibonacci_series(n-2);
}
int main() {
    
   // cout<<"Nth number in fibonacci series is : "<<fibonacci_series(8);
    cout<<"hello "<<412/10<<endl;
    return 0;
}