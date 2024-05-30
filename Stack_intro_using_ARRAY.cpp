#include <iostream>
#include <string>
#define n 5
using namespace std;
template<typename T>
class Stack_using_array{
public:
T stack_array [n]; //can be sized according to our own will
int top;
Stack_using_array(){
	top = -1;
}
void push(T data){
	//Checking if stack is already full or not - Stack overflow
	if(top == n-1){
		cout<<"Stack overflow";
		return;
	}
	top++;
	stack_array[top] = data;
}
void pop(){
//Checking if stack is already empty or not - Stack underflow
if(top == -1){
	cout<<"Stack underflow";
	return;
}
top--;
}

T peak(){ //returns top most element in a stack

//Checking if stack is already empty or not 
if(top == -1){
	cout<<"Stack is empty";
	return;
}
return stack_array[top];
}

void traverse_stack(){
//Checking if stack is already empty or not 
if(top == -1){
	cout<<"Stack is empty";
	return;
}
int i;
for(i=top ; i>=0 ; i--){
	cout<<stack_array[i]<<endl;
}
cout<<endl;
}
bool is_empty(){
	if(top==-1){
		return true;
	}
	else{
		return false;
	}
}
bool is_full(){
	if(top==n-1){
		return true;
	}
	else{
		return false;
	}
}
};




int main() {
	Stack_using_array <int> s1;

	return 0;
}