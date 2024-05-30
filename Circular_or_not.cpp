#include <iostream>
#include <string>

using namespace std;

class Node { 
    public:
    int data;
    Node* address;
    Node(int data){
        this->data = data;
        address = NULL;
    }
    Node(){
        data = 0;
        address = NULL;
    }

    void insert_at_head(Node* &head , Node* &tail){
        cout<<"Enter valaue to be inserted at head\n";
        int value;
        cin>>value;
        Node* new_node = new Node(value);
        new_node->address = head;
        head = new_node;
        tail->address = head;
    }

    void Traverse_circular_ll(Node* &head , Node* &tail){
       Node* temp = head;
       while(temp != tail ){
        cout<<temp->data<<" ";
        temp = temp->address;
       } 
        cout<<temp->data<<" ";
    }

    void insert_at_tail(Node* &tail){
        cout<<"Enter the value to be inserted at tail\n";
        int value;
        cin>>value;
        Node* new_node = new Node(value);
        new_node->address = tail->address;
        tail->address = new_node;  
        tail = new_node; 
    }

    void insert_at_any_position(Node* &head, Node* &tail){
        cout<<"Enter value to be inserted\n";
        int value;
        cin>>value;
        cout<<"Enter position\n";
        int position;
        cin>>position;
        if(position == 1){
            insert_at_head(head,tail);
            return;
        }
        Node* new_node = new Node(value);
        Node* temp = head;
        
        //To access 1 node before the new node
        for(int i = 1 ; i<position - 1 ;i++){
            temp = temp->address;
        }
        if(temp == tail){
            insert_at_tail(tail);
            return;
        }
        new_node->address = temp->address;
        temp->address = new_node;

    }
    void delete_node(Node* &head){
        int position;
        cout<<"Enter position you want node to be deleted from\n";
        cin>>position;
        Node* acees_deleting = head;
        Node* acess_previous = head;
        //To access the node being deleted
        for(int i = 1; i<position ; i++){
            acees_deleting = acees_deleting->address;
        }
        //To access the node before the one being deleted
        for(int i=1 ; i<position-1 ;i++){
            acess_previous = acess_previous->address;
        }
        acess_previous->address = acees_deleting->address;
        acees_deleting->address = NULL;
        delete acees_deleting;
    }
    int number_of_nodes(Node* &head){
        Node* temp = head;
        int counter = 1;
        while (temp->address != NULL && temp->address != head){
            temp = temp->address;
            counter++;
        }
        return counter;
    }
    void is_this_linked_list_circular_or_not(Node* &head){
        Node* temp = head;
        int length = number_of_nodes(head);
        int count = 1;
        //Reaching the last node of LL
        while(count != length){
            temp = temp->address;
            count++;
        }
        
        //Condition to check if its circular
        if(temp->address == head){
            cout<<"This is a circular LL\n";
        }
        else{
            cout<<"This is NOT a circular LL\n";
        }
    }
    

};




int main() {
  Node* head = new Node (10);
  Node* tail = head;
  cout<<"head : " <<head->data<<" tail : "<<tail->data<<" \n";
  head->insert_at_head(head,tail);
  cout<<"head : " <<head->data<<" tail : "<<tail->data<<" \n";
  head->insert_at_head(head,tail);
  cout<<"head : " <<head->data<<" tail : "<<tail->data<<" \n";
  head->insert_at_tail(tail);
  cout<<"head : " <<head->data<<" tail : "<<tail->data<<" \n";
  head->Traverse_circular_ll(head,tail);
  head->insert_at_any_position(head,tail);
  head->Traverse_circular_ll(head,tail);
  head->delete_node(head);
  head->Traverse_circular_ll(head,tail);
  cout<<"Number of nodes: "<<head->number_of_nodes(head);
  head->is_this_linked_list_circular_or_not(head);


     return 0;
}