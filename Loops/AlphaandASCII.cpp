#include<iostream>
using namespace std;
int main(){
    // Capital letters
    for(int i  = 65;i<=90;i++){
        cout<<(char)i<<"="<<i<<"  "; // typecasting
    }
    cout<<endl;
     // Small letters
    for(int i  = 97;i<=122;i++){
        cout<<(char)i<<"="<<i<<"  "; // typecasting
    }
}