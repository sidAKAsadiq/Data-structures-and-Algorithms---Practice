#include <iostream>
#include <string>

using namespace std;

void map(int n){
    if(n==0)
    cout<<" zero ";
    else if(n==1)
    cout<<" one ";
    else if(n==2)
    cout<<" two ";
    else if(n==3)
    cout<<" three ";
    else if(n==4)
    cout<<" four ";
    else if(n==5)
    cout<<" Five ";
}


void Say_digit(int n){
int digit;
//Base case
if((n/10)==0){
    map(n);
    return;
}
    
//Processing
digit=n%10;
n=n/10;

//Recrusive call
Say_digit(n);
map(digit);

}

int main() {
    int n;
    cin>>n;
    Say_digit(n);
    return 0;
}