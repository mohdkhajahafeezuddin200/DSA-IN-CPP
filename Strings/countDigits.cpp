#include<iostream>
#include<string>
using namespace std;
int main(){
    // count digits
    int n;
    cin>>n;
    string s = "";
    if(n < 0) n *= -1;
        s = to_string(n);
    int c = s.length();
    cout<<c<<endl;
}