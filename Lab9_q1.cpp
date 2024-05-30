#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    int height;
    int balance_factor;
    node(){
        data = 0;
        left = right = NULL;
        height = 0;
        balance_factor = 0;
    }
    node(int d){
        data = d;
        left = right = NULL;
        height = 0 ;
        balance_factor = 0;
    }
    ~node(){
        left = right = NULL;
        delete left;
        delete right;
    }
};

class avl{
    public:
    node* root;
    bool is_balanced;
    avl(){
        root = NULL;
        is_balanced = true;
    }
    int calculate_height(node* &root){
        if(root == NULL){
            return -1;
        }
        return max(calculate_height(root->left),calculate_height(root->right)) + 1;
    }
    int calculate_balance_factor(node* root){
        return (calculate_height(root->left) - calculate_height(root->right));
    }
    void left_rotation(node* &root){
        node* t = root->right;
        root->right = t->left;
        t->left = root;
        root = t;
    }
    void right_rotation(node* &root){
        node* t = root->left;
        root->left = t->right;
        t->right = root;
        root = t;

    }
    void left_right_rotation(node* &root){
        left_rotation(root->left);
        right_rotation(root);
    }
    void right_left_rotation(node* &root){
        right_rotation(root->right);
        left_rotation(root);
    }
    void insert(node* &root, int k){
        if(root == NULL){
            root = new node(k);
            return;
        }
        if(k < root->data){
            insert(root->left,k);
        }
        else{
            insert(root->right,k);
        }
        //Re calculate the height after each insertion
        root->height = calculate_height(root);
        //Balance the tree!
        if(calculate_balance_factor(root) !=2 && calculate_balance_factor(root) != -2){
            return;
        }
        //If balance factor is +ve then Left waly cases are psbl i.e LL and LR case
        if(calculate_balance_factor(root) > 0 ){
            //check for LL case -> Right rotation
            if(k < root->left->data){
                right_rotation(root);
            }
            //LR case
            else{
                left_right_rotation(root);
            }
        }
        else{
            //check for RR case -> Left rotation
            if(k > root->right->data){
                left_rotation(root);
            }    
            //RL case   
            else{
                right_left_rotation(root);
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
    void level_order_traversal(){
        if(root==NULL)return;
        queue<node*> q;
        q.push(root);
        //int i = 0;
        while(!q.empty()){
            node* temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(root->right);
            }
           // i++;
        }
        cout<<endl;
    }
};


int main() {
    int arr [7] = {1,2,3,4,5,6,7};
    avl a;
     for(int i=0;i<7;i++){
       a.insert(a.root,arr[i]);
       cout<<"preorder traversal : ";
       a.preorder(a.root);
       cout<<endl;
     }
    a.level_order_traversal();
    return 0;
}