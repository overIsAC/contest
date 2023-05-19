#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        if (a ^ b) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }
    return 0;
}