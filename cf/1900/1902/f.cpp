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

struct LinearBasic {
    vector<int> a;
    LinearBasic() : a(20) {}
    void insert(int v) {
        for (int i = 19; i >= 0; --i) {
            if (v >> i & 1) {
                if (!a[i]) {
                    a[i] = v;
                    break;
                }
                v ^= a[i];
            }
        }
    }
    void insert(LinearBasic& other) {
        for (auto& i : other.a) {
            insert(i);
        }
    }
};

int n, a[N];
vector<int> edge[N];
int ne[20][N];
int d[N];
int f[20][N];

void dfs(int x, int fa) {
    d[x] = d[fa] + 1;

    for (int i = 0; i < 20; ++i) {
        ne[i][x] = ne[i][fa];
    }

    for (int i = 0; i < 20; ++i) {
        if (a[x] >> i & 1) {
            ne[i][x] = x;
        }
    }

    f[0][x] = fa;
    for (int i = 1; i < 20; ++i) {
        f[i][x] = f[i - 1][f[i][x]];
    }

    for (auto& y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x);
    }
}

int lca(int x, int y) {
    if (d[x] > d[y]) {
        swap(x, y);
    }
    for (int i = 19; i >= 0; --i) {
        if (d[f[i][y]] >= d[x]) {
            y = f[i][y];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = 19; i >= 0; --i) {
        if (f[i][x] != f[i][y]) {
            x = f[i][x];
            y = f[i][y];
        }
    }
    return f[0][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0);

    int q;
    cin >> q;
    while (q--) {
        int x, y, k;
        cin >> x >> y >> k;

        int g = lca(x, y);

        LinearBasic lb;
        lb.insert(a[g]);
        lb.insert(a[x]);
        lb.insert(a[y]);
        int z = a[x] | a[y] | a[g];

        while (true) {
            int p = 0;
            for (int i = 0; i < 20; ++i) {
                if (z < (a[ne[i][x]] | z) && d[ne[i][x]] >= d[g]) {
                    if (d[p] < d[ne[i][x]]) {
                        p = ne[i][x];
                    }
                }
            }
            if (!p) {
                break;
            }
            z |= a[p];
            lb.insert(a[p]);
            x = f[0][p];
        }

        swap(x, y);
        while (true) {
            int p = 0;
            for (int i = 0; i < 20; ++i) {
                if (z < (a[ne[i][x]] | z) && d[ne[i][x]] >= d[g]) {
                    if (d[p] < d[ne[i][x]]) {
                        p = ne[i][x];
                    }
                }
            }
            if (!p) {
                break;
            }
            z |= a[p];
            lb.insert(a[p]);
            x = f[0][p];
        }

        for (int i = 19; i >= 0 && k; --i) {
            if (k >> i & 1) {
                k ^= lb.a[i];
            }
        }
        if (!k) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

/*
4
0 1 2 10
2 1
3 2
4 2
8
3 4 1
*/