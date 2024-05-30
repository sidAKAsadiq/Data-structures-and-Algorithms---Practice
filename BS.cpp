#include <iostream>
#include <string>
using namespace std;
//Bs
main(){
	int arr[5] = {5,4,3,2,1};
	for(int i=0;i<4;i++){
		for(int i=0;i<4;i++){
			if(arr[i]>arr[i+1]){
				swap(arr[i],arr[i+1]);
			}
		}
	}
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
}