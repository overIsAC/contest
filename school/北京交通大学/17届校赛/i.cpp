#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N];

void solve() {
    map<int, int> m1, m2;
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j * j <= a[i]; ++j) {
            while (a[i] % j == 0) {
                ++m1[j];
                a[i] /= j;
            }
        }
        if (a[i] > 1) {
            ++m1[a[i]];
        }
    }
    for (auto &i : m1) {
        int t = i.second + 1;
        for (int j = 2; j * j <= t; ++j) {
            while (t % j == 0) {
                ++m2[j];
                t /= j;
            }
        }
        if (t > 1) {
            ++m2[t];
        }
    }
    // cout << "**************" << endl;
    // for (auto &i : m1) {
    //     cout << i.first << ' ' << i.second << endl;
    // }
    // cout << "**************" << endl;
    // for (auto &i : m2) {
    //     cout << i.first << ' ' << i.second << endl;
    // }
    // cout << "**************" << endl;
    for (auto &i : m2) {
        if (m1[i.first] < i.second) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        solve();
    }
    return 0;
}