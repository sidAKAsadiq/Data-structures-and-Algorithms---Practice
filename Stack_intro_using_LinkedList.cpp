#include <iostream>
#include <string>

using namespace std;

//template <typename int>
class stack_using_LL{
public:
int data;
stack_using_LL* next;  // this is basically top or head of LL
stack_using_LL(){
    next = NULL;
}
stack_using_LL(int data){
this->data = data;
next = NULL;
}
void push(stack_using_LL* &top , int data ){ //this is basically insertion at head
//checking if stack is empty
if(top==NULL){
cout<<"Stack underflow\n";
return;
}
stack_using_LL* new_node = new stack_using_LL;
new_node->data = data;
new_node->next = top;
top = new_node;
}
void pop(stack_using_LL* &top){
if(top == NULL){
    cout<<"Empty stack\n";
    return;
}
stack_using_LL* temp  = new stack_using_LL;
top = top->next;
temp = NULL;
delete temp;
}
int peak(stack_using_LL* &top){
return top->data;
}
void traverse(stack_using_LL* &top){
stack_using_LL* temp = new stack_using_LL;
temp = top;
while (temp != NULL){
cout<<temp->data<<endl;
temp = temp->next;
}
}
bool is_empty(stack_using_LL* &top){
    if(top==NULL){
        return true;
    }
    else{
        return false;
    }
}
int size(stack_using_LL* &top){
    stack_using_LL* temp = top;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}


};



int main() {
   stack_using_LL*  top = new stack_using_LL(10);
   top->push(top,20);
   top->push(top,30);
   top->push(top,40);
   top->traverse(top);
   cout<<top->peak(top);
   //top->pop(top);
   cout<<top->peak(top);
   //top->pop(top);
   //top->pop(top);
  // top->pop(top);
  // top->pop(top);
   cout<<"\n"<<top->is_empty(top);
   cout<<"\n"<<top->size(top);


   //top->traverse(top);

    return 0;
}