#include<iostream>
#include<cmath>
using namespace std;
int main(){
    // printing facetors of no.
    // method-1
    // int n;
    // cin>>n;
    // for(int i =1 ;i<=n;i++){
    //     if(n%i == 0 ) cout<<i<<" ";
    // }
    // method-2 efficient
     int n;
    cin>>n;
    for(int i =1 ;i<=sqrt(n);i++){
        if(n%i == 0 ) cout<<i<<" "<<(n/i)<<" ";
    }
}