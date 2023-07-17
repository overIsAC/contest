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

void solve(int n, vector<int> &a) {
    if (a[0] == 0) {
        cout << "YES" << endl;
        return;
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            cout << "YES" << endl;
            return;
        }
    }
    vector<int> vis(n);
    function<int(int, int)> dfs = [&](int p, int sum) {
        if (p == n) {
            for (int i = 0; i < n; ++i) {
                if (vis[i]) {
                    continue;
                }
                if (sum == a[i]) {
                    return 1;
                }
            }
            return 0;
        }
        if (dfs(p + 1, sum)) {
            return 1;
        }
        vis[p] = 1;
        if (dfs(p + 1, sum - a[p])) {
            return 1;
        }
        if (dfs(p + 1, sum + a[p])) {
            return 1;
        }
        vis[p] = 0;
        return 0;
    };

    if (dfs(0, 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }
        sort(a.begin(), a.end());
        solve(n, a);
    }
    return 0;
}