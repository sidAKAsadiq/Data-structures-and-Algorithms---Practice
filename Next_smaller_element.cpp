#include <iostream>
#include <string>
#include <stack>
#include<vector>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans;
    bool flag = false;
    for(int i=0 ; i<n ; i++){
        flag=false;
        for(int j=i+1 ; j<n ; j++){
            if(arr[i] > arr[j]){
                ans.push_back(arr[j]);
                flag=true;
                break;
            }
        }
        if(flag==false){
            ans.push_back(-1);
        }
    }
    return ans;
    // Write your code here.
}
int main() {
    cout<<"Solved in O(n^2) Time complexity, can be solved in O(n) by using Stack\n";
    return 0;
}