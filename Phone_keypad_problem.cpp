#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(string map[],string input,int index_of_input,vector <string>& answer,string output){

// Base case 
if(index_of_input==input.length()){
    answer.push_back(output);
    return;
}
    
int digit = input[index_of_input] - '0';
string value = map[digit-2];
for(int i=0; i<value.length();i++){
    output.push_back(value[i]);
    solve(map,input,index_of_input+1,answer,output);
    output.pop_back(); // Back Tracking to make the string empty
}

}

int main() {
    string map[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string input;
    cin>>input;
    int index_of_input = 0;
    vector <string> answer;
    string output;
    solve(map,input,index_of_input,answer,output);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }   
    return 0;
}