#include<iostream>
#include <string>
using namespace std;

void merge(int* arr,int s,int mid,int e){
	int left_size = mid - s + 1; //not mid+1 cuz s wont be 0 everytime
	int right_size = e - mid;
	int* left = new int[left_size];
	int i = s;
	for(int j=0;j<left_size;j++){
		left[j] = arr[i];
		i++;
	}
	int* right = new int [right_size];
	i = mid+1;
	for(int j=0;j<right_size;j++){
		right[j] = arr[i];
		i++;
	}
	//Merge arrays into original in sorted way
	i = 0; //for left arr
	int j = 0; //for right arr
	int k = s; //for org
	while(i<left_size && j<right_size){
		if(left[i]<right[j]){
			arr[k] = left[i];
			i++;
		}
		else{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while(i<left_size){
		arr[k] = left[i];
		i++;
		k++;
	}
	while(j<right_size){
		arr[k] = right[j];
		j++;
		k++;
	}
	
}


void merge_sort(int* arr,int s,int e){
	//Base case
	if(s>=e){
		return;
	}
	int mid = s + ((e-s)/2);
	//Left part
	merge_sort(arr,s,mid);
	//Right part
	merge_sort(arr,mid+1,e);
	//Merge 2 sorted arrays
	merge(arr,s,mid,e);
	
	
}


main(){
	int n = 6;
	int arr[n] = {5,4,3,2,1,0};
	int s = 0;
	int e = n-1;
	merge_sort(arr,s,e);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}










