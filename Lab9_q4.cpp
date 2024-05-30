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
    node* inorder_pred(node* root){
        //left par kuch hai hi nahi tou left subtree ki max value kahan say laoun
        if(root->left == NULL){
            return NULL;
        }
        if(root->left->right == NULL){
            return root->left;
        }
        node* temp = root->left;
        while(temp->right != NULL){
            temp = temp->right;
        }
        return temp;
    }
    //right subtree ki left most value
    node* inorder_succ(node* root){
        //right par kuch hai hi nahi tou right subtree ki min value kahan say laoun
        if(root->right == NULL){
            return NULL;
        }
        if(root->right->left == NULL){
            return root->right;
        }
        node* temp = root->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }    
        void delete_from_bst(node*& root,int k){
        if(root == NULL){
            return;
        }
        if(k < root->data){
            delete_from_bst(root->left,k);
        }
        else if(k > root->data){
            delete_from_bst(root->right,k);
        }
        else{
            if(inorder_pred(root) == NULL && inorder_succ(root) == NULL){
                root = NULL;
                return;
            }
            else if(inorder_pred(root)!=NULL && inorder_succ(root) == NULL){
                root->data = inorder_pred(root)->data;
                delete_from_bst(root->left,inorder_pred(root)->data);
                return;
            }
            else if(inorder_pred(root)==NULL && inorder_succ(root) != NULL){
                root->data = inorder_succ(root)->data;
                delete_from_bst(root->right,inorder_succ(root)->data);
                return;                
            }
            else{
                root->data = inorder_pred(root)->data;
                delete_from_bst(root->left,inorder_pred(root)->data);
                return;                
            }
        }
    }   
    void checked_balanced(node* &root){
        if(root == NULL){
                return;
                }
        if(calculate_balance_factor(root) == 2 || calculate_balance_factor(root) == -2){
            is_balanced = false;
        }
        checked_balanced(root->left);
        checked_balanced(root->right);

    }
    void inorder(node* &root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    void postorder(node* &root){
        if(root == NULL){
            return;
        }
        cout<<root->data<<" ";
        postorder(root->left);
        postorder(root->right);
    }
void kth_smallest_element(node* &root,int k,int &i){
    if(root == NULL){
        return;
    }
    kth_smallest_element(root->left,k,i);
    i++;
    if(i == k){
        cout<<"kth smallest element : "<<root->data<<endl;
    }
    kth_smallest_element(root->right,k,i);
}
void count_nodes(node* &root, int& c){
    if(root == NULL){
        return;
    }
    count_nodes(root->left,c);
    c++;
    count_nodes(root->right,c);
}
void kth_largest_element(node* &root,int n,int k,int &i){
    if(root == NULL){
        return;
    }
    kth_largest_element(root->left,n,k,i);
    if(n - i == k ){
        cout<<"Kth largest element : "<<root->data<<endl;
    }
    i++;
    kth_largest_element(root->right,n,k,i);
}
};

int main() {
    int arr [7] = {1,2,3,4,5,6,7};
    avl a;
     for(int i=0;i<7;i++){
       a.insert(a.root,arr[i]);
     }
    int  i = 0;
    int nodes = 0;
    a.count_nodes(a.root,nodes);
    a.kth_smallest_element(a.root,2,i);
    i=0;
    a.kth_largest_element(a.root,nodes,1,i);
    cout<<"Height of LST: "<<a.calculate_height(a.root->left);
    cout<<"\nHeight of RST: "<<a.calculate_height(a.root->right);
    return 0;
}