#include <iostream>
#include <string>
#include <queue>
using namespace std;
// class queue{
//     public:
//     int* arr;
//     int size;
//     int pushing_index;
//     int popping_index;
//     queue(int size){
//         this->size = size;
//         arr = new int[size];
//         pushing_index = 0;
//         popping_index = 0;
//     }
//     void push(int data){
//         //To check overflow
//         if(pushing_index == size-1){
//             cout<<"Queue is FULL!\n";
//             return;
//         }
//         arr[pushing_index] = data;
//         pushing_index++;
//     }
//     void pop(){
//         //To check if queue has any element
//         if(pushing_index==0){
//             cout<<"Queue empty\n";
//         }
//         else{
//             popping_index++;
//         }
//     }
//     bool is_empty(){
//         if(pushing_index==0){
//             return true;
//         }        
//         return false;
//     }
//     int front(){
//         return arr[popping_index];
//     }
//     int back(){
//         return arr[pushing_index-1];
//     }
// };


int main() {
    queue < int >  q;
   // q.front;
    vector<int> v;
    q.front();
    return 0;
}