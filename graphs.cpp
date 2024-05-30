#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;

class graph{
public:
map<int , list<int>> adj_list;
//undirected
void form_edge(int u, int v){
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}
void remove_edge(int u, int v){
    adj_list[u].remove(v);
    adj_list[v].remove(u);
}
void print_adj_list(){
    for(auto i : adj_list){
        cout<<i.first<<" -> ";
        for(auto j : i.second){
            cout<<j<<" , ";
        }
        cout<<endl;
    }
}


};


int main() {
    graph g;
    g.form_edge(0 ,1);
    g.form_edge(2 ,1);
    g.form_edge(2 ,0);
    g.print_adj_list();
    g.remove_edge(2,1);
    cout<<endl;
    g.print_adj_list();
    return 0;
}