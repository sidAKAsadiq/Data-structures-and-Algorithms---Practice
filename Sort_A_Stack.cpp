#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main() {
string str;
cin>>str;
int count = 0;
int flag = false;
//Checking for unbalanced number of Brackets
for(int i = 0 ; i<str.length() ; i++){
if(str[i]=='('){
    count++;
}
else if(str[i]==')'){
    count--;
}
}
if(str[str.length()-2]==')' && str[str.length()-1]==')'){
    cout<<"Redundatn";
    return 0;
}
if(count!=0){
    cout<<"Redundant present\n";
    return 0;
}
for(int i=0;i<str.length()-1 ; i++){
if(str[i]=='(' && str[i+1]=='('){
    cout<<"Redundant Brackets\n";
    return 0;
}
}
cout<<"No redu\n";


return 0;
    }

