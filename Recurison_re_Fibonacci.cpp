#include <iostream>
#include <string>

using namespace std;

    int fibonacci_series_return_number(int position){

        //Base cases
        if(position==1){
            return 0;
        }
        if(position==2){
            return 1;
        }

        //Recursive call

        int ans = fibonacci_series_return_number(position-1) + fibonacci_series_return_number(position-2);

        return ans;
    }

    int fibonacci_series_return_position(int number){
        static int counter = 3;
        static int temp = 1;
        //Base case
        if(number==0){
            return 1;
        }
        if(number==1){
            return 2;
        }
        if(temp==number){
            return counter;
        }
        counter++;
        temp = fibonacci_series_return_position()





    }

int main() {
    int position;
    cin>>position;
    cout<<"Number at "<<position<<" position : "<<fibonacci_series_return_number(position)<<endl;
    int number;
    cin>>number;
    cout<<number<<" is found at postiion"<<fibonacci_series_return_position(number)<<endl;
    
    
    return 0;
}