#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N];
int b[N], t;

void solve() {
    set<int> s;
    int q = 0, w = 0;
    for (int i = 1; i <= n; ++i) {
        s.insert(a[i]);
        if (a[i] < 0) {
            ++q;
        }
        if (a[i] > 0) {
            ++w;
        }
    }
    if (q >= 3 || w >= 3) {
        cout << "NO" << endl;
        return;
    }
    sort(a + 1, a + n + 1,
         [&](const int &a, const int &b) { return abs(a) > abs(b); });
    if (a[1] == a[n]) {
        cout << "YES" << endl;
        return;
    }
    while (n - 2 >= 1 && a[n] == 0 && a[n - 2] == 0) --n;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                if (!s.count(a[i] + a[j] + a[k])) {
                    cout << "NO" << endl;
                    return;
                }
            }
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