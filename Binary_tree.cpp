#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
class node{
    public:
    int data;
    node* left_child;
    node* right_child;

    node(int data){
        this->data = data;
        left_child = NULL;
        right_child = NULL;
    }

};

void level_order_traversal(node* &root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    node* temp = NULL;
    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL); 
            }
            continue;
        }

        cout<<temp->data<<" ";
        if(temp->left_child!=NULL){
            q.push(temp->left_child);
        }
        if(temp->right_child!=NULL){
            q.push(temp->right_child);
        }
    }
}

    bool inorder_traversal_1(node* root_1,node* root_2){
        //LNR
        //Base case -  Rukna kab hai
        if(root_1==NULL || root_2==NULL){
            return true;
        }
        //bool ans;
        if(root_1->data==root_2->data){
           // bool ans = true;
        int left = inorder_traversal_1(root_1->left_child,root_2->left_child);
        int right = inorder_traversal_1(root_1->right_child,root_2->right_child);
        }
        else{
           return false;
           // bool ans = false;
        }
        return true;
        
    }
    
        void inorder_traversal(node* root, int &count_paths,vector<int>* store_paths){
        //LNR
        //Base case -  Rukna kab hai
        if(root==NULL){
            return;
        }

        inorder_traversal(root->left_child,count_paths,store_paths);
        if (root->left_child == NULL && root->right_child == NULL) {
            //Leaf node milgaya hai
            store_paths->push_back(count_paths);
            count_paths = 0;
        }
        else{
            count_paths++;
        }
        inorder_traversal(root->right_child,count_paths,store_paths);
        
    }
int heightOfBinaryTree(node *root)
{
   vector<int> store_paths;
   int count_paths = 0;
   inorder_traversal(root,count_paths,&store_paths); 
   int max = 0;
   for(int i = 0; i<store_paths.size() ; i++){
        if(store_paths[i]>max){
            max = store_paths[i];
        }
   }
   return max+1;
}


    void preorder_traversal(node* root){
        //NLR
        //Base case 
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        preorder_traversal(root->left_child);
        preorder_traversal(root->right_child);

    }

    void postorder_traversal(node* root){
        static int count = 0;
        //LRN
           if(root==NULL){
            return;
        }

        postorder_traversal(root->left_child);
        postorder_traversal(root->right_child);
        cout<<root->data<<" ";
    }
node* build_tree(node* &root){
    int data;
    cout<<"Enter data\n";
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for Left child of "<<root->data<<endl;
    root->left_child = build_tree(root->left_child);
    cout<<"Enter data for Rigth child of "<<root->data<<endl;
    root->right_child = build_tree(root->right_child);
    return root;
}

    int max_length_of_left_side(node* root){
        //Base case -> ruk jao
        if(root==NULL){
            return 0;
        }

        //Recursive call -> Trust your function
        int left = max_length_of_left_side(root->left_child);
        int right = max_length_of_left_side(root->right_child);
        //max++;
        int ans = max(left,right) + 1;
        return ans;
    }
    int max_length_of_right_side(node* root){
        //Base case -> ruk jao
        if(root==NULL){
            return 0;
        }

        //Recursive call -> Trust your function
        int right = max_length_of_right_side(root->right_child);
        int left = max_length_of_right_side(root->left_child);
        //max++;
        int ans = max(left,right) + 1;
        return ans;
    }    

    int sum(node* root){
        //Base case -> Rukna kab hai
        if(root==NULL){
            return 0;
        }

        int left_sum = sum(root->left_child);
        int right_sum = sum(root->right_child);

        int ans = left_sum + right_sum + root->data;

        return ans;
    }



int main() {
    node* root_1 = NULL;
    root_1 = build_tree(root_1);
    cout<<"Sum : "<<sum(root_1->left_child);
    //node* root_2 = NULL;
    //root_2 = build_tree(root_2);
    //if(inorder_traversal_1(root_1,root_2))cout<<"\nans : ";
   // level_order_traversal(root);
    //inorder_traversal(root);
    //preorder_traversal(root);
    //postorder_traversal(root);
   // inorder_traversal(root,count_paths,store_paths);
    //cout<<heightOfBinaryTree(root);
    //cout<<"s: "<<max_length_of_left_side(root);
   // cout<<"Root data : "<<root->data;
    //cout<<"s: "<<max_length_of_right_side(root->right_child);
   // cout<<"\nAnwer : "<<max_length_of_left_side(root)+max_length_of_right_side(root->right_child)-1;
    return 0;
}