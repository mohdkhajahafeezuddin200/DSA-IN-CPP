#include<iostream>
using namespace std;
int main(){
    // method-1
    for(int i = 1;i<100;i+=2){
        if(i%3 == 0) cout<<i<<" ";
    }
    cout<<endl;
    // method-2
     for(int i = 1;i<100;i++){
        if(i%3 == 0 and i%2 == 1) cout<<i<<" ";
    }
    // 3 9 15 21 27 33 39 45 51 57 63 69 75 81 87 93 99 
}