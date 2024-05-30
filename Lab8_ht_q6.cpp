#include <iostream>
#include <string>
#include <queue>
#include <math.h>
#include <climits>
#include <vector>
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
    bool found;
	btree(){
		root = NULL;
		is_full = true;
		is_complete = true;
        is_bst = true;
        is_perfect = true;    
        found = false;    
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

    // void bst_insert(int d){
    //     if(root == NULL){
    //         root = new node(d);
    //         return;
    //     }
    //     if(d > )
    // }


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
    //Left subtree ki right most value
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
        cout<<"Standing at: "<<root->data<<endl;
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
                //cout<<root->data<<"rd";
                //cout<<"here";
               // delete root;
                root = NULL;
                return;
            }
            else if(inorder_pred(root)!=NULL && inorder_succ(root) == NULL){
                cout<<"here 2";
                root->data = inorder_pred(root)->data;
                delete_from_bst(root->left,k);
                return;
            }
            else if(inorder_pred(root)==NULL && inorder_succ(root) != NULL){
                root->data = inorder_succ(root)->data;
                delete_from_bst(root->right,k);
                return;                
            }
            else{
                cout<<"hrer";
                root->data = inorder_pred(root)->data;
                delete_from_bst(root->left,inorder_pred(root)->data);
                return;                
            }
        }

    }   
    void find_ceil_floor_value(node* root,int x){
        if(root == NULL){
            return;
        }
        if(root->data == x){
            found = true;
            return;
        }
        if(x > root->data){
            find_ceil_floor_value(root->right,x);
        }
        else{
            find_ceil_floor_value(root->left,x);
        }
    }
int sum_of_tree(node* &root,int sum){
    if(root == NULL){
        return 0;
    }
    sum = sum + root->data;
    sum =  sum + sum_of_tree(root->left,0);
    sum = sum + sum_of_tree(root->right,0);
    return sum;
}
bool tree_is_bst(node* root){
        if(root == NULL){
            return true;
        }
        if(root->left!=NULL){
            if(root->left->data >= root->data)
                return false;
        }
        if(root->right!=NULL){
            if(root->right->data <= root->data)
          //  cout<<"here: "<<root->data<<endl;
                return false;
        }        
        return true;     
}
int sum_of_max_subtree_that_is_also_a_BST(node* &root){
    static int max = INT_MIN;
    if(root == NULL){
        return 0;
    }
    if(tree_is_bst(root)){
        int sum = sum_of_tree(root,0);
        if(sum > max){
            max = sum;
        } 
        sum = 0;
    }
    sum_of_max_subtree_that_is_also_a_BST(root->left);
    sum_of_max_subtree_that_is_also_a_BST(root->right);
    return max;
}
void create_combinations(vector<int>& v,vector<vector<int>>&comb,int i){
    if(i >= v.size()){
        comb.push_back(v);
        return;
    }
    for(int j = i;j<v.size();j++){
        swap(v[i],v[j]);
      //  i++;
        create_combinations(v,comb,i+1);
        swap(v[i],v[j]);
    }
}
void create_tree(vector<int>& comb){
int i = 0;
while(i < comb.size()){
    //insert_bst()
}

}
void many_trees(vector<vector<int>>&comb){
    int i = 0;
    while(i < comb.size()){
        create_tree(comb[i]);
        i++;
    }
}
};

main(){


	btree b1;
    
    int n;
    cout<<"Enter value of n: ";
    cin>>n;
    vector<int> v; //This will store values from 1-n
    for(int i = 1; i<=n ; i++){
        v.push_back(i);
    }
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }    
    cout<<endl;
    vector<vector<int>> comb; //This will store all possible combinations
    b1.create_combinations(v,comb,0); 
    cout<<endl;   
    for(int i=0;i<comb.size();i++){
        for(int j=0;j<comb[i].size();j++){
            cout<<comb[i][j]<<" ";
        }
        cout<<endl;
    }


    btree arr[1000];




 

}