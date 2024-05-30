#include<iostream>
#include<string>
using namespace std;
int main() {
	int n = 7;
	int arr[7] = {4,2,3,8,2,1,0};
	cout<<"initial : ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}	
	cout<<endl;
	int freq[10] = {0};
	//Counting frequency
	for(int i=0; i<n; i++) {
		freq[arr[i]]++;
	}
	//Cumilation of freq array
	int i = 1;
	for(int j = 0 ; j<10; j++) {
		freq[i] = freq[j] + freq[i];
		i++;
	}
	//Placing values in sorting order in our final array
	int final[n];
	for(int i = n-1; i>=0 ; i--){
		int val = arr[i];
		int new_index =	--freq[val]; 
		final[new_index] = val;
	}
	cout<<"final : ";
	for(int i=0;i<n;i++){
		cout<<final[i]<<" ";
	}
	
	
	
	
	
	
	
	
	
	

}