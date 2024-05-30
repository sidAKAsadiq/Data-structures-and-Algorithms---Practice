#include <iostream>
#include <string>

using namespace std;

int print_counting(int n){

    //Base case 
    if(n==1){
        cout<<n;
        return 0;
    }

    //Processing -> Not mandatory
    cout<<n<<"\t";

    //Recurisve relation -> mandatory
    return print_counting(n-1);

}


int main() {
    int n;
    cin>>n;
    print_counting(n);
    return 0;
}