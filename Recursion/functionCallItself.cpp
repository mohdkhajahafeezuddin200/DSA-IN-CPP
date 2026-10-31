#include<iostream>
using namespace std;
// void ameer(){
//     cout<<"Ameer"<<endl;
//     ameer(); // infinite function calling
// }

void ameer(int n){
    if(n == 0) return; // base case
    cout<<"Ameer"<<endl; // work
    ameer(n-1); // calling
}
int main(){
    ameer(4);
}