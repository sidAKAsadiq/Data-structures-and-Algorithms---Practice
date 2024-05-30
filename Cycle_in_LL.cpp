#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Node{
    public:
    int data;
    Node* address;
    bool is_visited;

    Node(){
        address=NULL;
        is_visited=false;
    };
    Node(int data){
        this->data = data;
        address=NULL;
        is_visited=false;
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





    void    Traverse_Linked_list(Node* &head){
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
    
            void detect_cycle_using_floyd_algorithm(Node* &head){
            Node* slow = head->address; // 1 step at a time
            Node* fast = head->address->address; //2 steps at a time
            while(1){
                    if(fast == slow){
                        cout<<"cycle detected\n";
                        return;
                    }
                    if(fast == NULL || slow == NULL){
                        cout<<"No cycle detected\n";
                        return;
                    }
                slow = slow->address;
                fast = fast->address->address;


            }

        }


        void detect_cycle_using_maps(Node* &head){
        map<Node*,bool> visited ;
        Node* temp = head;
        while (temp != NULL) {
            if(visited[temp] == true){
                cout<<"\nCycle detected\n";
                //To remove cycle
                remove_cycle(temp);
                return;
            }
            visited[temp] = true;
            temp = temp->address;
        }
        cout<<"Cycle NOT detected\n";
    }

    void remove_cycle(Node* &temp){
        temp->address = NULL;        
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
    tail->Traverse_Linked_list(head);
    tail->Delete_node(head,tail);
    tail->Traverse_Linked_list(head);
    cout<<"\n"<<tail->number_of_nodes(head);
    cout<<endl;
    head->is_this_linked_list_circular_or_not(head);
    head->detect_cycle_using_floyd_algorithm(head);
    













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