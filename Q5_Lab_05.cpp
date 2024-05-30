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
        head = n;
        update_tail();
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
    //This function will return head for the concatenated LL
    Node* concatenate_L_and_M(Node* &head_L,Node* &tail_L,Node* &head_M,Node* &tail_M){
        //Concatenating L and M lists
        tail_L->next = head_M;
        head_M->previous = tail_L;
        return head_L;
    }

    void append_using_recursion(Node* traverse , int data){
        if(traverse == NULL){
            head = new Node;
            head->next = NULL;
            head->previous = NULL;
            head->data = data;
            traverse = head;
            //Node has been appended
            return;
        }
        if(traverse->next == NULL){
            Node* add = new Node(data);
            add->next = NULL;
            add->previous = traverse;
            traverse->next = add;
            traverse = head;
            return;
        }
        append_using_recursion(traverse->next , data);

    }

    void traverse_using_recursion(Node* temp){
        if(temp==NULL){
            return;
        }
        cout<<temp->data<<" ";
        traverse_using_recursion(temp->next);
        
    }

    void update_tail(){
        Node* temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        tail = temp;
    }
    void traverse(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

main(){
    //creating demo L and M doubly Linked Lists
    Node* temp_head = new Node(1);
    Doubly_LL l1(temp_head);
    Node* traverse = l1.head;
    l1.append_using_recursion(traverse , 2);
    l1.append_using_recursion(traverse , 3);
    l1.append_using_recursion(traverse , 4);
    l1.append_using_recursion(traverse , 5);
    Node* temp = l1.head;
    l1.traverse_using_recursion(temp);

}