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

int query(int u, int v, int w) {
    cout << "? " << u << ' ' << v << ' ' << w << endl;
    cin >> u;
    return u;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int u = 1, v = 2, w = 3;
        int mx = query(u, v, w);
        for (int i = 4; i <= n; ++i) {
            int c1 = query(u, v, i), c2 = query(u, w, i);
            if (c1 >= max(c2, mx)) {
                w = i;
                mx = c1;
                continue;
            }
            if (c2 >= max(c1, mx)) {
                v = i;
                mx = c2;
                continue;
            }
        }
        int p = 1;
        // cout << u << ' ' << v << ' ' << w << endl;
        while (p == u || p == v || p == w) {
            ++p;
        }
        if (mx == query(u, v, p)) {
            cout << "! " << u << ' ' << v << endl;
            continue;
        }
        if (mx == query(u, w, p)) {
            cout << "! " << u << ' ' << w << endl;
            continue;
        }
        if (mx == query(w, v, p)) {
            cout << "! " << w << ' ' << v << endl;
            continue;
        }
        assert(false);
    }
    return 0;
}