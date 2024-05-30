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
	}
}
void traverse(){
	Node* temp = new Node;
	temp = head;
	while(temp!=NULL){
		cout<<"Name : "<<temp->name<<" Artist : "<<temp->artist<<endl;
		temp = temp->next;
	}
}
};
main(){
	cout<<"Sup";
}














