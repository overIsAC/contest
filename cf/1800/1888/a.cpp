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
    string s;
    cin >> n >> k;
    cin >> s;
    map<char, int> mp;
    for (auto &i : s) {
        ++mp[i];
    }

    int cnt = 0;
    for (auto &[x, y] : mp) {
        cnt += y % 2;
    }
    n = n - cnt;
    if (cnt > 1) {
        if (k < cnt - 1) {
            cout << "NO" << endl;
            return;
        }
        k -= cnt - 1;
        cnt = 1;
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