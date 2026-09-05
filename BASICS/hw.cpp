#include<iostream>
using namespace std;
int main(){
//     Take length and breadth of
// rectangle as input and write a program
// to find whether the area of rectangle is
// greater than its perimeter.

    int l,b;
    cout<<"enter length and breath: ";
    cin>>l>>b;
    int a = l*b;
    int p = 2*(l+b);
    if(a > p) cout<<"Area is > Perimeter";
    else cout<<"Area is < Perimeter";
}