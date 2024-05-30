#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <climits>
using namespace std;

class kruskal_implementation{
public:
int src_id;
int dest_id;
int weight;
kruskal_implementation(){}
kruskal_implementation(int si,int di,int w){
    src_id = si;
    dest_id = di;
    weight = w;
}
};

class edge_node{
public:
int id;
int weight;
edge_node* next;
edge_node(){
    id = -1;
    weight = -1;
    next = NULL;
}
edge_node(int i,int w){
    id = i;
    weight = w;
    next = NULL;
}
};
class special_linked_list{
public:
edge_node* head;
special_linked_list(){
    head = NULL;
}
special_linked_list(edge_node* n){
    head = n;
}
void add(int id,int weight){
    if(head == NULL){
        //no nodes exsist in LL
        head = new edge_node;
        head->id = id;
        head->weight = weight;
        head->next = NULL;
        return;
    }
    edge_node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    edge_node* new_node = new edge_node(id,weight);
    temp->next = new_node;
    new_node->next = NULL;
}
void print(){
    if(head == NULL){
        return;
    }
    edge_node* temp = head;
    //cout<<temp->id<<","<<temp->weight<<" ";
    while(temp != NULL){
        cout<<temp->id<<","<<temp->weight<<" ";
        temp = temp->next;
    }
}
bool search(int id){
    edge_node* temp = head;
    while(temp->id != id && temp != NULL){
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"Not found\n";
        return false;
    }
    cout<<"Found\n";
    return true;
}
void delete_all_nodes(){
    head = NULL;
}
void push_ids_in_stack_for_DFS(stack<int> &s1,int* &visited,int &count){
    if(head == NULL){
        return;
    }
    edge_node* temp = head;
    while(temp != NULL){
        bool is_visited = false;
        for(int i=0;i<=count;i++){
            if(visited[i] == temp->id){
                is_visited = true;
            }
        }
        if(!is_visited){
            s1.push(temp->id);
            count++;
            visited[count] = temp->id;
         }
        temp = temp->next;
    }    
}
void push_in_queue_for_BFS(queue<int> &q1,int* &visited,int &count){
    if(head == NULL){
        return;
    }
    edge_node* temp = head;
    while(temp != NULL){
        bool is_visited = false;
        for(int i=0;i<=count;i++){
            if(visited[i] == temp->id){
                is_visited = true;
            }
        }
        if(!is_visited){
            q1.push(temp->id);
            count++;
            visited[count] = temp->id;
         }
        temp = temp->next;
    }      
}
void push_weights_to_ans(int weight_to_be_added,int* &ans){
    int final_weight;
    edge_node* temp = head;
    while(temp != NULL){
        int id = temp->id;
        final_weight = weight_to_be_added + temp->weight;
        if(ans[id] >= final_weight){
            ans[id] = final_weight;
        }
        temp = temp->next;
    }
    cout<<"Ans array updated\n";
} 
bool push_to_stack_detect_cycle(stack<int> &s1,int* &visited, int &visited_counter){
    int count_visited_nodes = 0;
    if(head == NULL){
        return false;
    }
    edge_node* temp = head;
    while(temp != NULL){
        bool is_visited = false;
        //count_visited_nodes = 0;
        for(int i=0;i<=visited_counter;i++){
            if(visited[i] == temp->id){
                is_visited = true;
                count_visited_nodes++;
                if(count_visited_nodes > 1){
                cout<<"Nodes in visted : "<<count_visited_nodes<<" temp id : "<<temp->id<<endl;
                return true; //cycle exisits
                }
            }
        }   
        if(!is_visited){
            s1.push(temp->id);
            visited_counter++;
            visited[visited_counter] = temp->id;
            }
            temp = temp->next;
    } 
    return false;
}
void update_current_weights_prims(int* &current_weights){
    edge_node* temp = head;
    if(head == NULL){
        return;
    }
    while(temp != NULL){
        if(temp->weight <= current_weights[temp->id]){
            current_weights[temp->id] = temp->weight;
        }
        temp = temp->next;
    }
}
void update_current_weights_and_parents_prims(int index,int* &current_weights,int* parents){
    edge_node* temp = head;
    if(head == NULL){
        return;
    }
    while(temp != NULL){
        if(temp->weight <= current_weights[temp->id]){
            current_weights[temp->id] = temp->weight;
            parents[temp->id] = index;
        }
        temp = temp->next;
    }
}
void add_to_kruskal_arr(int src_id,kruskal_implementation* &array,int &count_arr){
edge_node* temp = head;
if(head == NULL){
    return;
}
while (temp!=NULL){
    bool found = false;
    int dest_id = temp->id;
    int weight = temp->weight;
    for(int j=0;j<count_arr;j++){
        if((array[j].src_id == src_id && array[j].dest_id == dest_id)||(array[j].src_id == dest_id && array[j].dest_id == src_id)){
            found = true;
        }
    }
    if(!found){ 
        array[count_arr].src_id = src_id;
        array[count_arr].dest_id = dest_id;
        array[count_arr].weight = weight;
        count_arr++;
    }
    temp = temp->next;
}

}
};




