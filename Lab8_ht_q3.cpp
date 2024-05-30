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
    bool is_bst;
    bool is_perfect;
	btree(){
		root = NULL;
		is_full = true;
		is_complete = true;
        is_bst = true;
        is_perfect = true;        
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
    void check_bst(node* root){
        if(root == NULL){
            return;
        }
        if(root->left!=NULL){
            if(root->left->data > root->data)
            is_bst = false;
            return;
        }
        if(root->right!=NULL){
            if(root->right->data < root->data)
            is_bst = false;
            return;
        }        
        check_bst(root->left);
        check_bst(root->right);   
    }
    void check_perfect_bt(node* root){
        node* temp;
        queue<node*> level_order;
        queue<node*> checker;
        level_order.push(root);
        while(!level_order.empty()){
            temp = level_order.front();
            level_order.pop();
            if(temp->left != NULL){
            level_order.push(temp->left);
            }
            if(temp->right != NULL){
            level_order.push(temp->right);
            }     
            //Ab queue may saray eik level waly elements paray howy hain
            if(level_order.size()%2 == 0 && !level_order.empty()){
            while(!level_order.empty()){
                //Copy queue
                checker.push(level_order.front());
                level_order.pop();
            }
            node* t = checker.front();
            if(t->left!=NULL && t->right!=NULL){
                //check all nodes for 2 childs
               level_order.push(t);
               checker.pop(); 
                while(!checker.empty()){
                if(checker.front()->left == NULL || checker.front()->right == NULL){
                    is_perfect = false;
                    return;
                }
                else{
                    level_order.push(checker.front());
                    checker.pop();
                }
                }
            }
            else if(t->left == NULL && t->right == NULL){
                //check all nodes for 0 childs
               level_order.push(t);
               checker.pop(); 
               while(!checker.empty()){
                if(checker.front()->left != NULL || checker.front()->right != NULL){
                    is_perfect = false;
                    return;                    
                }
                else{
                    level_order.push(checker.front());
                    checker.pop();                   
                }
               }                
            }
            else{
                //The tree is not full
                is_perfect = false;
                return;
            }
            }

        }
    }
};

main(){
	btree b1;
	b1.level_order_insert();//enter data of root node
 	b1.root->right = new node(20);	
 	b1.root->left = new node(5);	
 //	b1.root->left->left = new node(4);	 //Commenting out this would make tree full and complete	
 	b1.root->left->right = new node(7);	 	
    b1.root->right->right = new node(25);
    b1.root->right->left = new node(15);
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
    b1.check_bst(b1.root);
    if(b1.is_bst)
    cout<<"Tree is a BST\n";
    else
    cout<<"Tree is not a BST\n";
    b1.check_perfect_bt(b1.root);
    if(b1.is_perfect)
    cout<<"Tree is Perfect\n";
    else
    cout<<"Tree is not perfect\n";


}