#include<iostream>
#include<cmath>
using namespace std;
int main(){
     int n;
    cin>>n;
    bool flag = false; // false means prime
    for(int i = 2;i<n;i++){ // 2 to n-1 loop chalega
        if(n%i == 0 ){
            flag = true;
            break;
        }
    }
    if(flag == false) cout<<"prime number";
    else cout<<"composite number";
}