#include <iostream>
#include <string>

using namespace std;

void print_counting(int count_from){
//Base case
if(count_from == 0){
    return;
}
//Processing
cout<<count_from<<" ";
//Recursive call
print_counting(count_from-1);

}


int main() {
    int count_from;
    cin>>count_from;
    print_counting(count_from);
    return 0;
}