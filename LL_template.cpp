#include <iostream>
#include <string>

using namespace std;

template <class s>
class node{
public:
s data;
node* <s> next;
node(){
    data = 0;
    next = NULL;
}
node(s d){
    data = d;
    next = NULL;
}
~node(){
    next = NULL;
    delete next;
}

};


int main() {
  
    return 0;
}