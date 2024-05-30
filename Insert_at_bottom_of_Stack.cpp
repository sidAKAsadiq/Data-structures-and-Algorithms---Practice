#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
  
  stack<int> my_stack;
  my_stack.push(7);
  my_stack.push(1);
  my_stack.push(4);
  my_stack.push(5);
  int* arr = new int[my_stack.size()];
  int length = my_stack.size();
  for(int i=0 ; i<length ; i++){
    arr[i] = my_stack.top();
    my_stack.pop();
  }
    
    int x;
    cin>>x;
    my_stack.push(x);

    for(int i = length - 1 ; i>=0 ; i--){
        my_stack.push(arr[i]);
    }
    arr = NULL;
    delete arr;

    return 0;
}