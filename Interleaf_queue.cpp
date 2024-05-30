#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
  vector<int> copy;
    while(!q.empty()){
    copy.push_back(q.front());
    q.pop();
}
for(int i = 0 ; i<copy.size() ; i++){
    cout<<copy[i]<<" ";
}
//int index = (q.size()/2)-1;
int left = 0;
int right = copy.size()/2;
cout<<"\n right "<<right<<endl;
while(right<copy.size()){
    q.push(copy[left]);
    q.push(copy[right]);
    left++;
    right++;
    //return 0;
}
cout<<q.front()<<endl;

}