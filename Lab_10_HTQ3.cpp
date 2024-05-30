#include <iostream>
#include <string>
using namespace std;

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

    while(left_child < count || right_child < count){  
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
    parent = 0;
    left_child = (2*parent) + 1;
    right_child = (2*parent) + 2; 
    if((left_child < 0 || left_child > count) && (right_child < 0 || right_child > count)){
        return;
    }    
    if((left_child < 0 || left_child > count)){
        if(arr[parent] > arr[right_child]){
            swap(arr[parent],arr[right_child]);
        }
    }
    else if((right_child < 0 || right_child > count)){
        if(arr[parent] > arr[left_child]){
            swap(arr[parent],arr[left_child]);
        }        
    }
}
void delete_max_heap(){
    swap(arr[0],arr[count]);
    count = count - 1;
    int parent = 0;
    int left_child = (2*parent) + 1;
    int right_child = (2*parent) + 2;

    if(arr[parent] > arr[left_child] && arr[parent] > arr[right_child]){
        return;
    }
    while(left_child < count || right_child < count){  
    if(arr[left_child] > arr[right_child]){
        swap(arr[parent],arr[left_child]);
        parent = left_child;
    }   
    else if(arr[right_child] > arr[left_child]){
        swap(arr[parent],arr[right_child]);
        parent = right_child;    
    }  
    left_child = (2*parent) + 1;
    right_child = (2*parent) + 2; 
    if(arr[parent] > arr[left_child] && arr[parent] > arr[right_child]){
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
        print();
    }
    cout<<"Kth smallest element : "<<arr[0]<<endl;
}
void kth_largest_element(int k){
    for(int i=1;i<k;i++){
        delete_max_heap();
    }
    cout<<"Kth Largest element : "<<arr[0]<<endl;    
}
};
main(){
    int s = 7;
    int arr[7] = {7, 10, 4, 3, 20, 15, 12};
    int n = 3;
    heap min_heap(s-n);
    heap max_heap(n);
    int j = n;
    while(j < s){
        min_heap.insert_min_heap(arr[j]);
        j++;
    }       
    j = n-1;
    while(j>=0){
        max_heap.insert_max_heap(arr[j]);
        j--;
    }
    cout<<"Min heap : ";
    min_heap.print();
    cout<<"Max heap : ";
    max_heap.print();



}