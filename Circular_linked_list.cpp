#include <iostream>
#include <string>
#include<map>

using namespace std;

class Node { 
    public:
    int data;
    Node* address;
    bool is_visited;
    Node(int data){
        this->data = data;
        address = NULL;
        is_visited = false;
    }
    Node(){
        data = 0;
        is_visited = false;
        address = NULL;
    }

    void insert_at_head(Node* &head , Node* &tail){
        cout<<"Enter valaue to be inserted at head\n";
        int value;
        cin>>value;
        Node* new_node = new Node(value);
        new_node->address = head;
        head = new_node;
        tail->address = head;
    }

    void Traverse_circular_ll(Node* &head , Node* &tail){
       Node* temp = head;
       while(temp != tail ){
        cout<<temp->data<<" ";
        temp = temp->address;
       } 
        cout<<temp->data<<" ";
    }

    void insert_at_tail(Node* &tail){
        cout<<"Enter the value to be inserted at tail\n";
        int value;
        cin>>value;
        Node* new_node = new Node(value);
        new_node->address = tail->address;
        tail->address = new_node;  
        tail = new_node; 
    }

    void insert_at_any_position(Node* &head, Node* &tail){
        cout<<"Enter value to be inserted\n";
        int value;
        cin>>value;
        cout<<"Enter position\n";
        int position;
        cin>>position;
        if(position == 1){
            insert_at_head(head,tail);
            return;
        }
        Node* new_node = new Node(value);
        Node* temp = head;
        
        //To access 1 node before the new node
        for(int i = 1 ; i<position - 1 ;i++){
            temp = temp->address;
        }
        if(temp == tail){
            insert_at_tail(tail);
            return;
        }
        new_node->address = temp->address;
        temp->address = new_node;

    }
    void delete_node(Node* &head){
        int position;
        cout<<"Enter position you want node to be deleted from\n";
        cin>>position;
        Node* acees_deleting = head;
        Node* acess_previous = head;
        //To access the node being deleted
        for(int i = 1; i<position ; i++){
            acees_deleting = acees_deleting->address;
        }
        //To access the node before the one being deleted
        for(int i=1 ; i<position-1 ;i++){
            acess_previous = acess_previous->address;
        }
        acess_previous->address = acees_deleting->address;
        acees_deleting->address = NULL;
        delete acees_deleting;
    }
        void detect_cycle_using_floyd_algorithm(Node* &head){
            Node* slow = head->address; // 1 step at a time
            Node* fast = head->address->address; //2 steps at a time
            while(1){
                    if(fast == slow){
                        cout<<"cycle detected\n";
                        return;
                    }
                    if(fast == NULL){
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
    
  Node* head = new Node (10);
  Node* tail = head;
  cout<<"head : " <<head->data<<" tail : "<<tail->data<<" \n";
  head->insert_at_head(head,tail);
  cout<<"head : " <<head->data<<" tail : "<<tail->data<<" \n";
  head->insert_at_head(head,tail);
  cout<<"head : " <<head->data<<" tail : "<<tail->data<<" \n";
  head->insert_at_tail(tail);
  cout<<"head : " <<head->data<<" tail : "<<tail->data<<" \n";
  head->Traverse_circular_ll(head,tail);
  head->insert_at_any_position(head,tail);
  head->Traverse_circular_ll(head,tail);
  head->delete_node(head);
  head->Traverse_circular_ll(head,tail);
  cout<<endl;
    head->detect_cycle_using_floyd_algorithm(head);
//   head->detect_cycle_using_maps(head);
//   head->detect_cycle_using_maps(head);




     return 0;
}