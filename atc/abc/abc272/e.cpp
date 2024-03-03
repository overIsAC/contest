#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, m, a[N];
set<PII> st[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        int v = -a[i] / i;
        v = max(1, v);
        if (v <= m && a[i] + (LL)i * v <= n + 1) {
            st[v].insert({a[i] + i * v, i});
        }
    }
    for (int i = 1; i <= m; ++i) {
        int c = 0;
        for (auto& j : st[i - 1]) {
            if (j.first + j.second <= n + 1) {
                st[i].insert({j.first + j.second, j.second});
            } else {
                c += 1;
            }
        }
        int p = 0;
        auto it = st[i].lower_bound({p, 0});
        while (it != st[i].end() && it->first == p) {
            p += 1;
            it = st[i].lower_bound({p, 0});
        }
        n -= c;
        cout << p << endl;
    }

    return 0;
}