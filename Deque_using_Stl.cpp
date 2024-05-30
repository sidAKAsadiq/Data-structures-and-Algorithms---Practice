#include <bits/stdc++.h> 
class Deque
{
public:
    int* arr;
    int front;
    int back;
    int size;


    Deque(int n)
    {
        size = n;
        arr = new int[size];
        back=front=-1;
    }
    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
            if(front==-1)
            return true;
            else
            return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if((front==0 && back==size-1)||(back==(front-1)%(size-1))){
            return true;
        }
        else{
            return false;
        }
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if(isFull()){
            return false;
        }
       else if(front==0){ //(front==0 && back!=size-1)
            front = size - 1;
        }
       else if(front==-1){
            back=front=0;
        }
        else {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if(isFull()){
            return false;
        }
        else if(back==size-1){ //(back==size-1 &&  front!=0)
            back=0;
        }
        else if(front ==-1){
            back=front=0;
        }
        else{
            back++;
        }
        arr[back]=x;
        return true;

    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        int element;
        if(isEmpty()){
            return -1;
        }
        else if(front==size-1){
            element = arr[front];
            front=0;
        }
        else if(front==back){
            element = arr[front];
            front=back=-1;
        }
        else{
            element = arr[front];
            front++;
        }
        return element;

    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        int element;
        if(isEmpty()){
        return -1;
        }
        else if(back==front){
            element = arr[back];
            front=back=-1;
        }
        else if(back==0){
            element = arr[back];
            back = size-1;            
        }
        else{
            element = arr[back];
            back--;
        }
        return element;
        
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[back];        // Write your code here.
    }

};