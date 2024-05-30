#include <iostream>
#include <string>

using namespace std;

int factorial(int n){

//Base case 
if(n == 0){ 
    return 1; //0! = 1
}

//Recursive call/relation
int ans = n * factorial(n-1);

//Returning the answer
return ans;



}

int main() {
    int n;
    cin>>n;
    cout<<"Factorial of "<<n<<" : "<<factorial(n)<<endl;
  
    return 0;
}