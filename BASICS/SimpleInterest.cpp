#include<iostream>
using namespace std;
int main(){
    int p,r,t;
    cout << "Enter principal rate and time values: \n";
    cin>>p>>r>>t;
    float s = (p*r*t)/100;
    cout<<s<<endl;
}