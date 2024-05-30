#include <iostream>
#include <string>
#include <stack>
using namespace std;

void reverse_stack(stack<int>&s,int num){

//Base case 
if(s.empty()){
 s.push(num);
    return;
}

int nums = s.top();
s.pop();

//Recursive call
reverse_stack(s , nums);


}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.top();
    reverse_stack(s,s.top());
    cout<<s.top();
    return 0;
}