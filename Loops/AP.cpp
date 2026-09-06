#include<iostream>
using namespace std;
int main(){
    // best method
    int a,n,d;
    cout<<"enter 1st term,no.of terms, common diff: ";
    cin>>a>>n>>d;
    for(int i=1;i<=n;i ++){
        cout<<a<<" ";
        a += d;
    }
}