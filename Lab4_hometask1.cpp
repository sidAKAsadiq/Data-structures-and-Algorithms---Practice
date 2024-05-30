#include <iostream>
#include <string>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){
        data = 0;
        next = NULL;
    }
    Node(int data){
        this->data = data;
        next = NULL;
    }
    ~Node(){
        next = NULL;
        delete next;
    }
};

class Circular_LL{
    public:
    Node* head;
    Node* tail;
    Circular_LL(){
        head = tail = NULL;
    }
    Circular_LL(int data){
        head->data = data;
        head->next = head;
        tail = head;
    }
    Circular_LL(Node* n){
        head = tail = n;
        head->next = head;
    }
    void insert_at_head(int data){
        if(head==NULL){
            head = new Node;
            head->data = data;
            head->next = head;
            tail = head;
            return;
        }
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
        tail->next = head;
    }
    void insert_at_tail(int data){
        if(head==NULL){
            head = new Node;
            head->data = data;
            head->next = head;
            tail = head;
            return;
        }     
        Node* new_node = new Node(data);
        tail->next = new_node;
        tail = new_node;
        tail->next = head;   
    }
    void insert_at_given_position(int data , int position){
        if(position==1){
            insert_at_head(data);
            return;
        }
        Node* new_node = new Node(data);
        Node* temp = head;
        int counter = 1;
        while(counter != position-1){
            temp = temp->next;
            counter++;
        }
        if(temp==tail){
            insert_at_tail(data);
            return;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    void delete_from_head(){
        Node* temp = head;
        head = head->next;
        tail->next = head;
        temp = NULL;
        delete temp;

    }
    void delete_from_tail(){
        //cout<<"\ntail "<<tail->data<<"head"<<head->data<<endl;;
        Node* temp = tail;
        //Update tail
        Node* updated_tail = head;
        while(updated_tail->next != tail){
            updated_tail = updated_tail->next;
        }
        //cout<<"\nUpdated tail"<<updated_tail->data<<endl;
        tail = updated_tail;
        tail->next = head;
        temp = NULL;
        delete temp;
    }
    void delete_from_any_position(int position){
        if(position==1){
            delete_from_head();
            return;
        }
        Node* temp = head;
        int counter = 1;
        while(counter != position-1){
            temp = temp->next;
            counter++;
        }
        if(temp->next==tail){
            delete_from_tail();
            return;
        }
        Node* store = temp->next->next;
        Node* delete_node = temp->next;
        temp->next = store;
        delete_node = NULL;
        delete delete_node;
    }
    void traverse(){
        Node* temp = head;
        cout<<temp->data <<" ";
        temp = temp->next;
        while(temp!=head){
        cout<<temp->data <<" ";
        temp = temp->next;            
        }
        cout<<endl;
    }
};




int main() {
    Circular_LL c1;
    c1.insert_at_head(1);
    c1.insert_at_head(12);
    c1.insert_at_head(13);
    c1.insert_at_tail(2);
    c1.insert_at_tail(3);
    c1.insert_at_tail(5);
    c1.insert_at_given_position(40,4);
    c1.traverse();
    c1.delete_from_head();
    c1.traverse();
    c1.delete_from_any_position(3);
     c1.traverse();
    return 0;
}