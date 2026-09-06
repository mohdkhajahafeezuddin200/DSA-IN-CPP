#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int pro = 1;
    while(n != 0){
        pro *= (n%10);
        n /= 10;
    }
    cout<<pro<<endl;
}