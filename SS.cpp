#include <iostream>
#include <string>
using namespace std;
//SS
main(){
	int arr[5] = {5,4,3,2,1};
	
	int min;
	for(int i = 0 ; i<4 ; i++){
		for(int j = i+1; j<5;j++){
			if(arr[j]<arr[i]){
				min = j;
			}
		}
		swap(arr[i],arr[min]);
	}	

	
	
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
}