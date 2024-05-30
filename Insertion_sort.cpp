  #include <iostream>
  #include <string>
  
  using namespace std;
  // Insertion sort - Card wali example
  int main() {
    int temp,i,j,k;
    int n=6;
    int arr[n]={5,1,2,7,4,3};
    cout<<"Before insertion sort\n";
    for(i=0;i<n;i++){
      cout<<arr[i]<<"\t";
    }       
    cout<<endl;
    
    // for(i=0;i<n;i++){
    //   temp=arr[i];
    //   for(j=i-1;j>=0;j--){
    //     if(temp>arr[j]){
    //       //Do nothing cause already sorted
    //       break;
    //     } 
    //     else{
    //       arr[j+1]=arr[j];
    //     }
    //   }
    //   arr[j+1]=temp;
    // }
  i=1;
while(i<n){
  temp=arr[i];
  j=i-1;
  while(j>=0){
    if(temp<arr[j]){
      arr[j+1]=arr[j];
    }
    else{
      break;
    }
    j--;
  }
  arr[j+1]=temp;
  i++;
}

























     cout<<"After insertion sort\n";
    for(i=0;i<n;i++){
      cout<<arr[i]<<"\t";
    }       
    cout<<endl;

      return 0;
  }  