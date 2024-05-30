#include <iostream>
#include <string>

using namespace std;

int power_of_2(int n){
//Base case 
if(n==1){
    return 2;
}           
if(n==0){       //Both base cases are valid here!
    return 1;
}
//Recursive relation
int ans = 2 * power_of_2(n-1);

//Return
return ans;
}

int main() {
    int power;
    cin>>power;
    cout<<power<<"th of 2 is : "<<power_of_2(power)<<endl;
    return 0;
}