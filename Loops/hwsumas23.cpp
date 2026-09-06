#include<iostream>
using namespace std;
int main(){
    for(int i = 1;i<=1000;i++){
         int count = 0;
          int temp = i;
    while(temp != 0){
       
       count += (temp%10);
       temp /= 10;
    }
    // cout<< count;
    if(count == 23) break;
    else cout<<i<<" ";
    }
}