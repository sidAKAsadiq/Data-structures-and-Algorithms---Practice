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
    //This function refers to task # 6
    void check_palindrome(){
        int* arr = new int[count_number_of_nodes()];
        Node* temp = head;
        int index = 0;
        while(temp != NULL){
            arr[index] = temp->data;
            temp  = temp->next;
            index++;
        }
        int start = 0;
        int end = count_number_of_nodes() - 1;
        //checking palindrome , start will iterate from left to right and end will iterate from right to left until they cross each other
        while(start<=end){
           if(arr[start] == arr[end]){
            start++;
            end--;
            continue;
           } 
           else{
            cout<<"not a palindrome linkedlist\n";
            return;
           }
        }
        cout<<"Palindrome linkedlist\n";
    }
    //This function refers to task # 7
    void selection_sort_on_LL(){
        Node* hold_minimum_value = head;
        Node* traverse = head->next;

        while(hold_minimum_value->next != NULL){
                while(traverse != NULL){
                    if(hold_minimum_value->data>traverse->data){
                        swap(hold_minimum_value->data,traverse->data);
                    }
                    traverse = traverse->next;
                }
                hold_minimum_value = hold_minimum_value->next;
                traverse = hold_minimum_value->next;
        }
    }
    //This function refers to task # 7
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
        //This function refers to task 7 of lab 3 and task 1 of lab 4
    void bubble_sort_on_LL_swapping_nodes(){
      //  Node* counter = head;
        Node* access_previous = head;
        Node* access_previous_previous = head;
        Node* access_ahead = head->next;
        Node* store = new Node;
        int counter = 1;

        while(counter != count_number_of_nodes()){
            while(access_ahead != NULL){
                //cout<<"here2";
                if(access_previous->data > access_ahead->data){
                    store = access_ahead->next; 
                    if(access_previous == head){
                    head = access_ahead;
                    }
                }

                if(access_previous == head){
                    if(access_previous->data > access_ahead->data){
                        store = access_ahead->next;
                        head = access_ahead;
                        access_ahead->next = access_previous;
                        access_previous->next = store;
                        access_previous_previous = access_ahead;
                        access_ahead = access_previous->next;
                    }
                    else{
                        access_previous = access_ahead;
                        access_ahead = access_previous->next;
                    }
                }
                else{
                    if(access_previous->data > access_ahead->data){
                    store = access_ahead->next;
                    access_ahead->next = access_previous;
                    access_previous_previous->next = access_ahead;
                    access_previous->next = store;
                    access_previous_previous = access_ahead;
                    access_ahead = access_previous->next;
                    }
                    else{
                        access_previous_previous = access_previous;
                        access_previous = access_ahead;
                        access_ahead = access_previous->next;
                    }
                }
            }
            //     traverse_LL();
            // cout<<"here";
           // counter = counter->next;
            counter++;
            access_previous = head;
            access_previous_previous = head;
            access_ahead = head->next;
        }
    }
        void sorting_subsequent_nodes(){
            Node* access_ahead = head->next;
            Node* access_previous = head;


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
    s1.add_to_end_of_LL(5);
    s1.add_to_end_of_LL(1);
    s1.add_to_end_of_LL(0);
    s1.add_to_end_of_LL(25);
    s1.add_to_end_of_LL(22);
    s1.add_to_end_of_LL(-1);
    s1.add_to_end_of_LL(-10);
    s1.traverse_LL();
    s1.bubble_sort_on_LL_swapping_nodes();
    s1.traverse_LL();
    }