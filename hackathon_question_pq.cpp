#include <iostream>
#include <string>

using namespace std;

class card{
public:
string name;
int initiative_val;
string element_prior;
card(){}
card(string s,int v,string ep){
    name = s;
    initiative_val = v;
    element_prior = ep;
}  
void display_card(){
    cout<<name<<" ("<<element_prior<<":"<<initiative_val<<")"<<endl;
}
};

//Acc to Q, we need a min heap
class heap{
public:
card* arr;
int count;
int size;
heap(){
    count = 0;
}
heap(int s){
    size = s;
    arr = new card[size];
    count = 0;
}
void insert_into_min_heap(card obj){
    //placing the card
    arr[count] = obj;
    //moving the card to its correct position
    int inserted_index = count;
    int parent_index = (count-1)/2;
    count++;
    if(inserted_index == 0){
        //First card is inserted, no need to check anything
        return;
    }
    while(inserted_index != 0){
        if(arr[parent_index].initiative_val < arr[inserted_index].initiative_val){
            //placed at right place
            return;
        }
        else if(arr[parent_index].initiative_val > arr[inserted_index].initiative_val){
            //swap objects
            card temp = arr[parent_index];
            arr[parent_index] = arr[inserted_index];
            arr[inserted_index] = temp;
            //update indexes
            inserted_index = parent_index;
            parent_index = (inserted_index-1)/2;
        }
        else{
            //when initaitive values are equal
            if(compare_elemental_priority(arr[parent_index],arr[inserted_index])){
                //returns true if priority is set i.e parent's less than child
                return;
            }
            else{
            //swap objects
            card temp = arr[parent_index];
            arr[parent_index] = arr[inserted_index];
            arr[inserted_index] = temp;
            //update indexes
            inserted_index = parent_index;
            parent_index = (inserted_index-1)/2;
            }
        }
    }
}
bool compare_elemental_priority(card parent,card child){
if(child.element_prior == "fire"){
    //parent uper sahi hai
    return true;
}
if(child.element_prior == "water" && parent.element_prior == "fire"){
    //child ko uper ana hai
    return false;
}
if(child.element_prior == "air" && parent.element_prior == "earth"){
    //parent uper sahi hai
    return true;
}
return false;
}
void print(){
    for(int i=0;i<count;i++){
        arr[i].display_card();
    }
}
void delete_from_heap(){
cout<<"Deleting : ";
arr[0].display_card();
card temp = arr[0];
arr[0] = arr[count-1];
arr[count-1] = temp;
count--;
//placing the obj on first index on its right place;
int index = 0;
int left_child = (2*index) + 1;
int right_child = (2*index) + 2;
while (1){
if(left_child >= count && right_child >= count){
    break;
}
else if(left_child < count && right_child >= count){
    if(arr[index].initiative_val > arr[left_child].initiative_val){
        card t = arr[index];
        arr[index] = arr[left_child];
        arr[left_child] = t;
        index = left_child;
        left_child = (2*index) + 1;
        right_child = (2*index) + 2;        
    }
    else{
        break;
    }
}
else if(right_child < count && left_child >= count){
    if(arr[index].initiative_val > arr[right_child].initiative_val){
        card t = arr[index];
        arr[index] = arr[right_child];
        arr[right_child] = t;
        index = right_child;
        left_child = (2*index) + 1;
        right_child = (2*index) + 2;        
    }
    else{
        break;
    }
}
else{
    if(arr[index].initiative_val > arr[right_child].initiative_val || arr[index].initiative_val > arr[left_child].initiative_val){
        if(arr[left_child].initiative_val < arr[right_child].initiative_val){
        card t = arr[index];
        arr[index] = arr[left_child];
        arr[left_child] = t;
        index = left_child;
        left_child = (2*index) + 1;
        right_child = (2*index) + 2;    
        }
        else{
        card t = arr[index];
        arr[index] = arr[right_child];
        arr[right_child] = t;
        index = right_child;
        left_child = (2*index) + 1;
        right_child = (2*index) + 2; 
        }
    }
    else{
        break;
    }
}
}


}
};



int main() {
    heap h1(10);
    card c1("fireball",3,"fire");
    h1.insert_into_min_heap(c1);
 //   h1.print();
   // cout<<endl;
    card c2("c2",2,"earth");
    card c22("c22",4,"fire");
    card c3("c3",1,"fire");
    h1.insert_into_min_heap(c2);
    h1.print();
    cout<<endl;
    h1.insert_into_min_heap(c22);
        h1.print();
    cout<<endl;
    h1.insert_into_min_heap(c3);
    h1.print();
    h1.delete_from_heap();
    cout<<endl;
    h1.print();

    h1.delete_from_heap();
    cout<<endl;
    h1.print();

        h1.delete_from_heap();
    cout<<endl;
    h1.print();
    return 0;
}