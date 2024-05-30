#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* previous;
    Node(){
        data = 0;
        next = previous = NULL;
    }
    Node(int d){
        data = d;
        next= previous = NULL;
    }
    ~Node(){
        delete next;
        next = NULL;
        delete previous;
        previous = NULL;
    }
};

class Double_cicular_LL{
    public:
    Node* head;
    Node* tail;
    Double_cicular_LL(){
        head = tail = NULL;
    }
    Double_cicular_LL(int data){
        head->next = NULL;
        head->previous = NULL;
        head->data = data;
        tail = head;
    }
    Double_cicular_LL(Node* n){
        head = tail = n;
    }
    void add_to_head(int data){
        if(head==NULL){
            head = new Node;
            head->data = data;
            head->next = head;
            head->previous = head;
            tail = head;
            return;
        }
        Node* new_node = new Node(data);
        new_node->next = head;
        new_node->previous = tail;
        head->previous = new_node;
        head = new_node;
    }
    void add_to_tail(int data){
        if(head==NULL){
            head = new Node;
            head->data = data;
            head->next = head;
            head->previous = head;
            tail = head;
            return;
        }
        Node* new_node = new Node(data);
        tail->next = new_node;
        new_node->previous = tail;
        new_node->next = head;
        tail = new_node;
    }    
    void add_at_index(int data,int index){
        if(index==1){
            add_to_head(data);
            return;
        }
        Node* new_node = new Node(data);
        Node* access_index = head;        
        int counter = 1;
        while(counter != index){
            access_index = access_index->next;
            counter++;
        }
        if(access_index == head){
            add_to_tail(data);
            return;
        }
        new_node->next = access_index;
        new_node->previous = access_index->previous;
        access_index->previous->next = new_node;
        access_index->previous = new_node;
    }
    void delete_from_end(){
        Node* access_new_tail = tail->previous;
        access_new_tail->next = head;
        head->previous = access_new_tail;
        Node* delete_node = tail;
        tail = access_new_tail; //New tail updated
        //Deleting previous tail
        delete_node = NULL;
        delete delete_node;
    }    
    void traverse(){
        Node* temp = head;
        cout<<temp->data<<" ";
        temp = temp->next;
        while(temp!=head){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }    
};
main(){
    Double_cicular_LL d1;
    d1.add_to_head(2);
    d1.add_to_tail(23);
    d1.add_at_index(100,3);
    d1.delete_from_end();
    d1.traverse();
}