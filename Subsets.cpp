#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(int* arr,vector<vector<int>>&ans , vector<int>&fill,int ind){
	//Base case
	if(ind == 3){
		for(int i=0;i<fill.size()-1 ; i++){
			for(int k=0;k<fill.size()-1;k++){
				if(fill[k]>fill[k+1]){
					swap(fill[k],fill[k+1]);
				}
			}
		}
		for(int i=0; i<ans.size(); i++){
			if(ans[i] == fill){
				return;
			}
		}
		ans.push_back(fill);
		return;
	}
		bool same = false;
		for(int i=0; i<ans.size(); i++){
			if(ans[i] == fill){
				same = true;
			}
		}
		if(!same)
		ans.push_back(fill);	
	
	for(int i=0;i<3;i++){
		bool mojod = false;
		for(int m =0;m<fill.size();m++){
			if(fill[m] == arr[i]){
				mojod = true;
			}
		} 
		if(!mojod){
		
		fill.push_back(arr[i]);
		solve(arr,ans,fill,ind+1);
		fill.pop_back();
	}}
	
	
	
	
}


main(){
	int arr[3] = {1,2,3};
	vector<vector<int>> ans;
	vector<int> fill;
	solve(arr,ans,fill,0);
	for(int i=0 ; i<ans.size() ; i++){
		for(int j=0;j<ans[i].size() ; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	
}