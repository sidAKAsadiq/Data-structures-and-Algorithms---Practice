#include <iostream>
#include <string>
using namespace std;
//IS
main() {
	int arr[5] = {3,2,1,5,-1};

	for(int m=0; m<4; m++) {
		for(int i=0; i<4; i++) {
			if(arr[i]>arr[i+1]) {
				swap(arr[i],arr[i+1]);
			//Backtrack
			for(int j=i-1 ; j>=0 ; j--) {
				if(arr[j]>arr[i]) {
					swap(arr[j],arr[i]);
				}
				 else {
					break;
				}
			}
			}
		}
	}



	for(int i=0; i<5; i++) {
		cout<<arr[i]<<" ";
	}
}