#include <iostream>
#include <string>
#include <stack>
#include<vector>
using namespace std;

int main() {
  vector<int> a;
  a.push_back(1);
  a.pop_back();
  cout<<a[a.size()-1];
    return 0;
}