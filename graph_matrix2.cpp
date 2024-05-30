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
        //pushing all adjacent and non visited nodes of the temp into stack
        for(int i=0;i<n;i++){
            if(graph[temp][i] == 1 && visited[i] == false){
                s1.push(i);
                visited[i] = true;   
         }
        }
    }

}
int main() {
    int n = 8;
    int** graph1 = new int*[n];
    for(int i=0;i<n;i++){
        graph1[i] = new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph1[i][j] = 0;
        }
    }
    make_edge_directed(0,1,graph1);
    make_edge_directed(1,2,graph1);
    make_edge_directed(1,3,graph1);
    make_edge_directed(2,6,graph1);
    make_edge_directed(2,7,graph1);
    make_edge_directed(3,4,graph1);
    make_edge_directed(4,5,graph1);
    make_edge_directed(5,3,graph1);
    make_edge_directed(7,6,graph1);
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
    dfs(graph1,n);
    cout<<"wapis";
    return 0;

}