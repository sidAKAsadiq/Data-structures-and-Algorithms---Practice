#include <iostream>
#include <string>

using namespace std;

void travel_to_home(int source,int destination){

//Base case - when source and destination becomes equal
if(source == destination){
    cout<<"Source : "<<source<<" Destination : "<<destination<<endl;
    cout<<"reached home\n";
    return;
}

//Processing
cout<<"Source : "<<source<<" Destination : "<<destination<<endl;
source = source + 1; //taking one step at a time - eik case solve kardia 

//Recursive call
travel_to_home(source,destination);


}


int main() {
    int destination;
    cin>>destination;
    int source = 0;
    travel_to_home(source,destination);
    return 0;
}