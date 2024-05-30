#include <iostream>
#include <string>
using namespace std;
class Node{
    public:
	string name;
	string artist;
	Node* prev;
	Node* next;
	Node(){
		prev = next = NULL;
	}
	Node(string s1,string s2){
		name = s1;
		artist = s2;
		prev = next = NULL;}
	~Node(){
		delete prev;
		prev = NULL;
		delete next;
		next = NULL;
	}
};

class dcl{
    public:
Node* head;
dcl(Node* n){
	head = n;
}
dcl(){
	head = NULL;
}
void append_at_head(string s1,string s2){
	if(head == NULL){
		//We are appending the first node
		head = new Node(s1,s2);
		head->next  = head->prev = head;
		return;
	}
	//cout<<"here\n";
	Node* new_node = new Node(s1,s2);
	Node* tail = head;
	while(tail->next != head){
	//	cout<<"hererer";
		tail = tail->next;
	}
	new_node->next = head;
	head->prev = new_node;
	head = new_node;
	tail->next = head;
	head->prev = tail;
}
void traverse(){
	Node* temp = new Node;
	temp = head;
		cout<<"Name : "<<temp->name<<" Artist : "<<temp->artist<<endl;
		temp = temp->next;
	while(temp!=head){
		cout<<"Name : "<<temp->name<<" Artist : "<<temp->artist<<endl;
		temp = temp->next;
	}
}
void delete_func(string name,string artist, int pos){
	if(pos<1 || pos > length()){
		cout<<"Out of range\n";
		return;
	}
	if(pos == 1){
		//Deleting head
		if(head->name == name && head->artist == artist){
		
		Node* tail = head;
		while(tail->next != head){
			tail = tail->next;
		}
		tail->next = head->next;
		head->next->prev = tail;
		Node* del = head;
		head = head->next;
		del = NULL;
		delete del;
	}
	else{
		cout<<"Wrong call\n";
	}
		return;
	}
	Node* t = head;
	int c = 1 ;
	while(c!=pos){
		t  = t->next;
		c++;
	}
	cout<<"t name : "<<t->name<<" t art : "<<t->artist<<endl;
	if(t->name == name && t->artist == artist){
		//Delete
		t->prev->next = t->next;
		t->next->prev = t->prev;
		t = NULL;
		delete t;
	}
	else{
		cout<<"Wrong call , either wrong pos or wrong info\n";
	}
}
int length(){
	Node*  temp = head;
	int count = 0;
	temp = temp->next;
	count++;
	while(temp!=head){
	temp = temp->next;
	count++;
	}
	return count;
}
};
main(){
	dcl dc1;
	dc1.append_at_head("sid","a");
	dc1.append_at_head("sid","b");
	dc1.append_at_head("dsa","c");
	dc1.append_at_head("dsa","d");
	dc1.traverse();
	cout<<dc1.length();
	dc1.delete_func("dsa","d",1);
	dc1.traverse();
}














