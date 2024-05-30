#include <iostream>
#include <string>
#include <climits>

using namespace std;

//Consider a task as a Node
class task{
public:
int id;
int time;
int memory;
int storage;
task* next;
task(){
    next = NULL;
    id=time=memory=storage=0;
}
task(int i,int t,int m ,int s){
    next = NULL;
    id = i;
    time = t;
    memory = m;
    storage = s;
}
~task(){
    delete next;
}
};
class task_queue{
public:
task* head;
task_queue(){
    head = NULL;
}
task_queue(task*h){
    head = h;
}
void enqueu(task t){
    if(head == NULL){
            head = new task;
            head->id = t.id;
            head->time = t.time;
            head->memory = t.memory;
            head->storage = t.storage;
            head->next = NULL;
            return;        
    }
        task* tt = head;
        while(tt->next != NULL){
            tt = tt->next;
        }
        task* new_t = new task(t.id,t.time,t.memory,t.storage);
        tt->next = new_t;
        new_t->next = NULL;    
}
void delete_from_head(){
    head = head->next;
}
task* delete_from_head_with_ret(){
    task* t = head;
    head = head->next;
    return t;
}
void delete_from_tail(){
    task* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
}
task* delete_from_tail_with_ret(){
    task* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    task* ret = temp->next;
    temp->next = NULL;
    return ret;
}
void dequeu(){
    //Task with the least memory would have top priority of being dequeued
    int min_mem = INT_MAX;
    task* t = new task;
    task* tt = head;
    task* temp_t = head;
    while(temp_t->next != NULL){
        temp_t = temp_t->next;
    }
    while(tt != NULL){
        if(tt->memory < min_mem){
            min_mem = tt->memory;
            t = tt;
        }
        tt = tt->next;
    }
    if(t == head){
        delete_from_head();
        return;
    }
    if(t == temp_t){
        delete_from_tail();
        return;
    }
    task* p = head;
    while(p->next != t){
        p = p->next;
    }
    p->next = t->next;
    t->next = NULL;
}
task* dequeu_with_ret(){
    //Task with the least memory would have top priority of being dequeued
    int min_mem = INT_MAX;
    task* t = new task;
    task* tt = head;
    task* temp_t = head;
    while(temp_t->next != NULL){
        temp_t = temp_t->next;
    }
    while(tt != NULL){
        if(tt->memory < min_mem){
            min_mem = tt->memory;
            t = tt;
        }
        tt = tt->next;
    }
    if(t == head){
    return delete_from_head_with_ret();
        
    }
    if(t == temp_t){
    return delete_from_tail_with_ret();
    }
    task* p = head;
    while(p->next != t){
        p = p->next;
    }
    p->next = t->next;
    t->next = NULL;
    return t;
}
task* return_potential_deque(){
    //Task with the least memory would have top priority of being dequeued
    int min_mem = INT_MAX;
    task* t = new task;
    task* tt = head;
    task* temp_t = head;
    while(temp_t->next != NULL){
        temp_t = temp_t->next;
    }
    while(tt != NULL){
        if(tt->memory < min_mem){
            min_mem = tt->memory;
            t = tt;
        }
        tt = tt->next;
    }
    return t;
}
void traverse(){
    if(head == NULL){
        cout<<"Empty task queue\n";
        return;
    }
    task* t = head;
    while(t!=NULL){
        cout<<t->id<<" "<<t->time<<" "<<t->storage<<" "<<t->memory<<" "<<endl;
        t = t->next;
    }
}
bool is_empty(){
    if(head == NULL){
        //All tasks have been sent to server queue for processing
        return true;
    }
    //Some task are remaining to be sent to server queue for processing
    return false;
}
};

class server_queue{
    public:
    int max_memory;
    task* head;
    task_queue tq;
    server_queue(){
        head = NULL;
        max_memory = 0;
    }
    server_queue(int mm,task* h){
        max_memory = mm;
        head = h;
    }
    server_queue(int mm,task_queue t){
        head = NULL;
        max_memory = mm;
        tq = t;
    }
    int current_total_memory(){
        task* t = head;
        int memory = 0;
        while(t!=NULL){
            memory = memory + t->memory;
            t = t->next;
        }
        return memory;
    }    
    bool enqueue(task* t){
        //Check if the max capacity is reached or not
        if(current_total_memory() == max_memory){
            cout<<"Server Queue is FULL i.e Max memory reached\n";
            return false;
        }
        //Check if adding the task would excced the memory
        if(current_total_memory() + t->memory > max_memory){
            cout<<"Adding the next potential task would result in excceding tha max psbl memory\n";
            return false;;
        }
        //Check if the queue is empty or not
        if(head == NULL){
            head = new task;
            head->id = t->id;
            head->memory = t->memory;
            head->storage = t->storage;
            head->time = t->time;
            head->next = NULL;
            cout<<"Task enuqued to server queue\n";
            return true;
        }
        task* tt = head;
        while(tt->next != NULL){
            tt = tt->next;
        }
        task* new_t = new task(t->id,t->time,t->memory,t->storage);
        tt->next = new_t;
        new_t->next = NULL;
        cout<<"Task enuqued to server queue\n";
        return true;
    }    
    void dequeu(){
        // if(head == NULL){
        //     return;
        // }
        head = head->next;
        cout<<"Task processed from server queue\n";
    }
    void traverse(){
        if(head == NULL){
            cout<<"Empty server queue\n";
            return;
        }
        task* t = head;
        while(t != NULL){
        cout<<t->id<<" "<<t->time<<" "<<t->storage<<" "<<t->memory<<" "<<endl;
        t = t->next;            
        }
    }
    bool is_empty(){
        //All tasks have been processed
        if(head == NULL){
            return true;
        }
        //Some tasks are pending for being processed
        return false;
    }
    void processing(){
     cout<<"In processing\n";
     while(!tq.is_empty()){
        cout<<"Printing Task Queue: \n";
        tq.traverse();
        cout<<"\nPrinting Server Queue: \n";
        traverse();
        if(enqueue(tq.return_potential_deque())){
            tq.dequeu();
            continue;
        }
        else{
            while(current_total_memory() + tq.return_potential_deque()->memory > max_memory){
                dequeu();
            }
        }
     }
     while(!is_empty()){
        dequeu();
     }
     cout<<"All Task processed successfully\n";

    }
    ~server_queue(){
        delete head;
    }
};



int main() {
    task t1(1,10,100,1000);
    task t2(5,50,500,5000);
    task t3(6,60,60,6000);
    task_queue tq1;
    tq1.enqueu(t1);
    tq1.enqueu(t2);
    tq1.enqueu(t3);
    server_queue s1(525,tq1);
    s1.processing();


    return 0;
}