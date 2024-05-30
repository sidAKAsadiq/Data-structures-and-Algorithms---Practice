#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
  string str;
  cin>>str;    
  stack<char> s;
  for(int i=0;i<str.length();i++){
    s.push(str[i]);
  }
  for(int i=0;i<str.length();i++){
    cout<<s.top();
    s.pop();
  }  
}