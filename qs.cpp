#include<iostream>
using namespace std;

void qs(int*arr,int s,int e){
	if(s>=e){
		return;
	}
	//find the pivot
	int index=s;
	int pivot=arr[e];
	for(int i=s;i<e;i++){
		if(arr[i]<pivot){
			swap(arr[i],arr[index]);
			index++;
		}
	}
	swap(arr[e],arr[index]);
	qs(arr,s,index-1);
	qs(arr,index+1,e);
}
int main(){
	int arr[5]={2,4,2,1,7};
	qs(arr,0,4);
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
}