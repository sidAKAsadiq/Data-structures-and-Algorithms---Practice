#include <iostream>
#include <string>

using namespace std;

bool all_spots_checked(int(*checked)[4]){
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(checked[i][j]==0){
                return false;
            }
        }
    }
    return true;
}

bool valid_move(int(*checked)[4],int row,int coloum){
    if(row<0 | row>2 | coloum<0 | coloum>3){
        return false;
    }
    if(checked[row][coloum] == 1){
        return false;
    }

    return true;
}

void call_free_spots(int(*parking)[4] , int(*checked)[4],int row,int coloum){
//Base case -> Rukjao!
if(all_spots_checked(checked)){
    return;
}
if(parking[row][coloum] == 2){
cout<<"Free spot at : "<<row<<","<<coloum<<endl;
}
checked[row][coloum] = 1;

if(valid_move(checked,row,coloum+1)){
    call_free_spots(parking,checked,row,coloum+1);
}
if(valid_move(checked,row,coloum-1)){
    call_free_spots(parking,checked,row,coloum-1);
}
if(valid_move(checked,row+1,coloum)){
    call_free_spots(parking,checked,row+1,coloum);
}
if(valid_move(checked,row-1,coloum)){
    call_free_spots(parking,checked,row-1,coloum);
}
}

int main() {
    int parking[3][4] = {{1,1,1,1},{1,1,1,2},{1,2,1,1}};
    cout<<"Parking lot : "<<endl;
        for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<parking[i][j]<<" ";
        }
        cout<<endl;
    }
    int checked[3][4] = {0};
    call_free_spots(parking,checked,0,0);
    return 0;
}