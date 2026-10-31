#include<iostream>
using namespace std;
void aiman(){
    cout<<"aiamn"<<endl;
}
void ameer(){
    aiman();
    cout<<"ameer"<<endl;
    aiman();
}
void hafeez(){
    aiman();
    cout<<"hafeez"<<endl;
    ameer();
}
int main(){
    hafeez();
    ameer();
    aiman();
}