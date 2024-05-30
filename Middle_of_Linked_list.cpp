#include <iostream>
#include <string>
#include <vector>

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
        cout<<"Address of new node "<<new_node->address<<endl;
        new_node->address=head;
        cout<<"Address of new node after copy "<<new_node->address<<endl;
        head=new_node;
        cout<<"Address of head "<<head->address<<endl;
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

    Node* middle_of_the_linked_list(Node* &head){
        Node* middle = head; //initializing middle node with head at first
        Node *tail_again = head;
         
        //First I'll calculate number of nodes

        //Accessing the last element
        while(tail_again->address != NULL){
            tail_again = tail_again->address;
   }
        int num_of_nodes = 0;
        Node* node_calculator = head;
        while(node_calculator != NULL){
            node_calculator = node_calculator->address;
            num_of_nodes++;
        }
        
        int mid = num_of_nodes/2;
        
        //If odd number of nodes
        if(num_of_nodes%2 != 0){
            mid = mid + 1; //To get to the middle node
            for(int i = 1 ;i<mid ; i++){
                middle = middle->address;
            }
        }
        else{
            for(int i = 1 ;i<mid + 1 ;i++){
                middle = middle->address;
            }
        }
        // cout<<"\nMiddle node position : "<<mid<<endl;
        // cout<<"Middle node value : "<<middle->data<<endl;
        
        return middle;


    }


};

int main() {
    Node * head = new Node(30);
    Node * tail = head;
    tail->Insert_at_Tail(tail);
    tail->Traverse_Linked_list(head);
    tail->Insert_at_head(head);
    tail->Traverse_Linked_list(head);
    tail->Insert_at_head(head);
    tail->Traverse_Linked_list(head);
    tail->Insert_at_head(head);
    tail->Traverse_Linked_list(head);
    tail->Insert_At_any_position(head,tail);
    //tail->Traverse_Linked_list(head);
  //  tail->Delete_node(head,tail);
    tail->Traverse_Linked_list(head);
    tail->middle_of_the_linked_list(head);
    













    // Node head(10);
    // Node n2(20);
    // head.address=&n2;
    // Node n3(30);
    // n2.address=&n3;
     
    // cout<<head.data<<endl;
    // cout<<head.address->data<<endl;
    // cout<<n2.address->data<<endl;

    
    
    
    
    return 0;
}