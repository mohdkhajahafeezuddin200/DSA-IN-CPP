#include<iostream>
using namespace std;
int main(){
    int n,ori;
    cin>>n;
    ori = n;
    int rev = 0;
    while(n != 0){
        rev *= 10;
        rev += (n%10);
        n /= 10;
    }
    cout<<rev<<endl;
    cout<<ori+rev<<endl;
}