#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    vector<string> arr = {"464","5756","57856","00056"};
    int n = arr.size();
    string max = arr[0];
    for(int i=0;i<n;i++){
        if(stoi(arr[i]) > stoi(max)) max = arr[i];
    }
    cout<<max<<endl;
}