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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    if (a[0] > 1) {
        cout << 1 << endl;
        return;
    }
    LL sum = 0;
    vector<LL> b;
    vector<int> c;
    for (int i = 1; i < n; ++i) {
        sum += a[i] - a[i - 1] - 1;
        if (sum) {
            if (b.empty() || b.back() != sum) {
                b.push_back(sum);
                c.push_back(i);
            }
        }
    }
    b.push_back(sum + 1);
    c.push_back(n);

    // for (int i = 0; i < b.size(); ++i) {
    //     cout << b[i] << ' ' << c[i] << endl;
    // }
    // cout << endl;

    LL ans = 1;
    for (int i = 1; i <= k; ++i) {
        auto p = lower_bound(b.begin(), b.end(), ans);
        if (p == b.end()) {
            --p;
        }
        // db(*p);
        // db(p-b.begin());
        // db(c[p-b.begin()]);
        ans += c[p - b.begin()];
        // ans += *p - 1;
        // db(ans);
        // cout << endl;
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}