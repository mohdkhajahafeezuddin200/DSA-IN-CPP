#include<iostream>
using namespace std;
int main(){
   int a = 99,d = -4;
   for(int i = 1;i<100;i++){
        if(a > 0){
            cout<<a<<" ";
            a += d;
        }
        else break;
   }
}