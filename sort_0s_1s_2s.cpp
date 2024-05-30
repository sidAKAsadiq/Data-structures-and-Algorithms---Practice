#include <iostream>
#include <string>
#include <vector>
#include<math.h>


using namespace std;

class Node{
    public:
    int data;
    Node* address;

    Node(){
        address=NULL;
    };
    Node(int data){
        this->data = data;
        address=NULL;
    }
    void Insert_at_head(Node* &head){
        cout<<"enter Value to insert at head\n";
        int input;
        cin>>input;
        Node* new_node = new Node(input);
        new_node->address=head;        
        head=new_node;
    }
        void Insert_at_head_new(Node* &head, int value){
        Node* new_node = new Node(value);
        new_node->address=head;        
        head=new_node;
    }
    void Insert_at_Tail(Node * &tail){
        cout<<"enter Value to insert at tail\n";
        int input;
        cin>>input;
        Node* new_node = new Node(input);
        tail->address=new_node;
        tail=new_node;

    }
    void Insert_At_any_position(Node* &head, Node* &tail){
        cout<<"Enter the postion at which node is to be inserted\n";
        int postion;
        cin>>postion;
        //If inserting at head/start
        if(postion==1){
            Insert_at_head(head);
            return;
        }
        cout<<"Enter the value of node\n";
        int value;
        cin>>value;
        Node * new_node = new Node(value);
        Node* temp_pointer =  head;
        // To access the node before the given postion
        for(int i=1;i<postion-1;i++){
            temp_pointer=temp_pointer->address;
        }
        new_node->address = temp_pointer->address;  
        temp_pointer->address=new_node;
        //If inserting at the last node, we have to update the Tail
        if(new_node->address==NULL){
            tail=new_node;
        }        

    }

    void Delete_node(Node* &head, Node* &tail){
        int positon;
        cout<<"Enter postion from which node is to be deleted\n";
        cin>>positon;
        //If we want to delete at postion 1 , then just update the head
        if(positon==1){
            head = head->address ;
            return;
        }
        Node * access_deleting = head;
        Node * access_previous = head;

        for(int i=1;i<positon;i++){
                //To access the node being deleted
                access_deleting = access_deleting->address;
        }
        for(int j=1;j<positon-1;j++){
            // To access the node before the one thats being deleted
            access_previous=access_previous->address;
        }
        access_previous->address=access_deleting->address;
        tail = access_previous;

    }





    void Traverse_Linked_list(Node* &head){
        Node *temp = new Node;
        temp=head;
         while(temp!=NULL){
             cout<<temp->data<<" ";
             temp = temp->address;
         }

/*2nd psbl condition that can be used in while -> kind of jugaar
         while(1){
             cout<<temp->data<<" "<<endl;
             temp = temp->address;
             if(temp->address==NULL){
                 //This means that we are currently on the last node
             cout<<temp->data<<" "<<endl;
             break;
             }
         }*/


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

    void sort_0s_1s_2s_in_LL(Node* &head){
        int number_of_0s = 0;
        int number_of_1s = 0;
        int number_of_2s = 0;
        Node* count_numbers = head;
        while(count_numbers != NULL){
            cout<<"in first while\n";
            if(count_numbers->data == 0){
                number_of_0s++;
            }
            else if(count_numbers->data == 1){
                number_of_1s++;
            }
            else if(count_numbers->data == 2){
                number_of_2s++;
            }
            else{
                cout<<"Data is not 0 , 1 or 2\n"<<endl;
            }
            count_numbers = count_numbers->address;
        }
            cout<<"1s : "<<number_of_1s<<"\n0s : "<<number_of_0s<<"\n2s "<<number_of_2s<<endl;
        Node* sorter = head;
        int counter = 0;
        while(counter != number_of_0s){
            sorter->data = 0;
            counter++;
            sorter = sorter->address;
        }
        counter = 0;
        while(counter != number_of_1s){
            sorter->data = 1;
            counter++;
            sorter = sorter->address;            
        }
        counter = 0;
        while(counter != number_of_2s){
            sorter->data = 2;
            counter++;
            sorter = sorter->address;            
        }
        }


    };



int main() {
    Node* head = new Node(1);
    Node* tail = head;
    head->Insert_at_Tail(tail);
    tail->Insert_at_Tail(tail);
    tail->Insert_at_Tail(tail);
    tail->Insert_at_Tail(tail);
    head->Traverse_Linked_list(head);
    head->sort_0s_1s_2s_in_LL(head);
    head->Traverse_Linked_list(head);
    return 0;
}