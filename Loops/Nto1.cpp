#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    // N -> 1
    for(int i = n;i>0;i--){
        cout<<i<<" ";
    }
    cout<<endl;
    // 1 -> N
     for(int i = n;i>0;i--){
        cout<<n+1-i<<" ";
    }
}