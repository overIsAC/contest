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

int n, q;
int fa[N];
LL d[N];

int find(int p) {
    if (fa[p] == p) {
        return p;
    }
    int f = fa[p];
    fa[p] = find(fa[p]);
    d[p] += d[f];
    return fa[p];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    for (int i = 1; i <= q; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        int u = find(a), v = find(b);
        if (u == v) {
            if (::d[a] == ::d[b] + d) {
                cout << i << ' ';
            }

            continue;
        }

        fa[u] = fa[v];
        ::d[u] = d - (::d[a] - ::d[b]);
        cout << i << ' ';
    }

    return 0;
}