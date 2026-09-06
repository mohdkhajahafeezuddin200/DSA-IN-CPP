#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a == 0 && b == 0)
        cout << "indeterminate form";
    else {
        int ans = 1;
        for (int i = 0; i < b; i++)
            ans *= a;
        cout << ans << endl;
    }
}
