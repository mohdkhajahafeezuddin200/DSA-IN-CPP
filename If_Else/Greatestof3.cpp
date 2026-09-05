#include<iostream>
using namespace std;
int main(){
//         //Ques: Take 3 positive integers input and
// print the greatest of them.
    int a,b,c;
    cin>>a>>b>>c;
    if( a>b and a>c) cout<<a<<"  is the biggest";
    else if(b>c and b>a)  cout<<b<<"  is the biggest";
    else  cout<<c<<"  is the biggest";
}
