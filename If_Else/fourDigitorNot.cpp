#include<iostream>
using namespace std;
int main(){
    // given number is 4 digit or not
    int n;
    cin >> n;
    if(n >= 1000 and n<=9999) cout << "FOUR DIGIT NUMBER";
    else  cout << " NOT A FOUR DIGIT NUMBER";
}

