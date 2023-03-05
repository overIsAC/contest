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

int n, a[N], m;
int u[N], v[N];
vector<int> edge[N];
LL k;
int du[N];
int d[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i];
    }

    auto ok = [&](int o) -> bool {
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
            du[i] = 0;
            d[i] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            if (a[u[i]] > o || a[v[i]] > o) {
                continue;
            }
            edge[u[i]].push_back(v[i]);
            ++du[v[i]];
        }
        int t = n;
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (a[i] > o) {
                --t;
                continue;
            }
            if (!du[i]) {
                d[i] = 1;
                q.push(i);
            }
        }
        while (q.size()) {
            auto x = q.front();
            q.pop();
            --t;
            if (d[x] >= k) {
                return true;
            }
            for (auto &y : edge[x]) {
                d[y] = max(d[x] + 1, d[y]);
                if (!--du[y]) {
                    q.push(y);
                }
            }
        }
        return t;
    };

    int l = 1, r = 1e9;
    while (l < r) {
        int mid = l + r >> 1;
        if (ok(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (ok(r)) {
        cout << r << endl;
    } else {
        cout << -1 << endl; 
    }

    return 0;
}