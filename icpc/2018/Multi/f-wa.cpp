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
const int N = 3 + 202;

int n, q;
PII a[N];
int b[N];
int d[N][N];

/*
1
3 6
1 2 3

0 1 3
1 0 1
3 1 0

1 1 1
1 2 1
1 3 1
1 1 2
1 2 2
1 3 2

*/

void solve(int T) {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
        b[i] = a[i].first;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> d[i][j];
        }
    }
    sort(a + 1, a + n + 1);
    vector<array<int, 4>> ve(q);
    vector<int> ans(q);
    int p = 0;
    for (auto &[u, v, w, id] : ve) {
        cin >> u >> v >> w;
        id = p++;
    }
    sort(ve.begin(), ve.end(), [](array<int, 4> &u, array<int, 4> &v) {
        return u[2] < v[2];
    });

    auto update = [&](int k, int w) {
        for (int i = 1; i <= n; ++i) {
            if (b[i] > w) {
                continue;
            }
            for (int j = i + 1; j <= n; ++j) {
                if (b[j] > w) {
                    continue;
                }
                d[j][i] = d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    };

    p = 1;

    for (auto &[u, v, w, id] : ve) {
        while (p <= n && a[p].first <= w) {
            update(a[p].second, w);
            ++p;
        }
        int z = d[u][v];
        for (int i = 1; i <= n; ++i) {
            if (b[i] > w) {
                continue;
            }
            for (int j = i + 1; j <= n; ++j) {
                if (b[j] > w) {
                    continue;
                }
                z = min(z, d[u][i] + d[i][j] + d[j][v]);
                z = min(z, d[u][j] + d[j][i] + d[i][u]);
            }
        }
        ans[id] = z;
    }
    cout << "Case #" << T << ":\n";
    for (auto &i : ans) {
        cout << i << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        solve(i);
    }
    return 0;
}
