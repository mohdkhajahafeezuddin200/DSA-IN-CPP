#include <iostream>
using namespace std;
int main(){
    // modulus operator
    // used to find remainder
    int a = 5,b = 2;
    int c = a%b;
    cout<<c;

    // PROPERTIES:
    // 1. a % b == a (if a<b)
    // 2. a % (-b) == a % b
    // 3. (-a) % b == -(a%b)
}
