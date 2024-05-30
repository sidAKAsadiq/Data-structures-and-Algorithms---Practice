#include <iostream>
#include <string>

using namespace std;

class Two_stacks{
int *arr;
int top_1;
int top_2;
int size;
public:
Two_stacks(int s){
    size = s;
    top_1 = -1; //1st stack will be added from left to right
    top_2 = s; // 2nd stack will be added from right to left
    arr = new int [s];
}

void push_in_stack_1(int num){
//To check if space is available
if(top_2 - top_1 <= 1){
    cout<<"Position full\n";
    return;
}
top_1++;
arr[top_1] = num;

}
void push_in_stack_2(int num){
//To check if space is available
if(top_2 - top_1 <= 1){
    cout<<"Position full\n";
    return;
}
top_2--;
arr[top_2] = num;

}

int pop_1(){
    //To check if there is any element present or not
if(top_2 - top_1 == size+1){
    return -1;
}
int temp = top_1;
top_1--;
return arr[temp];

}
int pop_2(){
//To check if there is any element present or not
if(top_2 - top_1 == size+1){
    return -1;
}
int temp = top_2;
top_2++;
return arr[temp];

}
};



int main() {
  Two_stacks s1(3);
  s1.push_in_stack_1(1);
  s1.push_in_stack_1(2);
  cout<<s1.pop_1()<<endl;
  cout<<s1.pop_1()<<endl;
  cout<<s1.pop_2()<<endl;
    return 0;
}