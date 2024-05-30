#include <bits/stdc++.h> 
class CircularQueue{
    int* arr;
    int front;
    int back;
    int size;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        back = -1;
        front = 0;
        // Write your code here.
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if((back>front)&&(front==0&&back=size-1)){
          //Cant enter element
          return false;
        }      
        if((back<front)&&(back+1==front)){
          //Cant enter element 
          return false;
        }
        if((back>front)&&(back==size-1&&front!=0)){
          back=0;
          arr[back] = value;
          return true;
        }
        back++;
        arr[back]=value;
        return true;
        // Write your code here.
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
    }
};