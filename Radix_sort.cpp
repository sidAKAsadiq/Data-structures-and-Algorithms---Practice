#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int count_digs(int a) {
	int counter = 0;
	while(a!=0) {
		a = a/10;
		counter++;
	}
	return counter;
}
int main() {
	int n = 7;
	int arr[7] = {19,302,88,42,1,100,201};
	int final [7];
	int freq[10] = {0}; //Initializing freq array with 0s
	int max = 0;
	for(int i = 0;i<n;i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	for(int k = 0 ; k<count_digs(max); k++){
		//Finding freq of last number of each element
		for(int i = 0 ; i<n ; i++){
			int var1 = arr[i];
			int flag = 0;
			while(flag!=k){
				var1 = var1/10;
				flag++;
			}
			freq[var1%10]++;
		}
		cout<<"Freq : ";
		for(int i=0;i<10;i++){
			cout<<freq[i]<<" ";
		}
		cout<<endl;
		//Cumilation on freq array
		int m = 1;
		for(int i=0;i<10;i++){
			freq[m] = freq[i] + freq[m];
			m++;
		}
		cout<<"Cumilated : ";
		for(int i=0;i<10;i++){
			cout<<freq[i]<<" ";
		}
		cout<<endl;		//{19,302,88,42,1,100,201}
		for(int i = n-1; i>=0 ; i--){ 
			int var1 = arr[i];
			int flag = 0;
			while(flag!=k){
				var1 = var1/10;
				flag++;
			}
			int val = var1%10;
			int new_index = --freq[val];
			final[new_index] = arr[i];
		}
		//setting all freq back to 0
		for(int i=0;i<10;i++){
			freq[i] = 0;
		}
		//Copying final arr to org arr
		for(int i=0;i<n;i++){
			arr[i] = final[i];
		}
	}
	for(int i=0;i<n;i++){
		cout<<final[i]<<" ";
	}
	
	
	
	
	
	
	
}