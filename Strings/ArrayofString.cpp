#include<iostream>
#include<climits>
#include<string>
using namespace std;
int main(){
    string arr[] = {"978","00867","3736","470"};
    int a[4];
    for(int i=0;i<4;i++){
        a[i] = stoi(arr[i]);
    }
    int mx = INT_MIN;
    for(int i=0;i<4;i++){
        if(a[i] > mx) mx = a[i];
    }
    cout<<mx<<endl;
}