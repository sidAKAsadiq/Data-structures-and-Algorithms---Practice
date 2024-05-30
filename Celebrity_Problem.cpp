#include <iostream>
#include <string>

using namespace std;

int main() {
    int arr[3][3] =   {{0 ,1, 0},
                      {0, 0 ,0}, 
                      {0 ,1, 0}};
    int n = 3;
    bool celebrity_found = false;
    bool knows_no_one = true;
    bool everyone_knows = true;

    // for(int i = 0;i<3;i++){
    //     for(int j =0;j<3;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0 ; i<n ; i++){
        knows_no_one = true;
      //Knows no one wali condition
            for(int j=0 ; j<n ; j++){
                if(j==i){
                    continue;
                }
                else if(arr[i][j] == 1 ){
                    knows_no_one = false;
                    cout<<"Setting knows no one false for : "<<i<<endl;
                }
            }
            //Everyone knows wali condition
            if(knows_no_one){
            for(int j=0 ; j<n ;j++){
                if(j==i){
                    continue;
                }
                else if(arr[j][i] == 0){
                    everyone_knows = false;
                    cout<<"Setting knows everyone false for : "<<i<<endl;

                }
            }
            if(everyone_knows){
                cout<<"i: "<<i<<endl;
                return 0 ;
            }
            everyone_knows = true;  
            }





     }
    

    
    return 0;
}