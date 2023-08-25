#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, k;
string s;
LL ans, ok;

void dfs(int p, int limit, LL v, set<int> st) {
    if (ok || st.size() > k) {
        return;
    }
    if (p == s.size()) {
        ans = v;
        ok = 1;
        return;
    }
    int down = limit ? s[p] - '0' : 0;
    for (int i = down; i <= 9; ++i) {
        auto ss = st;
        ss.insert(i);
        dfs(p + 1, limit && down == i, v * 10 + i, ss);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        s = to_string(n);
        ok = 0;
        ans = 1e10 - 1;
        dfs(0, 1, 0, {});
        cout << ans << endl;
    }
    return 0;
}