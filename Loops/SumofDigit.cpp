#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count = 0;
    if(n < 0) n *= -1;
    while(n != 0){
       count += (n%10);
       n /= 10;
    }
    cout<< count;
}