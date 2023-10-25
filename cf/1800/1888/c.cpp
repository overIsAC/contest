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
int L[N], R[N];
int pre[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    map<int, int> mp;

    for (int i = 1; i <= n; ++i) {
        L[i] = mp[a[i]];
        mp[a[i]] = 1;
    }

    mp.clear();

    for (int i = n;i >= 1; --i) {
        R[i] = mp[a[i]];
        mp[a[i]] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1];
        if (!L[i]) {
            ++pre[i];
        }
    }

    LL ans = 0;
    for (int i = n; i >= 1; --i) {
        if (R[i]) {
            continue;
        }
        ans += pre[i];
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