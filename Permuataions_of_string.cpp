#include <iostream>
#include <string>
#include <vector>
using namespace std;

void  find_paths(int n,int arr[][4],int your_x,int your_y,int final_x,int final_y,string output,vector <string>& answers){
   // Base case 
   if(your_x==final_x && your_y==final_y){
    answers.push_back(output);

    return;
   }

    // For down
    if(your_y+1<n && arr[your_x][your_y+1]!=0 ){
        arr[your_x][your_y]=0;
        output.push_back('D');
        your_y++;
        find_paths( n,arr ,your_x, your_y, final_x, final_y, output,answers);
                arr[your_x][your_y] = 1; // Restore the original value
        output.pop_back();
        cout<<"Down";
    } 
     // For Left
    if(your_x-1>=0 && arr[your_x-1][your_y]!=0 ){
        arr[your_x][your_y]=0;

        output.push_back('R');
        your_x--;
        find_paths( n,arr ,your_x, your_y, final_x, final_y, output,answers);
        arr[your_x][your_y] = 1; // Restore the original value
        output.pop_back();
        cout<<"left";
    } 
    // For Right
    if(your_x+1<n && arr[your_x+1][your_y]!=0 ){
        arr[your_x][your_y]=0;
 
        output.push_back('R');
        your_x++;
        find_paths( n,arr ,your_x, your_y, final_x, final_y, output,answers);
            arr[your_x][your_y] = 1; // Restore the original value
        output.pop_back();
        cout<<"Right";
    } 
    // For up
    if(your_y-1>= 0&& arr[your_x][your_y-1]!=0 ){
        arr[your_x][your_y]=0;

        output.push_back('U');
        your_y--;
        find_paths( n,arr ,your_x, your_y, final_x, final_y, output,answers);
                arr[your_x][your_y] = 1; // Restore the original value
        output.pop_back();
        cout<<"up";
    } 
   



}

int main() {
    int n = 4;
    int arr[4][4]={{1,0,0,0},
                   {1,1,0,1},
                   {1,1,0,0},
                   {0,1,1,1}
                   };
    int your_x = 0;
    int your_y = 0;
    int final_x = n - 1; //2-1 (1,1)
    int final_y = n - 1; //2-1 (1,1)
    string output; // iss may answers store hongy for each possible way
    vector <string> answers;
    find_paths( n,arr ,your_x, your_y, final_x, final_y, output,answers);
    for(int i = 0 ; i<answers.size() ; i++){
        cout<<answers[i]<<" ";
    }
    


    return 0;
}