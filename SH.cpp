#include <iostream>
#include <string>
using namespace std;
//SHS - IS with gap
main() {
	int arr[5] = {2,3,4,5,0};
	for(int i=0 ;i<5;i++){
	for(int gap = 5/2 ; gap>1 ; gap = gap/2){
		for(int i = gap ; i<5; i++){
			for(int j = i - gap ; j>=0 ; j--){
				if(arr[j]>arr[i]){
					swap(arr[j],arr[j+gap]);
				}
				else{
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