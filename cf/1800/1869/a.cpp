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
    int xo = 0;
    for (auto &i : a) {
        xo ^= i;
    }
    for (auto &i : a) {
        i = xo;
    }
    vector<PII> ans;
    ans.push_back({1, n});
    if (xo) {
        if (n % 2) {
            ans.push_back({2, n});
            ans.push_back({1, 2});
            ans.push_back({1, 2});
        } else {
            ans.push_back({1, n});
        }
    }
    cout << ans.size() << endl;
    for (auto [i, j] : ans) {
        cout << i << ' ' << j << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}