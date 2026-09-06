#include<iostream>
using namespace std;
int main(){
    // method-1
    // for(int i = 1;i<101;i++){ // 100 iteartions
    //     if(i%2 == 0) cout<<i<<" ";
    // }

    // method-2
    // for(int i = 2;i<=100;i += 2){ // 50 iterations
    //     cout<<i<<" ";
    // }

    // method-3
    for(int i = 1;i<51;i++){ // best one
        cout<<2*i<<" ";
    }
}