class vertex{
public:
int id;
string name;
special_linked_list edge_list;
vertex(){}
vertex(int i,string n){
    id = i;
    name = n;
}
vertex(int i){
    id = i;
    name = "NN"; //NN = no name
}
void add_edge(int id,int weight){
    edge_list.add(id,weight);
}
void print_vertex(){
    cout<<id<<" "<<name<<"  [";
    edge_list.print();cout<<"]";
}
};
class graph{
public:
vertex* vertices;
int size;
int count;
graph(){
    size = 0;
    count = 0;
}
graph(int s){
    size = s;
    count = 0;
    vertices = new vertex[size];
}
void add_vertex(vertex v1){
    vertices[count] = v1;
    count++;
}
void add_edge(vertex src, vertex dest, int weight){
    //1. Locating source in my array
    int index;
    for(int i=0;i<count;i++){
        if(vertices[i].id == src.id){
            index = i;
            break;
        }
    }
    vertices[index].add_edge(dest.id , weight);
    //2. Locating dest
    for(int i=0;i<count;i++){
        if(vertices[i].id == dest.id){
            index = i;
            break;
        }
    }    
    vertices[index].add_edge(src.id , weight);   
}
void print_graph(){
    for(int i=0;i<count;i++){
        vertices[i].print_vertex();
        cout<<endl;
    }
}
void DFS(){
    int* visited = new int[count];
    int visited_index = 0;
    stack<int> s1;
    s1.push(vertices[0].id);
    visited[visited_index] = vertices[0].id;
    while(!s1.empty()){
        int temp = s1.top();
        cout<<temp<<" ";
        s1.pop();
        //Finding index in graph
        int ind;
        for(int i=0;i<count;i++){
            if(vertices[i].id == temp){
                ind = i;
                break;
            }
        }
        vertices[ind].edge_list.push_ids_in_stack_for_DFS(s1,visited,visited_index);
    }
}
void BFS(){
    int* visited = new int[count];
    int visited_index = 0;
    queue<int> q1;
    visited[visited_index] = vertices[0].id;
    q1.push(vertices[0].id);
    while (!q1.empty()){
        int temp_id = q1.front();
        q1.pop();
        cout<<temp_id<<" ";
        //Finding index
        int ind;
        for(int i=0;i<count;i++){
            if(vertices[i].id == temp_id){
                ind = i;
                break;
            }
        }
        vertices[ind].edge_list.push_in_queue_for_BFS(q1,visited,visited_index);
    }  
}   
void dijktras_algo(){
    int* ans = new int[size];
    bool* explored = new bool[size];
    for(int i=0;i<size;i++){
        ans[i] = INT_MAX;
        explored[i] = false;        
    }
    int id;
    cout<<"Src?"<<endl;
    cin>>id;
    ans[id] = 0;
    explored[id] = true;
    int weight_to_be_added = ans[id];
    vertices[id].edge_list.push_weights_to_ans(weight_to_be_added,ans);
    while(1){
        bool check_if_all_explored = true;
        for(int i = 0;i<size;i++){
            if(explored[i] == false){
                check_if_all_explored = false;
            }
        }
        if(check_if_all_explored){
            //We have explored all of the nodes/vertices
            break;
        }
        int min_value = INT_MAX;
        for(int i=0;i<size;i++){
            if(ans[i] < min_value && explored[i] == false){
                id = i;
                min_value = ans[i];
            }
        }
       explored[id] = true;
       weight_to_be_added = ans[id];
       vertices[id].edge_list.push_weights_to_ans(weight_to_be_added,ans);
    }

    for(int i=0;i<size;i++){
        cout<<ans[i]<<" ";
    }
}
void detect_cycle(){
    int* visited = new int[size];
    int visited_counter = 0;
    stack<int> s1;
    int id = 0; //Initial starting point
    s1.push(vertices[id].id);
    visited[visited_counter] = vertices[id].id;
    while (!s1.empty()){
        int temp = s1.top();
        s1.pop();
        if(vertices[temp].edge_list.push_to_stack_detect_cycle(s1,visited,visited_counter)){
            cout<<"Cycle found\n";
            return;
        }
    }
    cout<<"No cycle found\n";   
}
void prims_algo(){
    int ans = 0;
    bool* added_to_mst = new bool[size];
    int* current_weight = new int[size];
    for(int i=0;i<size;i++){
        added_to_mst[i] = false;
        current_weight[i] = INT_MAX;
    }
    int index;
    index = 0;
    added_to_mst[index] = true;
    current_weight[index] = 0;
    ans = ans + current_weight[index];
    while(1){
        bool all_vertex_added_to_mst = true;
        for(int i=0;i<size;i++){
            if(added_to_mst[i] == false){
                all_vertex_added_to_mst = false;
                break;
            }
        }
        if(all_vertex_added_to_mst){
            break;  
        }
        vertices[index].edge_list.update_current_weights_prims(current_weight);
        int min_val = INT_MAX;  
        for(int i=0;i<size;i++){
            if(current_weight[i] <= min_val && added_to_mst[i] == false){
                index = i;
                min_val = current_weight[i];
            }
        }
    added_to_mst[index] = true;
    ans = ans + current_weight[index];        
    }
    cout<<"MST by Prims algo : "<<ans<<endl;
}
void prims_algo_forms_mst_graph(){
    graph mst(size);
    mst.count = count;
    for(int i=0;i<size;i++){
        mst.vertices[i] = vertices[i];
        mst.vertices[i].edge_list.delete_all_nodes();
    }
    //mst.print_graph();
    int ans = 0;
    bool* added_to_mst = new bool[size];
    int* current_weight = new int[size];
    int* parents = new int[size];
    for(int i=0;i<size;i++){
        added_to_mst[i] = false;
        current_weight[i] = INT_MAX;
    }
    int index;
    index = 0;
    added_to_mst[index] = true;
    current_weight[index] = 0;
    ans = ans + current_weight[index];
    while(1){
        bool all_vertex_added_to_mst = true;
        for(int i=0;i<size;i++){
            if(added_to_mst[i] == false){
                all_vertex_added_to_mst = false;
                break;
            }
        }
        if(all_vertex_added_to_mst){
            break;  
        }
        vertices[index].edge_list.update_current_weights_and_parents_prims(index,current_weight,parents);
        int min_val = INT_MAX;  
        for(int i=0;i<size;i++){
            if(current_weight[i] <= min_val && added_to_mst[i] == false){
                index = i;
                min_val = current_weight[i];
            }
        }
    added_to_mst[index] = true;
    cout<<"Adding : "<<current_weight[index]<<endl;
    ans = ans + current_weight[index];     
    //adding edge
    int temp_src_id = parents[index];
    int temp_dest_id = index; 
    int temp_weight = current_weight[index];
    mst.add_edge(temp_src_id,temp_dest_id,temp_weight);  
    }
    cout<<endl;
    mst.print_graph();
    cout<<"MST by Prims algo : "<<ans<<endl;
}
void kruskal_algo(){
int n = 100;
kruskal_implementation* array = new kruskal_implementation[n]; //any large size cuz we dont know exact number of edges, maybe we can find someday later
int count_arr = 0;
for(int i=0;i<size;i++){
int src_id = vertices[i].id;
vertices[i].edge_list.add_to_kruskal_arr(src_id,array,count_arr);
}
for(int i=0;i<count_arr;i++){
    cout<<array[i].weight<<" "<<array[i].src_id<<" "<<array[i].dest_id<<endl;
}
//sorting this array
for(int i=0;i<count_arr;i++){
    for(int j=0;j<count_arr;j++){
        if(array[i].weight <= array[j].weight){
            kruskal_implementation temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
}
cout<<"Sorted : \n";
for(int i=0;i<count_arr;i++){
    cout<<array[i].weight<<" "<<array[i].src_id<<" "<<array[i].dest_id<<endl;
}
int* added = new int[size];
int added_count = 0;
int ans = 0;
//Caclulating MST
for (int i=0;i<count_arr;i++){
int weight = array[i].weight;
int src = array[i].src_id;
int dest = array[i].dest_id;
bool src_found = false;
bool dest_found = false;
    for(int j=0;j<added_count;j++){
        if(added[j] == src){
            src_found = true;
        }
        if(added[j] == dest){
            dest_found = true;
        }
    }
if(src_found && dest_found){
    continue;
}
if(!src_found){
    added[added_count] = src;
    added_count++;
}
if(!dest_found){
    added[added_count] = dest;
    added_count++;
}
cout<<"Adding : "<<weight<<endl;
ans = ans + weight;
}
cout<<"MST by kruskal : "<<ans<<endl;
}
};

int main() {
graph g1(8);
vertex v0(0);
vertex v1(1);
vertex v2(2);
vertex v3(3);
vertex v4(4);
vertex v5(5);
vertex v6(6);
vertex v7(7);
g1.add_vertex(v0);
g1.add_vertex(v1);
g1.add_vertex(v2);
g1.add_vertex(v3);
g1.add_vertex(v4);
g1.add_vertex(v5);
g1.add_vertex(v6);
g1.add_vertex(v7);
g1.add_edge(v0,v1,12);
g1.add_edge(v0,v5,4);
g1.add_edge(v1,v4,7);
g1.add_edge(v1,v3,5);
g1.add_edge(v1,v2,20);
g1.add_edge(v2,v7,19);
g1.add_edge(v3,v4,2);
g1.add_edge(v3,v7,18);
g1.add_edge(v4,v5,10);
g1.add_edge(v4,v7,15);
g1.add_edge(v5,v6,8);
g1.add_edge(v6,v7,13);
g1.print_graph();
cout<<"\nNEW MST:\n";
g1.prims_algo_forms_mst_graph(); //MST graph bhi ban raha wow!!
cout<<endl;
g1.kruskal_algo(); //Eik edge kum count kar raha hai :-(



//     graph g(5);
//     vertex v1(0,"0th vertex");
//     vertex v2(1,"1th vertex");
//     vertex v3(2,"2th vertex");
//     vertex v4(3,"3th vertex");
//     vertex v5(4,"4th vertex");
//     g.add_vertex(v1);
//     g.add_vertex(v2);
//     g.add_vertex(v3);
//     g.add_vertex(v4);
//     g.add_vertex(v5);
//     g.add_edge(v1,v2,100);
//     g.add_edge(v1,v3,150);
//     g.add_edge(v2,v4,150);
//     g.add_edge(v2,v5,150);
//     g.add_edge(v4,v5,150);
//   //  g.add_edge(v2,v5,250);
//    // g.add_edge(v2,v4,120);
//    // g.add_edge(v2,v3,130);
//    // g.add_edge(v3,v4,255);
//   //  g.add_edge(v4,v5,105);
//     g.print_graph();
//     cout<<"DFS : ";
//     g.DFS();
//     cout<<endl;
//     cout<<"BFS : ";
//     g.BFS();
//     cout<<endl;
//     g.dijktras_algo();
//     g.detect_cycle();   //For an undirected graph, cycle exisit when a node have more than 1 adjacent nodes that have previously been visited, in other words, in an Acyclic undirected graph, each node can have at max 1 adjacent node that has been visited (it's parent )
//     return 0;

}