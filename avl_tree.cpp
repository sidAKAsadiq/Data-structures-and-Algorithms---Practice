#include <iostream>
#include <string>
#include <queue>
#include<climits>
#include<algorithm>
using namespace std;
class node{
    public:
    int data;
    int bal_fac; //Balance factor
    int height;
    node* left;
    node* right;
    node(){
        data = 0;
        left = right = NULL;
        height = 0;
        bal_fac = 0;
    }
    node(int d){
        data = d;
        left = right = NULL;
        height = 0;
        bal_fac = 0;
    }
};

class avl_tree{
public:
node* root;
bool is_balanced;
avl_tree(){
    root = NULL;
    is_balanced = true;
}
avl_tree(node* n){
    root = n;
    is_balanced = true;
}
int calc_height(node* root){
    if(root == NULL){
        return -1;
    }
    return max(calc_height(root->left),calc_height(root->right))+1;
}
int calc_balanceFactor(node* root){
 return (calc_height(root->left) - calc_height(root->right));
}
void right_rot(node* &root){
    node* t1 = root->left;
    root->left = t1->right;
    t1->right = root;
    root = t1;
}
void left_rot(node* &root){
    node* t1 = root->right;
    root->right = t1->left;
    t1->left = root;
    root = t1;    
}
void left_right_rot(node* &root){
    left_rot(root->left);
    right_rot(root);
}
void right_left_rot(node* &root){
    right_rot(root->right);
    right_left_rot(root);
}
void insert(node* &root,int k){
    if(root == NULL){
        cout<<"here";
        root = new node(k);
        return;
    }
    if(k > root->data){
        insert(root->right,k);
    }
    else{
        insert(root->left,k);
    }
    //updating height of every node
    root->height = calc_height(root);
    //Balancing the tree!
    if(calc_balanceFactor(root) != 2 && calc_balanceFactor(root) != -2){
        return;
    }
    if(calc_balanceFactor(root)>0){
        //+ve balance factor - Left waly cases are psbl

        //Check left left case - right rotation
        if(k < root->left->data){
            //Right rotation
            right_rot(root);
        }
        else{
            //Left right case - Left right rotation
            left_right_rot(root);
        }
    }
    else{
        //-ve bf -> right waly cases
        if(k > root->right->data){
            left_rot(root);
        }
        else{
            right_left_rot(root);
        }
    }
}
    void check_balanced(node* root){
        if(root == NULL){
            return;
        }
        if(calc_balanceFactor(root) >=2 || calc_balanceFactor(root) <= -2){
            is_balanced = false;
            return;
        }
        check_balanced(root->left);
        check_balanced(root->right);
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
    void delete_from_avl(node* &root,int k){
        if(root == NULL){
            return;
        }
        //Agar key right say delete ho rahi hai i.e Left waly cases
        if(k > root->data){
            if(calc_balanceFactor(root->left) == 1){
                cout<<"idahr:";
                right_rot(root);
            }
            else{
                left_right_rot(root);
            }
        }
        //Agar key left say delete ho rahi hai i.e Right waly cases
        else{
            if(calc_balanceFactor(root->right) == -1){
                right_rot(root);
            }
            else{
                right_left_rot(root);
            }
        }
     //   level_order_traversal();
        //Ab delete kardo element ko
        delete_from_bst(root,k);
    }
};

int main() {
    avl_tree a1;
    a1.insert(a1.root,20);
    a1.level_order_traversal();
    a1.root->left = new node(10);
    a1.root->right = new node(30);
    a1.root->right->right = new node(40);
    a1.level_order_traversal();
    a1.delete_from_avl(a1.root,10);
    a1.level_order_traversal();
    



    return 0;
}