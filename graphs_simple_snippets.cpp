#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <stack>
#include <queue>
#include <climits>
using namespace std;

class edge{
public:
int id;
int weight;
bool visited;//no faida
edge(int i,int w){
    visited = false;
    id = i;
    weight = w;
}
void print_edge(){
    cout<<id<<" -- "<<weight<<"  ";
}
};
class vertex{
public:
bool visited;//no faida
int id;
string name;
list<edge> edge_list;
vertex(){   
    visited = false;
    id = 0;
    name = "No name";
}
vertex(int i , string s){
    visited = false;
    id = i;
    name = s;
}
void add_edge(edge &obj){
    edge_list.push_back(obj);
}
void print_vertex(){
    cout << id << "->" << name << " " << "[ ";
    for (auto it = edge_list.begin(); it != edge_list.end(); ++it) {
        it->print_edge();
    }
    cout<<" ] ";
    cout << endl;
}


};
class graph{
public:
vector<vertex> vertices;
void add_vertex(vertex &obj){
    vertices.push_back(obj);
}
void print_graph(){
    for(int i = 0; i<vertices.size() ; i++){
        vertices[i].print_vertex();
    }
    cout<<endl;
}
void BFS(){
    vector<string>visited;
  //  vector<string>explored;     //These could be just bool variables in class magar wesy chal nahi raha
    queue<string> q1;
    vertex temp = vertices[0];
    q1.push(temp.name);
    visited.push_back(temp.name);
    while(!q1.empty()){
    string temp_name = q1.front();
    q1.pop();
    cout<<temp_name<<" ";
    int id;
    for(int i=0;i<vertices.size();i++){
        if(vertices[i].name == temp_name){
            id = i;
            break;
        }
    } 
  //  cout<<"ID : "<<id<<endl;   
    for(auto it = vertices[id].edge_list.begin() ; it != vertices[id].edge_list.end() ; ++it){
    bool visited_already = false;
    //cout<<"finidning : "<<it->id<<" "<<endl;
    for(int i=0;i<vertices.size();i++){
        if(vertices[i].id == it->id){
      //      cout<<"here  it->id " <<it->id<<endl;;
            for(int j=0;j<visited.size();j++){
                if(visited[j] == vertices[i].name){
                    visited_already = true;
                    break;
                }
        //    cout<<"her2\n";
            }
            if(!visited_already){
          //      cout<<"oushig : "<<vertices[i].name;
                q1.push(vertices[i].name);
                visited.push_back(vertices[i].name);
                break;
            }    
        }
    }
    }
  //  explored.push_back(temp_name);

    }
}
//Bad appraoch for checking if visited or not
void DFS(){
vector<string> check; 
stack<string> s1;
vertex temp;
temp = vertices[0];
s1.push(temp.name);
while(!s1.empty()){
string temp_name = s1.top();
s1.pop();
cout<<temp_name<<"  ";
int id;
for(int i = 0 ; i<vertices.size() ; i++){
    if(vertices[i].name == temp_name){
        id = i;
        break;
    }
}
for(auto it = vertices[id].edge_list.begin() ; it != vertices[id].edge_list.end() ; ++it){
    bool visited = false;
    if(it->id != temp.id){
        int search_id = it->id;
        for(int i = 0;i<vertices.size();i++){
            if(vertices[i].id == search_id){
                for(int j = 0 ; j<check.size() ; j++){
                    if(vertices[i].name == check[j]){
                        visited = true;
                        break;
                    }
                }
                
                if(!visited){
                s1.push(vertices[i].name);
                check.push_back(vertices[i].name);
                break;
                }
            }
        }
        //it->visited = true;
    }
}

}


}




void add_edge(int src_id , int dest_id , int w){
    //First checking if the edge already exisit or not
    for(int i = 0 ; i<vertices.size() ; i++){
        if(vertices[i].id == src_id){
        for(auto it = vertices[i].edge_list.begin() ; it != vertices[i].edge_list.end() ; ++it){
            if(it->id == dest_id){
                cout<<"Edge already exisits\n";
                return;
            }
        }
        }
    }
    //Insert edge
    for(int i = 0 ; i<vertices.size() ; i++){
        if(vertices[i].id == src_id){
            edge temp(dest_id,w);
            vertices[i].edge_list.push_back(temp);
        }
        if(vertices[i].id == dest_id){
            edge temp(src_id,w);
            vertices[i].edge_list.push_back(temp);
        }        
    }
        cout<<"Edge added successfully\n";
}

void dijktras_algo_stl(){
    int* ans = new int[vertices.size()];
    bool* explored = new bool[vertices.size()];
    for(int i=0;i<vertices.size();i++){
        ans[i] = 10000;
        explored[i] = false;
    }
    int id;
    cout<<"Source : ";
    cin>>id;
    ans[id] = 0;
    explored[id] = true;
    while(1){
        bool all_explored = true;
        for(int i=0;i<vertices.size();i++){
            if(explored[i] == false){   
                all_explored = false;
            }
        }
        if(all_explored){
            break;
        }
        int weight_to_be_added = ans[id];
        for(auto it = vertices[id].edge_list.begin() ; it!=vertices[id].edge_list.end();++it){
            int final_weight;
            final_weight = weight_to_be_added + it->weight;
            if(final_weight <= ans[it->id]){
                ans[it->id] = final_weight;
            }
        }
        cout<<"prinitng ans: \n";    for(int i=0;i<vertices.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
        int min_val = 10000;
        int min_ind;
        for(int i=0;i<vertices.size();i++){
            if(ans[i] < min_val && explored[i] == false ){
                min_val = ans[i];
                min_ind = i;
                cout<<"min val : "<<min_val<<" ";
                cout<<"min ind : "<<min_ind<<" ";
            }
        }
        explored[min_ind] = true;
        id = min_ind;
        cout<<"next idL "<<id<<endl;
    }
    for(int i=0;i<vertices.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

};

int main() {
    graph g1;
    vertex v1(0, "1");
    vertex v2(1, "2");
    vertex v3(2, "3");
    vertex v4(3, "4");
    vertex v5(4, "5");   
    g1.add_vertex(v1);
    g1.add_vertex(v2);
    g1.add_vertex(v3);
    g1.add_vertex(v4);
    g1.add_vertex(v5);  
    g1.print_graph();
    g1.add_edge(0,1,100);
    g1.add_edge(0,2,150);
    g1.add_edge(1,3,150);
    g1.add_edge(1,4,150);
    g1.add_edge(3,4,150); 
    g1.print_graph();
    g1.DFS();
    cout<<endl;
    g1.BFS();
    cout<<endl;
    g1.dijktras_algo_stl();
    return 0;
}