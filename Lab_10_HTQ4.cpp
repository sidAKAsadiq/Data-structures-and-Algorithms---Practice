#include <iostream>
#include <string>
using namespace std;

class task{
    public:
    int mem;
    int exec;
    task(){}
    task(int m,int e){
        mem = m;
        exec = e;
    }
    int get_priority(){
        return -1 * mem * exec;
    }
};
class heap{
public:
int* arr;
int size;
int count;
heap(int s){
    size = s;
    count = -1;
    arr = new int[s] {-1};
}                                                                                                                                                                                                                                               
void insert_max_heap(int d){
    count = count + 1;
    arr[count] = d;
    if(count == 0){
        return;
    }
    int element = count;
    int parent = (element-1)/2;
    while(element>0){
        if(arr[element] > arr[parent]){
            swap(arr[element],arr[parent]);
            element = parent;
            parent = (element-1)/2;
        }
        else{
            break;
        }
    }    
}
void insert_min_heap(int d){
    count = count + 1;
    arr[count] = d;
    if(count == 0){
        return;
    }
    int element = count;
    int parent = (element-1)/2;
    while(element>0){
        if(arr[element] < arr[parent]){
            swap(arr[element],arr[parent]);
            element = parent;
            parent = (element-1)/2;
        }
        else{
            break;
        }
    }    
}
void print(){
    for(int i=0 ; i<=count ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void delete_min_heap(){
    swap(arr[0],arr[count]);
    count = count - 1;
    int parent = 0;
    int left_child = (2*parent) + 1;
    int right_child = (2*parent) + 2;

    if(arr[parent] < arr[left_child] && arr[parent] < arr[right_child]){
        return;
    }

    while(left_child <= count || right_child <= count){  
    if(arr[left_child] < arr[right_child]){
        swap(arr[parent],arr[left_child]);
        parent = left_child;
    }   
    else if(arr[right_child] < arr[left_child]){
        swap(arr[parent],arr[right_child]);
        parent = right_child;    
    }  
    left_child = (2*parent) + 1;
    right_child = (2*parent) + 2; 
    if(arr[parent] < arr[left_child] && arr[parent] < arr[right_child]){
        return;
    }        
    }
}
void min_heap_TO_max_heap(){
    int i = 0;
    int j = count;
    int mid = count/2;
    while(i<=j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}
void kth_smallest_element(int k){
    for(int i=1;i<k;i++){
        delete_min_heap();
    }
    cout<<"Kth smallest element : "<<arr[0]<<endl;
}
void check_min_heap(){
    int parent = 0;
    int left_child = (2*parent) + 1;
    int right_child = (2*parent) + 2;
    while(left_child <= count && right_child <= count){
        cout<<"Parent: "<<arr[parent]<<endl;
        cout<<"LC: "<<arr[left_child]<<endl;
        cout<<"Rc: "<<arr[right_child]<<endl;
        if(arr[parent] < arr[left_child] && arr[parent] < arr[right_child]){
            parent++;
            left_child = (2*parent) + 1;
            right_child = (2*parent) + 2;
        }
        else{
            cout<<"Not a Min Heap\n";
            return;
        }
    }
    if((left_child < count || left_child < 0) && (right_child < count || right_child < 0)){
    cout<<"Yes, Its Min heap\n";
    return;
    }
    else if((left_child < count || left_child < 0)){
        if(arr[parent] < arr[right_child]){
            cout<<"Yes, Its min heap\n";
        }
        else{
            cout<<"Not a min heap\n";
        }
    }
    else{
         if(arr[parent] < arr[left_child]){
            cout<<"Yes, Its min heap\n";
        }
        else{
            cout<<"Not a min heap\n";
        }       
    }
}
};
class task_queue{
public:
task* arr;
int front;
int rear;
int size;
int counter; //Current number of elements in queue
task_queue(){}
task_queue(int s){
    arr = new task[s];
    front = rear = -1;
    size = s;
    counter = 0;
}
bool is_full(){
    if(counter == size){
        return true;
    }
    return false;
}
bool is_empty(){
    if(counter == 0){
        return true;
    }
    return false;
}
void enqueu(task obj){
    if(is_full()){
        cout<<"Queue is full\n";
        return;
    }
    rear = (rear + 1) % size;
    arr[rear] = obj;
    counter++;
    if(rear == 0){
        front = 0;
    }
}
void dequeue(){
    if(is_empty()){
        cout<<"Queue is Empty\n";
        return;
    }
    front = (front + 1) % size;
    counter-- ;
}
void print(){
    cout<<"( Mem : "<<arr[front].mem<<" , Exec : "<<arr[front].exec<<")"<<"  ";
    for(int i = front+1 ; i != front ; i = (i+1)%size){
    cout<<"( Mem : "<<arr[i].mem<<" , Exec : "<<arr[i].exec<<")"<<"  ";
    }
    cout<<endl;
}
};
class task_heap{
public:
task* arr;
int size;
int count;
task_heap(int s){
    size = s;
    count = -1;
    arr = new task[s];
}                                                                                                                                                                                                                                               
void insert_min_heap(task d){
    count = count + 1;
    arr[count] = d;
    if(count == 0){
        return;
    }
    int element = count;
    int parent = (element-1)/2;
    while(element>0){
        if(arr[element].get_priority() < arr[parent].get_priority()){
            swap(arr[element],arr[parent]);
            element = parent;
            parent = (element-1)/2;
        }
        else{
            break;
        }
    }    
}
void print(){
    for(int i=0 ; i<=count ; i++){
        cout<<"( Mem : "<<arr[i].mem<<" , Exec : "<<arr[i].exec<<")"<<"  ";
    }
    cout<<endl;
}
void delete_min_heap(){
    swap(arr[0],arr[count]);
    count = count - 1;
    int parent = 0;
    int left_child = (2*parent) + 1;
    int right_child = (2*parent) + 2;

    if(arr[parent].get_priority() < arr[left_child].get_priority() && arr[parent].get_priority() < arr[right_child].get_priority()){
        return;
    }

    while(left_child < count || right_child < count){  
    if(arr[left_child].get_priority() < arr[right_child].get_priority()){
        swap(arr[parent],arr[left_child]);
        parent = left_child;
    }   
    else if(arr[right_child].get_priority() < arr[left_child].get_priority()){
        swap(arr[parent],arr[right_child]);
        parent = right_child;    
    }  
    left_child = (2*parent) + 1;
    right_child = (2*parent) + 2; 
    if(arr[parent].get_priority() < arr[left_child].get_priority() && arr[parent].get_priority() < arr[right_child].get_priority()){
        return;
    }        
    }
    parent = 0;
    left_child = (2*parent) + 1;
    right_child = (2*parent) + 2; 
    if((left_child < 0 || left_child > count) && (right_child < 0 || right_child > count)){
        return;
    }    
    if((left_child < 0 || left_child > count)){
        if(arr[parent].get_priority() > arr[right_child].get_priority()){
            swap(arr[parent],arr[right_child]);
        }
    }
    else if((right_child < 0 || right_child > count)){
        if(arr[parent].get_priority() > arr[left_child].get_priority()){
            swap(arr[parent],arr[left_child]);
        }        
    }
}
void transfer_to_queue(task_queue &obj){
    int ind = count;
    for(int i = 0; i<=ind ; i++){
        obj.enqueu(arr[0]);
        delete_min_heap();
    }
    cout<<"Printing Queue : ";
    obj.print();
}
};

main(){
int n = 4;
task t1(1,2);
task t2(3,4);
task t3(5,6);
task t4(7,2);
task arr[4];
arr[0] = t1;
arr[1] = t2;
arr[2] = t3;
arr[3] = t4;
task_heap t(n);
for(int i=0;i<n;i++){
    t.insert_min_heap(arr[i]);
}
cout<<"Heap : ";
t.print();
task_queue q(4);
t.transfer_to_queue(q);

}