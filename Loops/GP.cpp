#include<iostream>
using namespace std;
int main(){
    // best method
    int a,n,r;
    cout<<"enter 1st term,no.of terms, common ratio: ";
    cin>>a>>n>>r;
    for(int i=1;i<=n;i ++){
        cout<<a<<" ";
        a *= r;
    }
}