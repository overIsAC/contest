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

int n, m;
vector<PII> edge[N];
int du[N], d[N];

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        ++du[v];
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!du[i]) {
            q.push(i);
        }
    }

    memset(d, -0x3f, sizeof(d));

    // cout << d[0] << ' ' << -1e5 * 1500 << endl;

    d[1] = 0;

    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto& e : edge[x]) {
            int y = e.first, w = e.second;
            d[y] = max(d[y], d[x] + w);

            if (!--du[y]) {
                q.push(y);
            }
        }
    }
    int ans = d[n];
    if (ans < -1e9) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}