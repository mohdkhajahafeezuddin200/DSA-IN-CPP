#include<iostream>
using namespace std;
int power(int a,int b){
   if(b == 1) return a;
   int ans = a * power(a,b-1);
   return ans;
}  // T.C = O(b)
int main(){
    int a,b;
    cin>>a>>b;
   cout<< power(a,b);
}