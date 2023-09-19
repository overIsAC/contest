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
const int N = 3 + 2e5;

int n, q;
int a[N], pre[N];
int preZero[N];
map<int, vector<int>> mp[2];

#define endl "\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
        preZero[i] = preZero[i - 1] + !a[i];
        mp[i & 1][pre[i]].push_back(i);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (pre[r] ^ pre[l - 1]) {
            cout << -1 << endl;
            continue;
        }
        if (preZero[r] - preZero[l - 1] == r - l + 1) {
            cout << 0 << endl;
            continue;
        }
        if (r - l + 1 & 1) {
            cout << 1 << endl;
            continue;
        }
        if (a[l] == 0 || a[r] == 0) {
            cout << 1 << endl;
            continue;
        }
        auto &ve = mp[l & 1][pre[l - 1]];
        auto p = lower_bound(ve.begin(), ve.end(), l);
        if (p == ve.end() || *p > r) {
            cout << -1 << endl;
            continue;
        }
        cout << 2 << endl;
    }
    return 0;
}