#include<iostream>
using namespace std;
int main(){
    cout<<"---GIVE SIDES OF TRIANGLE AS INPUT---";
    int a,b,c;
    cin >> a >> b >> c;
    if(a+b > c && b+c > a && a+c > b) cout<<"triangle can be formed";
    else cout<<"INVALID";
}