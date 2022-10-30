#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        if (n <= 2) {
            cout << "YES" << endl;
            continue;
        }
        int t = 0;
        bool ok = true;
        for (int i = 2; i < n; ++i) {
            if (a[i] < t) {
                ok = false;
                break;
            }
            a[i] -= t;
            if (a[i] > a[i - 1]) {
                t += a[i] - a[i - 1];
                a[i] = a[i - 1];
            }
        }
        if (t > a[n]) {
            ok = false;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}