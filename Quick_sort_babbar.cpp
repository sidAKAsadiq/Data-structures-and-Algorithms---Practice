#include <iostream>
#include <string>
using namespace std;

int partition(int*arr,int s,int e){
	int element = arr[s];
	int i = s+1;
	int j = i+1;
	while(j<=e){
		if(element>arr[j]){
			swap(arr[i],arr[j]);
			i++;
			j++;
		}
		else{
			j++;
		}
	}
	swap(arr[s],arr[i]);
	return i;
}

void quick_sort(int * arr,int s,int e){
	//Base case - single element remaining
	if(s>=e){
		return;
	}
	int pivot_index = partition(arr,s,e);
	//Left
	quick_sort(arr,s,pivot_index-1);
	//Right
	quick_sort(arr,pivot_index+1,e);
}

int main() {
    int n = 5;
    int arr[n] = {5, 4, 3, 2, 1};
	int s = 0;
	int e = n-1;
	quick_sort(arr,s,e);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
