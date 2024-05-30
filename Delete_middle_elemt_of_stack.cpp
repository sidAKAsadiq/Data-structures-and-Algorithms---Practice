#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    //s.push(3);
    s.push(1);
    s.push(9);
    s.push(5);
    s.push(2);
    s.push(8);
    s.push(8);
    int size = s.size();
    int number_of_times_to_be_stored;
    if(size%2 == 0){
        number_of_times_to_be_stored = (size/2);
    }
    else{
        number_of_times_to_be_stored = (size/2);
    }
    cout<<"number : "<<number_of_times_to_be_stored<<endl;
    int * arr = new int [number_of_times_to_be_stored];
    for(int i = 0 ;i<number_of_times_to_be_stored ; i++){
        cout<<"Copying : "<<s.top()<<endl;
        arr[i] = s.top();
        s.pop();
    }
    cout<<"Elenet being deleted : "<<s.top()<<endl;
    s.pop(); //deleting the middle element

    //Copy the element above the element that has been deleted

    for(int i=number_of_times_to_be_stored - 1 ; i>=0 ; i--){
        cout<<"Pushing "<<arr[i]<<endl;
        s.push(arr[i]);
    }

    cout<<s.top();
    arr = NULL;
    delete arr;
    return 0;
}