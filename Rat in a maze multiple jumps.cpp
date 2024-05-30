#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_safe(int(*maze)[4],int n,int(*vis)[4],int r,int c){
	if(r<0 || r>=n || c<0 || c>=n){
		return false;
	}
	if(maze[r][c]==0){
		return false;
	}
	if(vis[r][c] == 1){
		return false;
	}
	return true;
}

void solve(int(*maze)[4],int(*vis)[4],int n,vector<string> &ans,string move,int r,int c){
	//Base case
	if(r == n-1 && c == n-1){
		ans.push_back(move);
		return;
	}
	vis[r][c] = 1;
	//D,L,R,U
	//Down
	if(is_safe(maze,n,vis,r+1,c)){
		move.push_back('D');
		solve(maze,vis,n,ans,move,r+1,c);
		move.pop_back();
	}
	//Left
	if(is_safe(maze,n,vis,r,c-1)){
		move.push_back('L');
		solve(maze,vis,n,ans,move,r,c-1);
		move.pop_back();
	}
	//Right
	if(is_safe(maze,n,vis,r,c+1)){
		move.push_back('R');
		solve(maze,vis,n,ans,move,r,c+1);
		move.pop_back();
	}
	//Up
	if(is_safe(maze,n,vis,r-1,c)){
		move.push_back('U');
		solve(maze,vis,n,ans,move,r-1,c);
		move.pop_back();
	}
	vis[r][c] = 0;
				
}


int main(){
	int n = 4;
	int maze[4][4] = {{1,0,0,0},
					  {1,1,0,0},
					  {1,1,0,0},
					  {0,1,1,1}};
	int vis[4][4] = {0};
	vector<string>ans;
	int row = 0;
	string move = "";
	int col = 0;
	solve(maze,vis,n,ans,move,row,col);
	for(int i = 0; i<ans.size() ; i++){
		cout<<ans[i]<<"   ";
	}
return 0;
}

















