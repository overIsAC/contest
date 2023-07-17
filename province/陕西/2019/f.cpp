#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int mod = 7 + 1e9;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x + y < z) {
            cout << -1 << endl;
        } else {
            if (x + y == z) {
                cout << 2000000000 << endl;
            } else {
                if (x + y - z > x && x + y - z > z) {
                    cout << x + y - z << endl;
                } else {
                    cout << -1 << endl;
                }
            }
        }
    }
    return 0;
}