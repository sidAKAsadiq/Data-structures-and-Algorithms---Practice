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

void inorder_to_bst(node* &root3,int s,int e,int* &merged){
    if(s > e){
        return;
    }
    int mid = (s+e)/2;
    root3 = new node(merged[mid]);
    inorder_to_bst(root3->left,s,mid-1,merged);
    inorder_to_bst(root3->right,mid+1,e,merged);
}

void count_nodes(node* &root,int &nodes){
    if(root == NULL){
        return;
    }
    nodes++;
    count_nodes(root->left,nodes);
    count_nodes(root->right,nodes);
}

void find_largest_bst(node* &root, int &largest_bst){
    if(root == NULL){
        return;
    }
    bool is_bst = true;
    validate_bst(root,is_bst);
    if(is_bst){
        int number_of_nodes = 0;
        count_nodes(root,number_of_nodes);
        if(number_of_nodes > largest_bst){
            largest_bst = number_of_nodes;
        }
    }
    find_largest_bst(root->left , largest_bst);
    find_largest_bst(root->right , largest_bst);
}

int main() {
    // int* in1 = new int[4];
    // in1[0] = 10;
    // in1[1] = 20;
    // in1[2] = 30;
    // in1[3] = 40;
    // int* in2 = new int[4];
    // in2[0] = 5;
    // in2[1] = 15;
    // in2[2] = 25;
    // in2[3] = 35;
    // int* merged = new int[8];
    // int i = 0; //for in1
    // int j = 0; //for in2
    // int k = 0; //for merged

    // while(i<4 && j<4){
    //     if(in1[i] < in2[j]){
    //         merged[k] = in1[i];
    //         i++;
    //         k++;
    //     }
    //     else{
    //         merged[k] = in2[j];
    //         j++;
    //         k++;         
    //     }
    // }

    // while(i<4){
    //         merged[k] = in1[i];
    //         i++;
    //         k++;        
    // }
    // while(j < 4){
    //         merged[k] = in2[j];
    //         j++;
    //         k++;   
    // }


    // for(int i=0;i<8;i++){
    //     cout<<merged[i]<<" ";
    // }
    // cout<<endl;

    // int s = 0;
    // int e = 8-1;
    // node* root3 = NULL;
    // inorder_to_bst(root3,s,e,merged);
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->left->right = new node(7);
    root->right = new node(3);
    root->right->right = new node(6);
    root->right->left = new node(2);
    int largest_bst = 0;
    find_largest_bst(root,largest_bst);
    cout<<"Largest BST : "<<largest_bst<<endl;
    print_bst(root);
    return 0;   
}