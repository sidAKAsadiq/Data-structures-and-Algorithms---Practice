#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    
  stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);

  s.pop();

  cout<<"Peak/top element : "<<s.top()<<endl;

  if(s.empty()){
    cout<<"\n Stack is empty\n";
  }
  else{
    cout<<"Stack is not empty\n";
  }

  cout<<"Stack's size is : "<<s.size()<<endl;
    return 0;
}