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

int n;
vector<int> edge[N];
int d[N];
int w[N];

struct Node {
    int sum, lmax, rmax, max, lmin, rmin, min;
    void set(int x) {
        sum = lmax = rmax = max = lmin = rmin = min = x;
        if (min > 0) {
            min = 0;
        }
        if (max < 0) {
            max = 0;
        }
    }
    void reverse() {
        swap(lmax, rmax);
        swap(lmin, rmin);
    }
    void print() {
       // cout << sum << ' ' << lmax << ' ' << rmax << ' ' << max << ' ' << lmin << ' ' << rmin << ' ' << min << endl;
    }
} t[N][20];

int f[N][20];

Node operator+(Node &a, Node &b) {
    int sum = a.sum + b.sum;
    int lmax = max(a.lmax, a.sum + b.lmax);
    int rmax = max(a.rmax + b.sum, b.rmax);
    int _max = max({a.max, b.max, a.rmax + b.lmax});
    int lmin = min(a.lmin, a.sum + b.lmin);
    int rmin = min(a.rmin + b.sum, b.rmin);
    int _min = min({a.min, b.min, a.rmin + b.lmin});
    return {sum, lmax, rmax, _max, lmin, rmin, _min};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
        }
        d[1] = 1;
        w[1] = 1;
        int id = 1;
        for (int i = 1; i <= n; ++i) {
            char op;
            int u, v, x, k;
            cin >> op;
            if (op == '+') {
                cin >> v >> x;
                u = ++id;
                f[u][0] = v;
                t[u][0].set(w[v]);
                w[u] = x;
                d[u] = d[v] + 1;
                for (int i = 1; i < 20; ++i) {
                    f[u][i] = f[f[u][i - 1]][i - 1];
                    t[u][i] = t[u][i - 1] + t[f[u][i - 1]][i - 1];
                }
            } else {
                cin >> u >> v >> k;
                if (d[u] < d[v]) {
                    swap(u, v);
                }
                Node x, y;
                x.set(w[u]);
                y.set(w[v]);
                x.print();
                for (int i = 19; i >= 0; --i) {
                    if (d[f[u][i]] >= d[v]) {
                        x = x + t[u][i];
                        u = f[u][i];
                    }
                }
                if (u == v) {
                    db("?");
                    x.print();
                    if (x.min <= k && k <= x.max) {
                        cout << "Yes" << endl;
                    } else {
                        cout << "No" << endl;
                    }
                    continue;
                }
                for (int i = 19; i >= 0; --i) {
                    if (f[u][i] != f[v][i]) {
                        x = x + t[u][i];
                        y = y + t[v][i];
                        u = f[u][i];
                        v = f[v][i];
                    }
                }
                y.reverse();
                x = x + t[u][0];
                x = x + y;
                    x.print();
                if (x.min <= k && k <= x.max) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        }
    }
    return 0;
}