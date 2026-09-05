#include<iostream>
using namespace std;
int main(){
    // quadrant ?
    float x,y;
    cin>>x>>y;
    if(x == 0 and y == 0) cout<<"Origin";
    else if(x > 0 and y>0) cout << "1st Quadrant";
    else if(x < 0 and y>0) cout << "2nd Quadrant";
    else if(x > 0 and y<0) cout << "4th Quadrant";
    else if(x < 0 and y<0) cout << "3rd Quadrant";
    else{
    if(x == 0){
        if(y > 0) cout << "point lies on +y-axis";
        else cout << "point lies on -y-axis";
    }

    if(y == 0) {
        if(x <0) cout << "point lies on -x-axis";
       else cout << "point lies on +x-axis";
    }
    }
}