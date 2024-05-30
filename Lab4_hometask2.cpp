#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
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
    void delete_from_head(){
        Node* temp = head;
        head = head->next;
        head->previous = NULL;
        temp = NULL;
        delete temp;
    }
    void delete_from_tail(){
        Node* temp  = tail;
        Node* updated_tail = head;
        while(updated_tail->next != tail){
            updated_tail = updated_tail->next;
        }
        tail = updated_tail;
        tail->next = NULL;
        temp = NULL;
        delete temp;
    }
    void delete_from_any_position(int position){
        if(position == 1){
            delete_from_head();
            return;
        }
        int counter = 1;
        Node* temp = head;
        Node* deleting_node = head->next;

        while(counter != position-1){
            temp = temp->next;
            deleting_node = deleting_node->next;
            counter++;
        }
        if(deleting_node == tail){
            delete_from_tail();
            return;
        }
        temp->next = deleting_node->next;
        deleting_node->next->previous = temp;
        deleting_node = NULL;
        delete deleting_node;
    }
        void bubble_sort_on_LL(){
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
    void traverse(){
        ofstream f("file3.txt", ios::app);
        f<<"Question 2: \n";
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            f<<temp->data;
            f<<"\n";
            temp = temp->next;
        }
        f.close();
        cout<<endl;
    }
        int count_number_of_nodes(){
        Node* temp = head;
        int counter = 1;
        while(temp->next!=NULL){
            temp = temp->next;
            counter++;
        }
        return counter;
    }
};

main(){
    ifstream ff("file.txt");
    ofstream f("file3.txt");
    string line;
    while (getline(ff, line)) {
        f << line << endl;
    }
    ff.close(); 
    f.close();

    Doubly_LL d1;
    int num;
    for(int i=0;i<5;i++){
        cout<<"Enter num to insert into Doubly LL\n";
        cin>>num;
        d1.add_to_tail(num);
    }
    d1.bubble_sort_on_LL();
    d1.traverse();

}