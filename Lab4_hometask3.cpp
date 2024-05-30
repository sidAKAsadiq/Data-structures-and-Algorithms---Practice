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
    void delete_from_head(){
        Node* temp = head;
        head = head->next;
        tail->next = head;
        head->previous = tail;
        temp = NULL;
        delete temp;
    }
    void delete_from_tail(){
        Node* access_new_tail = tail->previous;
        access_new_tail->next = head;
        head->previous = access_new_tail;
        Node* delete_node = tail;
        tail = access_new_tail; //New tail updated
        //Deleting previous tail
        delete_node = NULL;
        delete delete_node;
    }    
    void delete_from_any_position(int position){
        if(position==1){
            delete_from_head();
            return;
        }
        Node* temp = head;
        Node* deleting_node = head->next;
        int counter = 1;
        while(counter != position-1){
            temp = temp->next;
            deleting_node = deleting_node->next;
            counter++;
        }
        if(deleting_node==tail){
            delete_from_tail();
            return;
        }
        temp->next = deleting_node->next;
        deleting_node->next->previous = temp->next;
        deleting_node = NULL;
        delete deleting_node;
    }
    void traverse(){
        Node* temp = head;
        cout<<temp->data<<" ";
        temp = temp->next;
        while(temp!=head){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }    
    void bubble_sort_on_LL(){
        cout<<"here\n";
        Node* access_previous = head;
        Node* access_ahead = head->next;
        int counter = 1;
        while(counter != count_number_of_nodes()+1){
                while(access_previous->next != NULL){
                    if(access_previous->data > access_ahead->data){
                        swap(access_previous->data,access_ahead->data);
                    }
                    access_previous = access_previous->next;
                    access_ahead = access_previous->next;
                }
                access_previous = head;
                access_ahead = access_previous->next;
                counter++;
        }
    }
        int count_number_of_nodes(){
        cout<<"Here2\n";
        Node* temp = head;
        int counter = 1;
        while(temp->next!=NULL){
           // cout<<"Here3\n";
            temp = temp->next;
            counter++;
        }
        cout<<"Counter : "<<counter;
        return counter;
    }
};
main(){
    Double_cicular_LL d1;
    d1.add_to_head(2);
    d1.add_to_tail(23);
    d1.add_to_tail(5);
    d1.add_to_tail(0);
    d1.add_to_tail(9);
    d1.traverse();
    d1.bubble_sort_on_LL();
    d1.traverse();


}