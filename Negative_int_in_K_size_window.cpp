#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main() {
 queue <int> q;
 q.push(1);
 q.push(2);
 q.push(3);
 q.push(4);
 q.push(5);
 int size = 5;
 int k = 3;
 stack<int> s;
 for(int i=0;i<k;i++){
    s.push(q.front());
    q.pop();
 }
 while(!s.empty()){
    q.push(s.top());
    s.pop();
 }
 cout<<q.front();  //4 5 3 2 1
 for(int i = size-k-1 ; i>=0 ; i--){
    q.push(q.front());
    q.pop();
 }
 cout<<q.front();  //4 5 3 2 1
q.s



    return 0;
}