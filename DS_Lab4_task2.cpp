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

class Doubly_LL{
    public:
    Node* head;
    Node* tail;
    Doubly_LL(){
        head = tail = NULL;
    }
    Doubly_LL(int data){
        head->next = NULL;
        head->previous = NULL;
        head->data = data;
        tail = head;
    }
    Doubly_LL(Node* n){
        head = tail = n;
    }
    void add_to_head(int data){
        if(head==NULL){
            head = new Node;
            head->data = data;
            head->next = head->previous = NULL;
            tail = head;
            return;
        }
        Node* new_node = new Node(data);
        new_node->next = head;
        new_node->previous = NULL;
        head->previous = new_node;
        head = new_node;
    }
    void add_to_tail(int data){
        if(head==NULL){
            head = new Node;
            head->data = data;
            head->next = head->previous = NULL;
            tail = head;
            return;
        }
        Node* new_node = new Node(data);
        tail->next = new_node;
        new_node->previous = tail;
        new_node->next = NULL;
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
        if(access_index == NULL){
            add_to_tail(data);
            return;
        }
        new_node->next = access_index;
        new_node->previous = access_index->previous;
        access_index->previous->next = new_node;
        access_index->previous = new_node;
    }
    void check_palindrome(){
        Node* left = head;
        Node* right = tail;
        //This condition is only valid when we have odd number of nodes - will also work for even but won't be efficent
        while(left != right){
            if(left->data == right->data){
                left = left->next;
                right = right->previous;
                continue;
            }
            else{
                cout<<"Not a Palindrome\n";
                return;
            }
        }
        cout<<"Palindrome LinkedList\n";
    }
    void traverse(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

main(){
    Doubly_LL d1;
    d1.add_to_tail(1);
    d1.add_to_tail(0);
    d1.add_to_tail(0);
    d1.add_to_tail(1);
    d1.traverse();
    d1.check_palindrome();
}