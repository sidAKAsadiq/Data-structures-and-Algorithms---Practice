#include <iostream>
#include <string>
#include <vector>
#include<math.h>


using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* arb;

    Node(){
        next=NULL;
        arb=NULL;
        data = 0;
    };
    Node(int data){
        this->data = data;
        arb=NULL;
        next=NULL;
    }
    void Insert_at_head(Node* &head){
        cout<<"enter Value to insert at head\n";
        int input;
        cin>>input;
        Node* new_node = new Node(input);
        new_node->next=head;        
        head=new_node;
    }
        void Insert_at_head_new(Node* &head, int value){
        Node* new_node = new Node(value);
        new_node->next=head;        
        head=new_node;
    }
    void Insert_at_Tail(Node * &tail){
        cout<<"enter Value to insert at tail\n";
        int input;
        cin>>input;
        Node* new_node = new Node(input);
        tail->next=new_node;
        tail=new_node;

    }
        void Insert_at_Tail_new(Node * &tail,int value){
        Node* new_node = new Node(value);
        tail->next=new_node;
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
            temp_pointer=temp_pointer->next;
        }
        new_node->next = temp_pointer->next;  
        temp_pointer->next=new_node;
        //If inserting at the last node, we have to update the Tail
        if(new_node->next==NULL){
            tail=new_node;
        }        

    }

    void Delete_node(Node* &head, Node* &tail){
        int positon;
        cout<<"Enter postion from which node is to be deleted\n";
        cin>>positon;
        //If we want to delete at postion 1 , then just update the head
        if(positon==1){
            head = head->next ;
            return;
        }
        Node * access_deleting = head;
        Node * access_previous = head;

        for(int i=1;i<positon;i++){
                //To access the node being deleted
                access_deleting = access_deleting->next;
        }
        for(int j=1;j<positon-1;j++){
            // To access the node before the one thats being deleted
            access_previous=access_previous->next;
        }
        access_previous->next=access_deleting->next;
        tail = access_previous;

    }





    void Traverse_Linked_list(Node* &head){
        Node *temp = new Node;
        temp=head;
         while(temp!=NULL){
             cout<<temp->data<<" ";
             temp = temp->next;
         }

    cout<<endl;
    }
        void Traverse_Linked_list_arb(Node* &head){
        Node *temp = new Node;
        temp=head;
        int nodes = number_of_nodes(head);
        int count = 0;
         while(count != nodes){
             cout<<temp->data<<" ";
             count++;
             temp = temp->arb;
         }
    cout<<endl;
    }
        int number_of_nodes(Node* &head){
        Node* temp = head;
        int counter = 1;
        while (temp->next != NULL && temp->next != head){
            temp = temp->next;
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
            temp = temp->next;
            count++;
        }
        
        //Condition to check if its circular
        if(temp->next == head){
            cout<<"This is a circular LL\n";
        }
        else{
            cout<<"This is NOT a circular LL\n";
        }
    }
    void reverse_the_link_list(Node* &head, Node* &tail){
    Node* ahead = head;
    Node* previous = head;
    Node* store = NULL;
    ahead = head->next;
    head->next = NULL;
    while(ahead != NULL){
    store = ahead->next;
    ahead->next = previous;
    previous = ahead;
    ahead = store;
}
    head = previous;

    // To update tail
    Node* tail_updater = head;
    while(tail_updater->next != NULL){
        tail_updater = tail_updater->next;
}
    tail = tail_updater;

}
void clone_LL_with_arb_ptr(Node* &head,Node* &tail){
    //1st clone the LL normally , ignoring the arb ptr
    Node* temp_org = head;
    Node* head_clone = new Node(temp_org->data);
    temp_org = temp_org->next;
    Node* tail_clone = head_clone;
    while(temp_org != NULL){
        head_clone->Insert_at_Tail_new(tail_clone,temp_org->data);
        temp_org = temp_org->next;
    }
    //Copying the Random pointers
    Node* traverse_org = head;
    Node* traverse_clone_checker = head_clone;
    Node* temp_clone_setter = head_clone;
    int nodes = number_of_nodes(head);
    int counter = 0;
    while(counter != nodes){
        if(traverse_org->arb->data == traverse_clone_checker->data){
            temp_clone_setter->arb = traverse_clone_checker;
            temp_clone_setter = temp_clone_setter->next;
            traverse_org = traverse_org->next;
            traverse_clone_checker = head_clone;
            counter++;
        }
        else{
            traverse_clone_checker = traverse_clone_checker->next;
        }
       // head->Traverse_Linked_list(head);

    }
        head->Traverse_Linked_list_arb(head_clone);

}

  
};



int main() {
    Node* head = new Node(3);
    Node* tail = head;
    head->Insert_at_Tail_new(tail,5);
    head->Insert_at_Tail_new(tail,7);
    head->Insert_at_Tail_new(tail,9);
    head->arb = head->next->next;
    head->next->arb = head;
    head->next->next->arb = tail;
    tail->arb = head->next;
    head->Traverse_Linked_list_arb(head);
    head->clone_LL_with_arb_ptr(head,tail);

    return 0;
}