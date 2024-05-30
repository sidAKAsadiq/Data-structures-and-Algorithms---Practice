#include<iostream>
using namespace std;
main(){
    int* one_d_array = new int[20] {0};
    int count = 1;
    for(int i = 0; i<20;i++)
    {
        one_d_array[i] = count;
        count++;
    }
    for(int i = 0; i<20;i++)
    {
        cout<<one_d_array[i]<<" ";
    }    
    delete one_d_array;
    one_d_array = NULL;
}