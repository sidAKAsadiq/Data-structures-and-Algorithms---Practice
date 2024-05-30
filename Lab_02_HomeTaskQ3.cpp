#include <iostream>
#include <climits>
#include <string>

using namespace std;

class data{
public:
int day;
int month;
int year;
data(){};
data(int y,int m,int d){
    day = d;
    month = m;
    year = y;
}
void re_initialize(){
    day = INT_MIN;
    month = INT_MIN;
    year = INT_MIN;
}
};

void selection_sort(data* array_of_dates, int n){
    //Implementing Selection sort
    int index_to_be_swapped;
    int index_to_hold_maximum_value;
    data maximum_value (INT_MIN,INT_MIN,INT_MIN);

    for(int i=0 ; i<n-1 ; i++){
        index_to_hold_maximum_value = i;
        for(int j=i;j<n;j++){
            if((array_of_dates[j].year>maximum_value.year) || (array_of_dates[j].year==maximum_value.year && array_of_dates[j].month>maximum_value.month) || (array_of_dates[j].year==maximum_value.year && array_of_dates[j].month==maximum_value.month && array_of_dates[j].day>maximum_value.day) ){
                index_to_be_swapped = j;
                maximum_value = array_of_dates[j];
            }
        }
        swap(array_of_dates[index_to_be_swapped],array_of_dates[index_to_hold_maximum_value]);
        maximum_value.re_initialize();
    } 
}

int main() {
    data d1(2020,12,31);
    data d2(2021,1,1);
    data d3(1999,10,1);
    data d4(2003,12,10);
    data d5(2003,11,10);
    data d6(2002,5,1);
    data d7(2023,9,30);
    int n = 7;
    data* array_of_dates = new data[n] {d1,d2,d3,d4,d5,d6,d7};
    cout<<"Before selection sort (YYYY / MM / DD): \n";
    for(int i=0;i<n;i++){
        cout<<array_of_dates[i].year<<" / "<<array_of_dates[i].month<<" / "<<array_of_dates[i].day<<endl;
    }

        selection_sort(array_of_dates,n);

        cout<<"After selection sort (YYYY / MM / DD) : \n";
        for(int i=0;i<n;i++){
        cout<<array_of_dates[i].year<<" / "<<array_of_dates[i].month<<" / "<<array_of_dates[i].day<<endl;
    }

    return 0;
}