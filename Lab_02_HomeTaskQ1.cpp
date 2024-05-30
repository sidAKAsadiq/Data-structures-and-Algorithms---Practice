#include <iostream>
#include <string>
using namespace std;
main(){
    int n;
    cout<<"Enter size of array\n";
    cin>>n;
    string* arr = new string[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element no."<<i+1<<endl;
        fflush(stdin);
        getline(cin,arr[i]);
    }
cout<<"Before bubble sort \n";
for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
}
    //Implementing Bubble sort on array of strings
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

cout<<"After bubble sort \n";
for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
}

}