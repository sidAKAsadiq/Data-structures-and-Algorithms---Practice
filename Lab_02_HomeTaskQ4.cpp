#include <iostream>
#include <string>

using namespace std;

class Employee{
public:
string first_name;
string last_name;
int age;
int employee_id;

Employee(){}
Employee(string s1,string s2,int a,int b){
first_name = s1;
last_name = s2;
age = a;
employee_id = b;
}
};

void insertion_sort(Employee* array_of_employees,int n){
    //Implementing insertion sort
    for(int i=0;i<n-1;i++){
        if(array_of_employees[i].employee_id>array_of_employees[i+1].employee_id){
            swap(array_of_employees[i],array_of_employees[i+1]);
                if(i!=0){
                    //Track back the array till we find 0th index or condition
                    for(int j=i ; j>0 ; j++){
                        if(array_of_employees[j].employee_id<array_of_employees[j-1].employee_id){
                            swap(array_of_employees[j],array_of_employees[j-1]);
                        }
                        else{
                            break;
                        }
                    }
                }
        }
    }
}

int main() {
    Employee e1("Muhammad","Sadiq",23,5);
    Employee e2("Muhammad","Ahmed",23,2);
    Employee e3("Sid","Ash",23,21);
    Employee e4("Saad","ali",23,3);
    Employee e5("ishras","sudook",23,14);
    Employee e6("jalil","jumaji",23,400);
    Employee e7("masood","kalu",23,45);
    int n = 7;
    Employee* array_of_employees = new Employee[n] {e1,e2,e3,e4,e5,e6,e7};
    cout<<"Before Insertion sort : \n";
    for(int i=0;i<n;i++){
        cout<<i+1<<" Name : "<<array_of_employees[i].first_name + " " + array_of_employees[i].last_name<<" Age : "<<array_of_employees[i].age<<" Employee ID : "<<array_of_employees[i].employee_id<<endl;
    }

    insertion_sort(array_of_employees,n);

    cout<<"\nAfter Insertion sort : \n";
    for(int i=0;i<n;i++){
        cout<<i+1<<" Name : "<<array_of_employees[i].first_name + " " + array_of_employees[i].last_name<<" Age : "<<array_of_employees[i].age<<" Employee ID : "<<array_of_employees[i].employee_id<<endl;
    }

    return 0;
}