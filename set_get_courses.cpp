#include "Fast_class.h"
#include <iostream>
using namespace std;

void FAST :: set_courses(){
    int number_of_courses;
    cout<<"Enter Number of Departments: ";
    cin>>number_of_departments;
    departments = new string*[number_of_departments];
    track_number_of_courses_of_each_deparment = new int[number_of_departments];
    for(int i = 0; i<number_of_departments ; i++){
        cout<<"\nEnter number of Courses for Department no. : "<<i+1<<endl;
        cin>>number_of_courses;
        track_number_of_courses_of_each_deparment[i] = number_of_courses;
        departments[i] = new string[number_of_courses];
            for(int j=0;j<number_of_courses;j++){
                cout<<"\nEnter Tittle for Cousrse no."<<j+1<<" : ";
                cin>>departments[i][j];
            }
    }
    cout<<endl;
}
void FAST :: get_courses(){
    for(int i=0 ; i<number_of_departments; i++){
        cout<<"Course list for department no."<<i+1<<endl;
        for(int j=0 ; j<track_number_of_courses_of_each_deparment[i];j++){
            cout<<"Course no."<<j+1<<" : "<<departments[i][j]<<"\t";
        }
        cout<<endl;
    }
}