#include<iostream>
using namespace std;
int main(){
    // factorial of number
    int n;
    cin>>n;
    // while(n >=1){

    // }
   if(n > 0) {int fact = 1;
        for(int i = n;i>=1;i--){
            fact *= i;
        }
        cout<<fact;
    }
    else cout<<"invalid";
}