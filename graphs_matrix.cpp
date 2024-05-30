#include <iostream>
#include <string>
#include <climits>
#include <stack>
using namespace std;



void make_edge(int src, int dest, int** &graph){
    graph[src][dest] = 1;
    graph[dest][src] = 1;
}

int find_best_node(int** &graph , int n){
int least_count_index;
int least_count = INT_MAX;
bool* reachable_nodes = new bool[n];
for(int i=0;i<n;i++){
    reachable_nodes[i] = false;
}

for(int i=0;i<n;i++){
    for(int s=0;s<n;s++){
    reachable_nodes[s] = false;
}
    int* visited = new int[n];
    cout<<"LCI" << least_count_index<<" \n";
    stack<int> s1;
    int visited_count = 0;
    int src = i;
//visited[visited_count] = i;
//visited_count++;
reachable_nodes[src] = true;
int count = 0;
bool all_reachable = false;

while(!all_reachable){
    cout<<"Reachable for : "<<src<<endl;
       for(int s=0;s<n;s++){
       cout<<reachable_nodes[s]<<" "; 
}

cout<<endl;
//if(visited_count > n)exit(1);
//cout<<"Visted count : "<<visited_count<<endl;
    visited[visited_count] = src;
    visited_count++;
    //cout<<"PRinting visited array: ";
    for(int l=0;l<visited_count;l++){
        cout<<visited[l]<<" ";
    }
    cout<<endl;
    all_reachable = true;
    for(int j=0;j<n;j++){
        if(reachable_nodes[j] == false){
            all_reachable = false;
            break;
        }
    }
    if(all_reachable){
          cout<<"COUNT : "<<count<<" "<<i<<endl;
        if(count <= least_count){
            cout<<"Setting: \n";
            least_count = count;
            least_count_index = i;
        }
        break;
    }
    //marking directly connected nodes as reachable
   bool reachable_nodes_may_kuch_dala_hai = false;
    for(int k=0;k<n;k++){
        if(graph[src][k] == 1){
            //reachable node milgai
            if(reachable_nodes[k] == false){
            reachable_nodes[k] = true;
            reachable_nodes_may_kuch_dala_hai = true;
            }
            s1.push(k);
        }
    }
    cout<<"kuch : ";
    cout<<reachable_nodes_may_kuch_dala_hai<<endl;
    int prev_src = src;
    while (1){
    //    cout<<"here6";
        src = s1.top();
  //      cout<<"In source "<<src<<endl;;
        s1.pop();
        bool visited_src = false;
        for(int m=0;m<visited_count;m++){
            if(visited[m] == src){
                visited_src = true;
            }
        }
        if(!visited_src){
            break;
        }
    }
    if(reachable_nodes_may_kuch_dala_hai)
    count++;
}
//cout<<"out";


}


return least_count_index;

}



int main() {
    int n = 4;
    int** graph1 = new int*[n];
    for(int i=0;i<n;i++){
        graph1[i] = new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph1[i][j] = 0;
        }
    }
    //making edges
    graph1[0][1] = 1;
    graph1[1][0] = 1;
    graph1[0][2] = 1;
    graph1[2][0] = 1;
    graph1[0][3] = 1;    
    graph1[3][0] = 1;    


        for(int i=0;i<n;i++){
               cout<<i<<"    ";
        for(int j=0;j<n;j++){
            cout<<graph1[i][j]<<" ";
        }
        cout<<endl;
    }

        cout<<endl;

        int best_node_g1 = find_best_node(graph1,n);
        cout<<"Best node g1 : "<<best_node_g1<<endl;

     n = 8;
    int** graph2 = new int*[n];
    for(int i=0;i<n;i++){
        graph2[i] = new int[n];
    }
    for(int i=0;i<n;i++){
       

        for(int j=0;j<n;j++){
            graph2[i][j] = 0;
        }
    }

    
    make_edge(0,1,graph2);
    make_edge(1,2,graph2);
    make_edge(1,5,graph2);
    make_edge(2,3,graph2);
    make_edge(2,6,graph2);
    make_edge(3,4,graph2);
    make_edge(3,7,graph2);


        for(int i=0;i<n;i++){
            cout<<i<<"    ";
        for(int j=0;j<n;j++){
            cout<<graph2[i][j]<<" ";
        }
        cout<<endl;
    }

        int best_node_g2 = find_best_node(graph2,n);
        cout<<"Best node g2 : "<<best_node_g2<<endl;

    return 0;

}