#include <iostream>
using namespace std;


void Hello(int a){
    cout<<"Hello world : "<<a<<endl;
}

main(){

void (*Function_ptr)(int);
Function_ptr = Hello;
Function_ptr(10);



}