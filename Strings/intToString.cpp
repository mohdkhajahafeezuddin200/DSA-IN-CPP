#include<iostream>
#include<string>
using namespace std;
int main(){
    // int to string
    int n;
    cin>>n;
    string s = "";
    if(n < 0) n *= -1;
    // while(n != 0){
    //     int last = (n%10);
    //     char ch = last + 48;
    //     s.push_back(ch);
    //     n /= 10;
    // }
    // // reverse 
    // int i=0,j=s.size() - 1;
    // while(i < j){
    //     swap(s[i],s[j]);
    //     i++;
    //     j--;
    // }
    // cout<<s<<endl;

    // buit in function  => to_string(n)
   // s = to_string(n); // O(n) == TC 'n' no. of digits
    //cout<<s<<endl;

    // return digits without using loop
    s = to_string(n);
    int c = s.length();
    cout<<c<<endl;
}