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
const int N = 3 + 3000;

int n, m;

int vis[N], cnt[N], d[N];
vector<PII> edge[N];
int fa[N], dis[N];

int find(int p) {
    if (fa[p] != p) {
        int q = find(fa[p]);
        d[p] += d[fa[p]];
        fa[p] = q;
    }
    return fa[p];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        fa[i] = i;
    }
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        if ((r - l + 1) % 2 != abs(x) % 2) {
            cout << "?" << endl;
            return 0;
        }
        if (abs(r - l + 1) < x) {
            cout << "?" << endl;
            return 0;
        }
        int u = find(l - 1), v = find(r);
        if (u == v) {
            if (d[r] - d[l - 1] != x) {
                cout << "?" << endl;
                return 0;
            }
            continue; 
        }
        d[v] = x - (d[r] - d[l - 1]);
        fa[v] = u;
        edge[l - 1].push_back({r, x});
        edge[r].push_back({l - 1, -x});
    }
    for (int i = 1; i <= n; ++i) {
        edge[i - 1].push_back({i, 1});
        edge[i].push_back({i - 1, 1});
        edge[i].push_back({0, 0});
    }
    edge[0].push_back({n, 0});

    memset(d, 0x3f, sizeof(d));
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while (q.size()) {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (auto [y, w] : edge[x]) {
            if (d[y] > d[x] + w) {
                d[y] = d[x] + w;
                cnt[y] = cnt[x] + 1;
                if (cnt[y] > n) {
                    cout << "?" << endl;
                    return 0;
                }
                if (!vis[y]) {
                    vis[y] = 1;
                    q.push(y);
                }
            }
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; ++i) {
        if (d[i] - d[i - 1] > 0) {
            cout << "(";
        } else {
            cout << ")";
        }
    }
    return 0;
}