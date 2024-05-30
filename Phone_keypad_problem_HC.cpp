#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(int* a,vector<string> &arr,string ans,string first,string sec,int ind ){
	//Base case
	if(ind == 1){
		cout<<"Pushing : "<<ans<<endl;
		arr.push_back(ans);
		return;
	}
	for(int j=0;j<3;j++){
	cout<<"first[ind] = "<<first[ind]<<endl;
	ans.push_back(first[j]);
	cout<<"Ans outside loop : "<<ans<<endl;
	ind++;
	for(int i=0;i<3;i++){
		ans.push_back(sec[i]);
		cout<<"Ans in lop : "<<ans<<endl;
		solve(a,arr,ans,first,sec,ind);	
		ans.pop_back();
	}
	ind = 0;
	ans.pop_back();
}
}


int main() {
	int a[2] = {3,4};
	string first = "def";
	string sec = "ghi";
	
	vector<string> arr;
	string ans = "";
	solve(a,arr,ans,first,sec,0);
	cout<<"Possible combinations : \n";
	for(int i = 0; i<arr.size(); i++) {
		cout<<arr[i]<<" ";
	}
}