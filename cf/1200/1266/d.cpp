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
const int N = 3 + 3e5;

int n, m;
LL d[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u] += w;
        d[v] -= w;
    }
    vector<tuple<int, LL>> ve;
    for (int i = 1; i <= n; ++i) {
        if (d[i]) {
            ve.push_back({i, d[i]});
        }
    }
    sort(ve.begin(), ve.end(), [](tuple<int, LL> a, tuple<int, LL> b) {
        auto [x1, y1] = a;
        auto [x2, y2] = b;
        return y1 < y2;
    });
    vector<tuple<int, int, LL>> ans;
    for (int i = 0, j = (int)ve.size() - 1; i < j;) {
        auto &[x1, y1] = ve[i];
        auto &[x2, y2] = ve[j];
        LL t = min(-y1, y2);
        y1 += t;
        y2 -= t;
        if (!y1) {
            ++i;
        }
        if (!y2) {
            --j;
        }
        ans.push_back({x1, x2, t});
    }
    cout << ans.size() << endl;
    for (auto &[x, y, w] : ans) {
        cout << y << ' ' << x << ' ' << w << endl;
    }
    return 0;
}