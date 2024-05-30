#include <iostream>
#include <string>
#include <queue>
using namespace std;

class node{
public:
int data;
node* left;
node* right;
node(){
    left = right = NULL;
}
node(int d){
    data = d;
    left = right = NULL;
}
};

void insert_into_bst(node* &root , int d){
    //Base case
    if(root == NULL){
        root = new node(d);
        return;
    }
    if(d < root->data){
        //left part may chaly jao
        insert_into_bst(root->left , d);
    }
    if(d > root->data){
        //right part may chaly jao
        insert_into_bst(root->right,d);
    }

}

void print_bst(node* &root){
    if(root == NULL){
        return;
    }
    print_bst(root->left);
    cout<<root->data<<" ";
    print_bst(root->right);

}

void kth_smallest(node* &root,int &k){
    static int i = 0;
    if(root == NULL){
        return;
    }
    kth_smallest(root->left,k);
    i++;
    if(i == k){
    cout<<root->data<<" aka "<<k<<"th smallest element\n";
        return;
        }
    kth_smallest(root->right,k);

}

int find_inorder_pred(node* &root){
    node* temp = root->left;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

void delete_from_bst(node* &root,int k){
    if(root == NULL){
        return;
    }
    //Getting to the node being deleted
    if(k < root->data){
        delete_from_bst(root->left,k);
    }
    else if(k > root->data){
        delete_from_bst(root->right,k);
    }
    else{
        //Node being deleted found

        //If it has 0 child, simple delete it
        if(root->left == NULL && root->right == NULL){
            cout<<"here\n";
            root = NULL;
            delete root;
        }
        //1 child
        else if(root->left == NULL || root->right == NULL){
            if(root->left == NULL){
                root->data = root->right->data;
                delete_from_bst(root->right,root->right->data);
            }
            else{
                root->data = root->left->data;
                delete_from_bst(root->left,root->left->data);
            }
        }
        else{
            int inorder_pred = find_inorder_pred(root);
            cout<<inorder_pred<<endl;
            root->data = inorder_pred;
            delete_from_bst(root->left , inorder_pred);
        }
    }
}


void level_order_traversal(node* &root){
queue<node*> q1;
q1.push(root);
while(!q1.empty()){
node* temp = q1.front();
q1.pop();
cout<<temp->data<<" ";
if(temp->left != NULL){
    q1.push(temp->left);
}
if(temp->right != NULL){
    q1.push(temp->right);
}
}
}

void validate_bst(node* &root, bool &is_bst){
if(root == NULL){
    return;
}
if((root->left!= NULL && root->data < root->left->data)|| ( root->right!= NULL && root->data > root->right->data)){
    is_bst = false;
    return;
}
validate_bst(root->left,is_bst);
validate_bst(root->right,is_bst);
}

void LCA(node* &root,int a ,int b){

if(root == NULL){
    return;
}
if((a <= root->data && b >= root->data) || (a >= root->data && b <= root->data)){
    cout<<"LCA = "<<root->data<<endl;
    return;
}
if(a < root->data && b < root->data){
    LCA(root->left , a, b);
}
else{
    LCA(root->right , a, b);
}


}

void tree_in_arr(node* &root,int* &tree,int& count){
    if(root == NULL){
        return;
    }
    tree_in_arr(root->left,tree,count);
    tree[count] = root->data;
    count++;
    tree_in_arr(root->right,tree,count);
}


void preorder(node* &root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}


int main() {
    node* root = NULL;
    insert_into_bst(root,10);
    insert_into_bst(root,8);
    insert_into_bst(root,21);
    insert_into_bst(root,7);
    insert_into_bst(root,27);
    insert_into_bst(root,5);
    insert_into_bst(root,4);
    insert_into_bst(root,3);
    insert_into_bst(root,9); 
    insert_into_bst(root,20);
    level_order_traversal(root);
    cout<<endl;
    print_bst(root);
    cout<<endl;
    delete_from_bst(root,21);
   // root->right->left = new node(25);
    print_bst(root);
    cout<<endl; 
    level_order_traversal(root);
    cout<<endl;
    bool is_bst = true;
    validate_bst(root,is_bst);
    if(is_bst){
        cout<<"BST validated!\n";
    }
    else{
        cout<<"Not a BST\n";
    }
    int k = 4;
    cout<<endl;
    kth_smallest(root,k);
    cout<<endl;
    LCA(root,8,20);
    int size = 9;
    int* tree = new int[size];
    int count = 0;
    cout<<endl;
    tree_in_arr(root,tree,count);
    for(int i=0;i<size;i++){
        cout<<tree[i]<<" ";
    }
    int two_sum = 17;
    int i = 0;
    int j = size-1;
    while(i < j){
       // cout<<"here";
        cout<<tree[i]<<" : i"<<tree[j]<<" : j";
        int sum = tree[i] + tree[j];
        if(sum == two_sum){
            cout<<"Found " <<tree[i]<<","<<tree[j]<<endl;
            break;
        }
        if(sum > two_sum){
            j--;
            continue;
        }   
        if(sum < two_sum){
            i++;
            continue;
        }

    }



    preorder(root);



    return 0;   
}