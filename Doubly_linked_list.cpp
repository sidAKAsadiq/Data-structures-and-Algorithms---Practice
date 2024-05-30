#include <iostream>
#include <string>

using namespace std;


class Node{
public : 
int data;
Node* previous_address;
Node* next_address;

Node(int data){
    this->data = data;
    previous_address = NULL;
    next_address = NULL;
}
Node(){
    previous_address = NULL;
    next_address = NULL;    
}

void Traverse_doubly_LL (Node * &head ){
Node * temp = new Node;
temp = head;
while (temp!= NULL){
    cout<<temp->data<<" ";
    temp = temp->next_address;
}
}

void Insert_at_head (Node * &head){
cout<<"Input data of new node to be inserted at head\n";
int input;
cin>>input;
Node* new_node = new Node(input);
new_node->next_address = head;
head->previous_address = new_node;
head = new_node;

}

void Insert_At_Tail (Node * &tail){
cout<<"Input data of new node to be inserted at Tail\n";
int input;
cin>>input;
Node * new_node = new Node (input);
new_node->previous_address = tail;
tail->next_address = new_node ; 
tail = new_node;
}

void Delete_node (Node * &head){
    cout<<"Postion from where node is to be deleted\n";
    int position;
    cin>>position;
    Node* access_position = head;
    Node* access_previous = head;
    Node* access_ahead = head;

    //To access postion
    for(int i = 1 ; i < position ; i++){
     access_position = access_position->next_address; 
    }
    //To access 1 node before postion 
        for(int i = 1 ; i < position - 1 ; i++){
     access_previous = access_previous->next_address; 
    }
    //To access 1 node ahead of position
            for(int i = 1 ; i < position + 1 ; i++){
     access_ahead = access_ahead->next_address; 
    }
    access_previous->next_address = access_ahead;
    access_ahead->previous_address = access_previous;
    access_position->next_address =  NULL;
    access_position->previous_address = NULL;
    delete access_position;
}
int calculate_number_of_nodes(Node* &head){
    Node* calculator = head;
    int counter = 0;
    while (calculator != NULL){
        calculator = calculator->next_address;
        counter ++;
    }
    return counter;
}

void Insert_at_any_position(Node* &head,Node * &tail){
cout<<"Enter value of node to be inserted\n";
int value;
cin>>value;
cout<<"Enter position at which node is to be inserted\n";
int position;
cin>>position;
//If to be inserted at head
if(position == 1){
    Insert_at_head(head);
    return;
}
//If to be inserted at Tail
if (position == calculate_number_of_nodes(head) + 1){
    Insert_At_Tail(tail);
    return; 
}
//If to be inserted at any position except head or tail
Node* new_node = new Node(value);
Node* access_previous = head;
Node* access_ahead = head;
//To access 1 previous position
for(int i = 1 ; i <position - 1 ; i++) {
    access_previous = access_previous->next_address;
}
//To access 1 ahead position
for(int i = 1 ; i <position ; i++) {
    access_ahead = access_ahead->next_address;
}
access_previous->next_address = new_node;
new_node->previous_address = access_previous;
new_node->next_address = access_ahead;
access_ahead->previous_address = new_node;
 


}


};




int main() {
Node* head = new Node(10);
Node* tail = head;
head->Insert_at_head(head);
head->Traverse_doubly_LL(head);
head->Insert_At_Tail(tail);
head->Traverse_doubly_LL(head);
head->Insert_At_Tail(tail);
head->Traverse_doubly_LL(head);
head->Delete_node(head);
head->Traverse_doubly_LL(head);
head->Insert_at_any_position(head,tail);
head->Traverse_doubly_LL(head);
cout<<"\n"<<tail->previous_address->data;
cout<< "Number of node : "<<head->calculate_number_of_nodes(head);


  
    return 0;
}