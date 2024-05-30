#include <iostream>
#include <string>
using namespace std;
class node{
	public:
	int data;
	node* next;
	node(){
		data = 0;
		next = NULL;
	}
	node(int d){
		data = d;
		next = NULL;
	}
	~node(){
		next = NULL;
		delete next;
	}
};
class sll{
	public:
	node* head;
	sll(){
		head = NULL;
	}
	sll(node* n){
		head = n;
	}
	sll(int d){
		head = new node;
		head->data = d;
		head->next = NULL;
	}
	void append(int d){
		if(head == NULL){
			head = new node;
			head->data = d;
			head->next = NULL;
			return;
		}
		//at end
		node* tail = head;
		while(tail->next != NULL){
			tail = tail->next;
		}
		node* new_node = new node(d);
		tail->next = new_node;	
	}
	void traverse(){
		node* temp = head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
	void reverse(){
		node* prev = NULL;
		node* curr = head;
		node* ahead = head->next;
		int i=0;
		while(curr != NULL){
			curr->next = prev;
			prev = curr;
			curr = ahead;
			if(ahead!=NULL){
				ahead = ahead->next;
			}
			i++;
			cout<<"iter : "<<i<<endl;	
	}
	head = prev;
	cout<<"here";
	traverse();
}
};
node* find_mid(node*head){
	node* slow = head;
	node* fast = head->next;
	while(fast!=NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
node* merge(node* left, node* right){
	//merge 2 sorted LL
	node* dummy = new node;
	node* temp = dummy;
	while(left!=NULL && right!=NULL){
		if(left->data < right->data){
			temp->next = left;
			temp = temp->next;
			left = left->next;
		}
		else{
			temp->next = right;
			temp = temp->next;
			right = right->next;
	}
	}
	while(left!=NULL){
			temp->next = left;
			temp = temp->next;
			left = left->next;		
	}
	while(right!=NULL){
			temp->next = right;
			temp = temp->next;
			right = right->next;		
	}
	return dummy->next;
}
node* merge_sort(node* head){
	//Base case -> either list is empty or has single element
	if(head == NULL || head->next == NULL){
		return head;
	}
	node* mid = find_mid(head);
	node* left_head = head;
	node* right_head = mid->next;
	mid->next = NULL;
	
	//left
	left_head = merge_sort(left_head);
	//Right
	right_head = merge_sort(right_head);
	//Merge 2 LL
	node* new_head = merge(left_head , right_head);
	return new_head;
}
node* reverse_in_k(node* head,int k){
	//Base case
	if(head == NULL){
		return NULL;
	}
	//1 case solve kardo - reverse k nodes
		node* prev = NULL;
		node* curr = head;
		node* ahead = NULL;
		int i=0;
		while(curr != NULL && k > i){
			ahead = curr->next;
			curr->next = prev;
			prev = curr;
			curr = ahead;
			i++;	
	}
//Recursive calls
if(ahead!=NULL){
	head->next = reverse_in_k(ahead,k);
}
return prev;
	
	
	
}
main(){
	sll s1(5);
	s1.append(4);
	s1.append(3);
	s1.append(2);
	s1.append(1);
	s1.append(0);
	s1.traverse();
	node* new_head = reverse_in_k(s1.head,2);
	s1.head = new_head;
	s1.traverse();
}












