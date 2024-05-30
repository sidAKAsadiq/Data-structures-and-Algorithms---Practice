#include<iostream>
#include <string>
#include <vector>
using namespace std;

void solve(string &s,vector<string> &arr,int len,int ind){
	//Base case
	if(ind == len){
		arr.push_back(s);
		return ;
	}

	for(int i=ind;i<len;i++){
		swap(s[ind],s[i]);
		solve(s,arr,len,ind+1);
		//BT
		swap(s[ind],s[i]);
	}
}

int main(){
	string s = "abc";
	vector<string> arr;
	solve(s,arr,3,0);
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\norg"<<s;
	return 0;
}