#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

int main() {
    int a, b;
    cin >> a >> b;
    int ok = 0;
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            for (int k = 1; k <= 6; ++k) {
                int u = 0, v = 0;
                if (i == 1 || i == 4) {
                    u += i;
                } else {
                    v += i;
                }
                if (j == 1 || j == 4) {
                    u += j;
                } else {
                    v += j;
                }
                if (k == 1 || k == 4) {
                    u += k;
                } else {
                    v += k;
                }
                // cout << i << ' ' << j << ' ' << k << ' ' << u << ' ' << v << endl;
                if (u == a && v == b) {
                    ok = 1;
                }
            }
        }
    }
    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}