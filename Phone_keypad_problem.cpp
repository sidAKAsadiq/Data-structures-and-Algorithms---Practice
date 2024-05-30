#include <iostream>
#include <string>
#include <vector>
using namespace std;


void solve(string* map,int* ip,vector<string> &arr,string ans,int i,int j){
	//Base case
	if(i==3){
		arr.push_back(ans);
		return;
	}
	string retrive = map[ip[i]];
	for(int j=0;j<retrive.length();j++){
		ans.push_back(retrive[j]);
		solve(map,ip,arr,ans,i+1,j);
		ans.pop_back();
	}
	
}


main(){
	string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	int ip[3] = {2,3,4};
	vector<string> arr;
	string ans = "";
	solve(map,ip,arr,ans,0,0);
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	
	
	
	
	
	
	
	
	
	
	
	
}