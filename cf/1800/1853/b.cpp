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

vector<int> f = {1, 1};

void solve() {
    int n, k;
    cin >> n >> k;
    if (k > f.size()) {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    for (LL i = 0; i * f[k - 2] <= n - f[k - 3] * i; ++i) {
        // cout << i << ' ' << f[k - 2] << ' ' << f[k - 3] << endl;
        if ((n - f[k - 3] * i) % f[k - 2] == 0) {
            ++ans;
        }
    }
    cout << ans << endl;
}

int main() {
    while (f.back() <= 1e9) {
        int a = f[f.size() - 2], b = f.back();
        f.push_back(a + b);
    }
    // for (auto &i : f) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}