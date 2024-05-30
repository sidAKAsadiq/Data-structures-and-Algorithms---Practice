#include <iostream>
#include <string>
using namespace std;
//CS - BS with gap
main() {
	int arr[10] = {5,4,3,2,1,10,-2,5,100,25};

	for(int gap = 10/1.3 ; gap>0; gap = gap/1.3){
		for(int i = gap ; i<10;i++){
			if(arr[i-gap] > arr[i]){
				swap(arr[i-gap] , arr[i]);
			}
		}
	}	



	for(int i=0; i<10; i++) {
		cout<<arr[i]<<" ";
	}
}