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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    auto check = [&](int p) {
        return p == (p & -p);
    };
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] > a[i + 1]) {
            if (!check(i + 1)) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}