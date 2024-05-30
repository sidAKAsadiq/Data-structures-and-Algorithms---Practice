#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string str;
    cin>>str;
    stack<char> s;
    //cout<<"length : "<<str.length()<<endl;
    for(int i = str.length() - 1 ; i>=0 ; i--){
        s.push(str[i]);
    }
    int counter_of_round_bracket = 0;
    bool right_of_round = false;
    int counter_of_square_bracket = 0;
    bool right_of_square = false;
    int counter_of_flower_bracket = 0;
    bool right_of_flower = false;
    while(!s.empty()){
        //this checks if any closing bracket is present before an opening bracket
        if((s.top() == ']' && right_of_square == false) || (s.top() == '}' && right_of_flower == false) || (s.top() == ')' && right_of_round == false)){
            cout<<"Not balanced\n";
            break;
        }
        else if(s.top() == '['){
            s.pop();
            counter_of_square_bracket++;
            right_of_square = true;
        }
        else if(s.top() == '{'){
            s.pop();
            counter_of_flower_bracket++;
            right_of_flower = true;
        }        
        else if(s.top() == '('){
            s.pop();
            counter_of_round_bracket++;
            right_of_round = true;
        }
        else if(s.top() == ']' && right_of_square == true){
            s.pop();
            counter_of_square_bracket--;
        }
        else if(s.top() == '}' && right_of_flower == true){
            s.pop();
            counter_of_flower_bracket--;
        }
        else if(s.top() == ')' && right_of_round == true){
            s.pop();
            counter_of_round_bracket--;
        }        
    }

    if(counter_of_flower_bracket==0 && counter_of_round_bracket==0 && counter_of_square_bracket==0){
        cout<<"Balanced"<<endl;
    }
    return 0;
}