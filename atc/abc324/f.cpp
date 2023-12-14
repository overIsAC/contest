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
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, m;
vector<array<int, 3>> edge[N];
double d[N];
int du[N], dd[N];

int ok(double z) {
    for (int i = 1; i <= n; ++i) {
        d[i] = -1e9;
        du[i] = dd[i];
    }
    d[1] = 0;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!du[i]) {
            q.push(i);
        }
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto [y, b, c] : edge[x]) {
            if (!--du[y]) {
                q.push(y);
            }
            if (d[y] < d[x] + b - z * c) {
                d[y] = d[x] + b - z * c;
            }
        }
    }
    return d[n] >= 0;
}

int main() {
    cin >> n >> m;

    while (m--) {
        int u, v, b, c;
        cin >> u >> v >> b >> c;
        edge[u].push_back({v, b, c});
        ++dd[v];
    }

    double l = 0, r = 1e9;
    while (r - l > 1e-11) {
        double mid = (l + r) / 2;
        if (ok(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(11) << r << endl;

    return 0;
}