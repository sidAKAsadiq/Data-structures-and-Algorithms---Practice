#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string str;
    cin>>str;
    bool right_found = false;
    int count = 0;
    //Checking if the string is already a valid one or not
    for(int i = 0 ; i<str.length() ; i++){
        if(str[i] == '{'){
            count++;
            right_found = true;
        }
        else{
            if(right_found==false){
                cout<<"invalid\n";
                count--;
                //return 0 ;
            }
            else{
                count--;
                if(count==0){
                    right_found=false;
                }
            }
        }
        
    }
    if(count==0){
        cout<<"valid\n";
        //return 0;
    }
    else{
        cout<<"invalid\n";
    }
    int right_brackets = 0;
    int left_brackets  = 0;
    for(int i = 0 ; i<str.length() ; i++){
        if(str[i]=='{'){
            right_brackets++;
        }
        else{
            left_brackets++;
        }
    }
    cout<<"Rigth : "<<right_brackets<<endl;
    cout<<"left : "<<left_brackets<<endl;
    if((right_brackets - left_brackets == 1) || (left_brackets - right_brackets == 1)){
        cout<<"cant be fixed\n";
        return -1;
    }
    if(right_brackets > left_brackets){

        if((right_brackets - left_brackets)%2 != 0){
            cout<<"cant be fixed\n";
            return -1;
        }
        else{
            cout<<(right_brackets - left_brackets)/2;
            return (right_brackets - left_brackets)/2;
        }
    }
    if(left_brackets > right_brackets){

        if((left_brackets - right_brackets)%2 != 0){
            cout<<"cant be fixed\n";
            return -1;
        }
        else{
            cout<<(left_brackets - right_brackets)/2;
            return (left_brackets - right_brackets)/2;
        }
    }

    return 0;
}
