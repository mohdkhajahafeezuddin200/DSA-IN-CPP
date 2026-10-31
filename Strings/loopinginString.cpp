#include<iostream>
#include<string>
using namespace std;
int main(){
    string s = "mohd hafeez";
    int n  = s.length();
    for(int i=0;i<n;i++){
        cout<<s[i];
    }
    cout<<endl;
    // for each loop
    for(char ch : s){
        cout<<ch;
    }
}