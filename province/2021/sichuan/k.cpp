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
    vector<int> ans;
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        if (mp[i]) {
            continue;
        }
        for (int j = i; j <= n; j += k) {
            mp[j] = 1;
            ans.push_back(j);
        }
    }
    for (auto& i : ans) {
        cout << i << ' ';
    }
}

int main() {
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}