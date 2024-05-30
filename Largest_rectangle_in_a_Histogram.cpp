#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

int main() {


    int heights[6] = {2,1,5,6,2,3};
    int n = 6;
    vector<int> ans;
    int breath = 1;
    int length;
    for(int i=0 ; i<n ; i++){
        length = heights[i];
        if((i!=0) && (heights[i-1]>=heights[i])){
            //Go to left part
            breath++;
            for(int j=i-2 ; j>=0 ; j--){
                if(heights[j]<heights[i]){
                    break;
                }
                else{
                    breath++;
                }
            }
        }
        if ((i!=n-1) && (heights[i+1]>=heights[i])){
            //Go to right part
            breath++;
            for(int j=i+2 ; j<n ; j++){
                if(heights[j]<heights[i]){
                    break;
                }
                else{
                    breath++;
                }
            }
        }
        ans.push_back(breath*length);
        breath = 1;
    }
    cout<<*max_element(ans.begin(), ans.end());
    return 0;
}