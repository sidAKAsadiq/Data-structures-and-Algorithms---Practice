#include <iostream>
#include <string>
using namespace std;

//MS - Array version


void merge(int* arr,int* left,int* right,int left_s,int right_s){
	int i = 0; //For left 
	int j = 0; //For right
	int k = 0; //For org
	while(i<(left_s) && j<(right_s)){
		if(left[i]<right[j]){
			arr[k] = left[i];
			i++;
			k++;
		}
		else{
			arr[k] = right[j];
			j++;
			k++;
		}
	}
	if(i==left_s){
	while(j<right_s){
		arr[k] = right[j];
		k++;
		j++;
	}
	}
	else{
	while(i<left_s){
		arr[k] = left[i];
		i++;
		k++;
	}
	}
	
	
}

void merge_sort(int* arr,int size){
	//Base case
	if(size<=1){
		return;
	}
	int mid = size/2;
	int* left = new int[mid];
	for(int i=0;i<mid;i++){
		left[i] = arr[i];
	}	
	int* right = new int[size-mid];
	// int k = mid;
	// for(int j=0;j<size-mid;j++){
	// 	right[j] = arr[k];
	// 	k++;
	// }	
	int k = 0;
	for (int j=mid;j<size;j++){
		right[k] = arr[j];
		k++;
	}
	merge_sort(left,mid);
	merge_sort(right,size-mid);
	//Merge
	merge(arr,left,right,mid,size-mid);
//	merge(arr,left,right,s,mid,e);
}


main(){
	int arr[6] = {5,4,3,2,1,0};
	// int s = 0;
	// int e = 5;
	for(int i=0;i<6;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;	
	merge_sort(arr,6);
	for(int i=0;i<6;i++){
		cout<<arr[i]<<" ";
	}
}






