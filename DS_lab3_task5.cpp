#include <iostream>

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
    }
    ~Node(){
        delete [] next;
        next = 0;
    }
};
class singly_linked_list{
    public:
    Node* head;
    Node* tail;
    singly_linked_list(){
        head = NULL;
        tail = NULL;
    }
    singly_linked_list(int data){
        head->data = data;
        head->next = NULL;
        tail = head;
    }
    singly_linked_list(Node* &n){
        head = n;
        tail = head;
    }
    void add_to_end_of_LL(int data){
        if(head==NULL){
            //No nodes are exisiting before
            head = new Node;
            head->data = data;
            head->next = NULL;
            tail = head;
            return;
        }
        Node* temp = new Node;
        temp->data = data;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
    void add_to_start_of_LL(int data){
        if(head==NULL){
            head = new Node;
            head->data = data;
            head->next = NULL;
            tail = head;
            return;
        }

        Node* temp = new Node;
        temp->data = data;
        temp->next = head;
        //tail = head;
        head = temp;
    }
    void add_node_after_given_node(){
        cout<<"\nEnter data of node after which you want to insert new node\n";
        int data;
        cin>>data;
        cout<<"Enter data of new node\n";
        int new_data;
        cin>>new_data;
        Node* new_node = new Node(new_data);
        Node* traverse = new Node;
        Node* access_ahead = new Node;
        traverse = head;
        while (traverse->data != data)     {
            traverse = traverse->next;
        }
        //Now we are standing on the node after which new node is to be inserted
        //First accessing the node infront of this node 
        access_ahead = traverse->next;
        traverse->next = new_node;
        new_node->next = access_ahead;
        delete new_node;
        new_node = NULL;
        delete traverse;
        traverse = NULL;
        delete access_ahead;
        access_ahead = NULL;       
    }
    //This function referes to task # 3
    void delete_last_node_aka_tail(){   
 
        //Updating new tail
        Node * traverse = new Node;
        traverse = head;
        while(traverse->next != tail){
            traverse = traverse->next;
        }
        delete tail;
        tail = NULL;
        tail = traverse;
        tail->next = NULL;

    }
    //This function referes to task # 3
    void delete_from_head(){
        Node* temp = head;
        temp = head->next;
        head = temp;
    }
    //This function referes to task # 3
    void delete_by_value(int data){
            if(head->data == data){
                delete_from_head();
                return;  
            }
            Node* access_previous = head; //This will access one node before the node that is going to be deleted
            while (access_previous->next->data != data)
            {
                access_previous = access_previous->next;
            }
            Node* access_deleteing = access_previous->next;
            Node* access_ahead = access_deleteing->next;
            access_previous->next = access_ahead;
            // delete access_deleteing;
            // access_deleteing = NULL;
    }
    //This function referes to task # 3
    void delete_by_index(int index){
        
        if(index==1){
            //deleting from head
            delete_from_head();
            return;
        }
        Node* temp = head;  //This will access 1 node before the node being deleted
        Node* delete_node = head;   //This will access the node being deleted
        int counter = 1;
        while(counter != index-1){
            temp = temp->next;
            counter++;
        }
        if(temp->next->next == NULL){
            //Delete from tail
            delete_last_node_aka_tail();
            return;
        }
        delete_node = temp->next;
        temp->next = delete_node->next;
        delete_node = NULL;
        delete delete_node;

        
    }
    //This function referes to task # 4
    void update_node_value(int previous_value , int new_value){
        Node* temp = head;
        bool found = false;
        while(temp != NULL){
            if(temp->data == previous_value){
                temp->data = new_value;
                found = true;
                return;
            }
            else{
                temp = temp->next;
            }
        }
        if(!found){
            cout<<"No such value found\n";
        }
    }
    //This function refers to task # 5
    void sort_even_before_odd(){
        int store_value;
        Node* temp = head;
        int counter = 1;
        while(counter != count_number_of_nodes()+1){
            if((temp->data%2)!=0){
                store_value = temp->data;
                delete_by_value(store_value);
                add_to_end_of_LL(store_value);
            }
                temp = temp->next;
                counter++;
        }

    }
//  Extra function for my own help
    void traverse_LL(){
        Node* traverse = new Node;
        traverse = head;
        while(traverse != NULL){
            cout<<traverse->data<<" ";
            traverse = traverse->next;
        }
        cout<<endl;
    }
//  Extra function for my own help
    int count_number_of_nodes(){
        Node* temp = head;
        int counter = 1;
        while(temp->next!=NULL){
            temp = temp->next;
            counter++;
        }
        return counter;
    }
    ~singly_linked_list(){
        delete head;
        head = NULL;
        delete tail;
        tail = NULL;
    }
};
main(){
    singly_linked_list s1;
    s1.add_to_end_of_LL(17);
    s1.add_to_end_of_LL(15);
    s1.add_to_end_of_LL(8);
    s1.add_to_end_of_LL(12);
    s1.add_to_end_of_LL(10);
    s1.add_to_end_of_LL(5);
    s1.add_to_end_of_LL(4);
    s1.add_to_end_of_LL(1);
    s1.add_to_end_of_LL(7);
    s1.add_to_end_of_LL(6);
    s1.traverse_LL();
    s1.sort_even_before_odd();
    s1.traverse_LL();


    }