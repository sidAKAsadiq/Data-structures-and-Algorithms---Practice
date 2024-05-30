#include <iostream>
#include <string>
#include "class_linkedlist.h"
using namespace std;
class edge{
public:
int id;
edge(){}
edge(int i){
    id = i;
}
};
class edge_list{
public:
singly_linked_list<int> adj_nodes;
void add_edge(int idd){
    adj_nodes.add_to_end_of_LL(idd);
}
void print_edge_list(){
    adj_nodes.traverse_LL();
}
};
class vertex{
public:
int id;
edge_list el;
vertex(){}
vertex(int i){
    id = i;
}
void add(int idd){
    cout<<"gere\n";
    el.add_edge(idd);
}
void print_vertex(){
    cout<<"V : "<<id<<" -> ";
    el.print_edge_list();
    //cout<<" ]\n";
}
};
class graph{
public:
vertex arr[100];
int count;
graph(){
    cout<<"hereC\n";
    count = 0;
}
void add_vertex(vertex v1){
    cout<<"here V\n";
    arr[count] = v1;
    cout<<count;
    arr[0].print_vertex();
    count++;
    cout<<count<<endl;
}
void print_graph(){
   // cout<<"here]n";
    for(int i=0;i<count;i++){
        //cout<<"here\n";
        arr[i].print_vertex();
    }
}
};

main(){
vertex v1(0);
vertex v2(1);
vertex v3(2);
vertex v4(3);
vertex v5(4);
v1.add(1);
v1.add(4);
v2.add(0);
v2.add(2);
v2.add(3);
v2.add(4);
v3.add(1);
v3.add(3);
v4.add(1);
v4.add(2);
v4.add(4);
v5.add(0);
v5.add(1);
v5.add(3);
graph g1;
// g1.add_vertex(v1);
// cout<<"back\n";
// g1.add_vertex(v2);
// g1.add_vertex(v3);
// g1.add_vertex(v4);
// g1.add_vertex(v5);
g1.arr[0] = v1;
g1.count++;
g1.arr[1] = v2;
g1.count++;
g1.arr[2] = v3;
g1.count++;
g1.arr[3] = v4;
g1.count++;
g1.arr[4] = v5;
g1.count++;
g1.print_graph();



}