#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>& arr){
       // int n = sizeof(arr)/4;
       int n = arr.size();
    for(int i = 0; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
vector<int> arr= {3,4,55,67,86,54,3};
    // sorting array
    // Bubble sort
    int n = arr.size();
    print(arr);
    for(int i = 0;i<n;i++){
        if(arr[i] > arr[i+1]) swap(arr[i],arr[i+1]);
    }
      print(arr);
}