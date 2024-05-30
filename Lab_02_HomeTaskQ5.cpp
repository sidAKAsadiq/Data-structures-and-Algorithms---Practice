#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main() {
    int n = 11;
    int array[n] = {10,12,20,30,25,40,32,31,35,50,60};
    int start = 0;
    int end = n-1;
    int minimum_element_from_start_to_end = INT_MAX;
    int maximum_element_from_start_to_end = INT_MIN;
        //Traversing left to right and finding start index
    for(int i=0 ; i<n-1 ; i++){
        if(array[i]<array[i+1]){
            start++;
        }
        else{
            break;
        }
    }
        //Traversing right to left and finding end index
    for(int i=n-1 ; i>=0 ; i--){
        if(array[i]>array[i-1]){
            end--;
        }
        else{
            break;
        }
    }
    for(int i=start ; i<=end ; i++){
        if(array[i]>maximum_element_from_start_to_end){
            maximum_element_from_start_to_end = array[i];
        }
        if(array[i]<minimum_element_from_start_to_end){
            minimum_element_from_start_to_end = array[i];
        }
    }
    //Re-tracking the array until we find an element lesser than minimum and greater than maximum
    for(int i=start ; i>=0 ; i--){
        if(array[i-1]>minimum_element_from_start_to_end){
            start--;
        }
        else{
            break;
        }
    }
    for(int i=end ; i<n ; i++){
        if(array[i+1]<maximum_element_from_start_to_end){
            end++;
        }
        else{
            break;
        }        
    }
    //cout<<"min"<<minimum_element_from_start_to_end<<"max"<<maximum_element_from_start_to_end;
    //cout<<"start "<<start<<"end "<<end;
    cout<<"Start = "<<start<<" End = "<<end<<endl;
    cout<<"Minimum Length = "<< abs(start-end) + 1;
    return 0;
}