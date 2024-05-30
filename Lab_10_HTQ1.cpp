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
main(){
    int n = 6;
    heap min_heap(n);
    int arr[6] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    for(int i =0;i<n;i++){
        min_heap.insert_min_heap(arr[i]);
    }  
    min_heap.print();
    cout<<min_heap.arr[4]<<endl;
    min_heap.arr[4] = 2; //Commenting out this would make a Min heap else this is not a min heap
    min_heap.check_min_heap();


}