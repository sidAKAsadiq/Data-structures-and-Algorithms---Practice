#include <iostream>
#include <string>

using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node()
    {
        data = 0;
        left = right = NULL;
    }
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
    ~node(){
//        left = right = NULL;
        delete left;
        delete right;
    }
};

node* build_tree(node* root){
    cout<<"Enter data for node : "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    //Build Left Sub-Tree
    cout<<"Going left of : "<<data<<endl;
    root->left = build_tree(root->left);
    //Build Right Sub-Tree
    cout<<"Going Right of : "<<data<<endl;
    root->right = build_tree(root->right);
    return root;
}

void traverse(node* root){
    if(root == NULL){
        return;
    }
    cout<<"data : "<<root->data<<endl;
    
    cout<<"Going left "<<endl;
    traverse(root->left);
    cout<<"Going right "<<endl;
    traverse(root->right);
}
int main()
{
    node* root  = NULL;
    root = build_tree(root);
    cout<<"l : "<<root->right->data<<endl;
    traverse(root);
    return 0;
}