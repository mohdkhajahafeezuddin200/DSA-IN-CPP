#include<iostream>
using namespace std;
int main(){
    int m,n;
    cout<<"enter rows & cols: ";
    cin>>m>>n; // m=> rows n => cols
    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){ // i -> rows j -> cols
            cout<<"* ";
        }
        cout<<endl;
    }
}