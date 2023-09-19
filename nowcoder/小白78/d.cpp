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

LL n;
set<LL> st;
map<LL, int> mp;

LL dfs(LL n) {
    if (n <= 1) {
        return n;
    }
    if (mp.count(n)) {
        return mp[n];
    }
    auto p = st.upper_bound(n);
    --p;
    return mp[n] = dfs(*p) + dfs()
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (LL i = 1; i <= 2e18; i = 2 * i + 1) {
        st.insert(i);
    }
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << dfs(n) << endl;
    }
    return 0;
}