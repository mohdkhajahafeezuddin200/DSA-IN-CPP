#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if(a < b){
       for(int i = a+1;i<b;i++){
        if(i %2 == 0) cout<<i<<" ";
       }
    }
    else{ // a > b
        swap(a,b);
        for(int i = a+1;i<b;i++){
            if(i %2 == 0) cout<<i<<" ";
       }
    }
}