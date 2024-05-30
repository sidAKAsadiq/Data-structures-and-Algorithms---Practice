#include <iostream>
#include <string>
using namespace std;

int main() {
    char arr[4]={'a','a','b','c'};
    int size = 4;
    int store[26] = {0};
    int i = 0;
    int j = 0;
    while(i<=j){
        store[arr[i] - 97]++;
        i++;



    }
    return 0;
}