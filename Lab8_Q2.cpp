#include <iostream>
#include <string>
#include <queue>
#include <math.h>
using namespace std;
class node{
	public:
		int data;
		node* left;
		node* right;
	node(){
		data = 0;
		left = right = NULL;
	}
	node(int d){
		data = d;
		left = right = NULL;
	}
	~node(){
		delete left;
		delete right;
	}
};
class btree{
	public:
	node* root;
	bool is_full;
	bool is_complete;
	btree(){
		root = NULL;
		is_full = true;
		is_complete = true;
	}
	void level_order_insert(){
	int d;
	cout<<"Enter Data : ";
	cin>>d;
	if(root == NULL){
		root = new node(d);	
		return;
	}
	queue<node*> que;
	que.push(root);
	while(!que.empty()){
		node* t = new node;
		t = que.front();
		que.pop();
		if(t->left != NULL){
			que.push(t->left);
		}
		else{
			t->left = new node(d);
			return;
		}
		if(t->right != NULL){
			que.push(t->right);
		}
		else{
			t->right = new node(d);
			return;
		}
	}
	}
	void level_order_traversal(){
		cout<<"Level wise printing: \n";
	queue<node*> que;
	que.push(root);
	while(!que.empty()){
		node* t = new node;
		t = que.front();
		que.pop();
		cout<<t->data<<" ";
		if(t->left != NULL){
			que.push(t->left);
		}
		if(t->right != NULL){
			que.push(t->right);
		}
	}
	}	
	void preorder(node* root){
		if(root == NULL){
			return;
		}
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
	void check_complete_tree(node* root){
		if(root == NULL){
			return;
		}
		if(root->left == NULL && root->right != NULL){
			is_complete = false;
			return;
		}
		
		check_complete_tree(root->left);
		check_complete_tree(root->right);
	}
	void delete_nodes_to_make_complete_bt(node* root){
		if(root == NULL){
			return;
		}
		if(root->left == NULL && root->right != NULL){
			root->right = NULL;
			return;
		}
		delete_nodes_to_make_complete_bt(root->left);
		delete_nodes_to_make_complete_bt(root->right);
	}
	void delete_nodes_to_make_full_bt(node* root){
			if(root == NULL){
			return;
		}
		if(root->left == NULL && root->right != NULL){
			root->right = NULL;
			return;
		}		
		if(root->left != NULL && root->right == NULL){
			root->left = NULL;
			return;
		}
		delete_nodes_to_make_full_bt(root->left);
		delete_nodes_to_make_full_bt(root->right);		
	}
	void check_full_tree(node* root){
		if(root == NULL){
			return;
		}
		if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL) ){
			is_full = false;
			return;
		}
		check_full_tree(root->left);
		check_full_tree(root->right);
	}
};

main(){
	btree b1;
	b1.level_order_insert();
 	b1.root->right = new node(2);	
 	b1.root->left = new node(3);	
 	//b1.root->left->left = new node(4);	 //Commenting out this would make tree full and complete, better to keep it this way so that we can see that the transformation of tree into a full and complete one is being done correctly 	
 	b1.root->left->right = new node(5);	 	
	b1.level_order_traversal();
	cout<<endl;
	b1.check_complete_tree(b1.root);
	if(b1.is_complete)
	cout<<"Tree is complete\n";
	else
	cout<<"Tree is INcomplete\n";
	b1.check_full_tree(b1.root);
	if(b1.is_full)
	cout<<"Tree is Full\n";
	else
	cout<<"Tree is not full\n";

	cout<<"\nAfter transformation: \n\n";
	//This part of the code will make the tree complete and full , if not already
	b1.is_complete = true;
	b1.delete_nodes_to_make_complete_bt(b1.root);
	b1.check_complete_tree(b1.root);
	if(b1.is_complete)
	cout<<"Tree is complete\n";
	else
	cout<<"Tree is INcomplete\n";	
	b1.is_full = true;
	b1.delete_nodes_to_make_full_bt(b1.root);
	b1.check_full_tree(b1.root);
	if(b1.is_full)
	cout<<"Tree is Full\n";
	else
	cout<<"Tree is not full\n";	
}