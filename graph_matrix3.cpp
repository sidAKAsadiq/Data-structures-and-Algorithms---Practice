#include <iostream>
#include <string>
#include <climits>
#include <stack>
using namespace std;



void make_edge(int src, int dest, int** &graph){
    graph[src][dest] = 1;
    graph[dest][src] = 1;
}
void make_edge_directed(int src,int dest,int** &graph){
    graph[src][dest] = 1;
}
void dfs(int** &graph,int n){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    int src = 0;
    stack<int> s1;
    s1.push(src);
    visited[src] = true;
    while(!s1.empty()){
        int temp = s1.top();
        cout<<temp<<" ";
        s1.pop();
        for(int i=0;i<n;i++){
            if(graph[temp][i] == 1 && visited[i] == false){
                s1.push(i);
                visited[i] = true;   
         }
        }
    }

}

void make_edge_weighted(int src,int dest, int w, int** &g){
g[src][dest] = w;
g[dest][src] = w;
}

void dijktras_algo(int** &graph1,int n){
    int* ans = new int[n];
    bool* visited = new bool[n];
    for(int i = 0;i<n;i++){
        ans[i] = INT_MAX;
        visited[i] = false;
    }
    cout<<"Soruce ? ";
    int src;
    cin>>src;
    ans[src] = 0;
    visited[src] = true;
    bool all_visited = false;
    while(!all_visited){
        all_visited = true;
        //checking if all visited
        for(int i=0;i<n;i++){
            if(visited[i] == false){
                all_visited = false;
                break;
            }
        }
        if(all_visited){
            break;
        }
        //Placing minimum distances in answer array
        int weight_to_be_added = ans[src];
        for (int i=0;i<n;i++){
            if(graph1[src][i]!=0 && visited[i] == false){
                int sum = weight_to_be_added + graph1[src][i];
                if(sum <= ans[i]){
                    ans[i] = sum;
                }
            }
        }
        int min_val = INT_MAX;
        int min_index;
        for(int i=0;i<n;i++){
            if(ans[i] <= min_val && visited[i] == false){
                min_val = ans[i];
                min_index = i;
            }
        }
        src = min_index;
        visited[src] = true;
    }
    cout<<"Ans : ";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}


int main() {
    int n = 6;
    int** graph1 = new int*[n];
    for(int i=0;i<n;i++){
        graph1[i] = new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph1[i][j] = 0;
        }
    }
    make_edge_weighted(0,1,3,graph1);
    make_edge_weighted(0,2,2,graph1);
    make_edge_weighted(1,2,3,graph1);
    make_edge_weighted(2,3,4,graph1);
    make_edge_weighted(2,4,6,graph1);
    make_edge_weighted(3,4,5,graph1);
    make_edge_weighted(3,5,1,graph1);
    make_edge_weighted(4,5,6,graph1);

    cout<<"   "; 
    for(int i=0;i<n;i++){
        cout<<i<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        cout<<i<<"  ";
        for(int j=0;j<n;j++){
            cout<<graph1[i][j]<<" ";
        }
        cout<<endl;
    }

    dijktras_algo(graph1,n);

    return 0;

}