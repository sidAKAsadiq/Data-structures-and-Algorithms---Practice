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
                                        // N = length of 1st LL & M = Length of 2nd LL
    void add_2_numbers_represented_by_LL(Node* &head_1 ,int N , Node* &head_2 , int M){
        int number_1 = 0;
        int multiplier = 1 * pow(10,N-1);
        Node* temp = head_1;
        while(temp != NULL){
            number_1 = number_1 + (temp->data * multiplier);
            multiplier = multiplier/10;
            temp = temp->address;
        }
        int number_2 = 0;
        int multiplier_2 = pow(10,M-1) + 1;
        temp = head_2;
        while(temp != NULL){
           number_2 = number_2 + (temp->data * multiplier_2);
           multiplier_2 = multiplier_2/10;
           temp = temp->address; 
        }
        int final_number = number_1 + number_2;
        int digit = final_number % 10;
        Node* head_new = new Node(digit);
        while ((final_number/10) != 0){
            final_number = final_number/10;
            digit = final_number % 10;
            head_new->Insert_at_head_new(head_new,digit);
        }
        head_new->Traverse_Linked_list(head_new);

    }


};

int main() {
    Node* head_1 = new Node(4);
    head_1->Insert_at_head(head_1);
    head_1->Traverse_Linked_list(head_1);
    int N = 2;
    Node* head_2 = new Node(0);
    head_2->Insert_at_head(head_2);
    head_2->Insert_at_head(head_2);
    head_2->Traverse_Linked_list(head_2);
    int M = 3;
    //head_2->Traverse_Linked_list(head_2);
    head_1->add_2_numbers_represented_by_LL(head_1,N,head_2,M);
    
    return 0;
}