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

int n, m, k;
int fa[N];
int x[N], y[N];

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        fa[find(u)] = find(v);
    }
    cin >> k;
    int ok = 1;
    for (int i = 1; i <= k; ++i) {
        cin >> x[i] >> y[i];
        if (find(x[i]) == find(y[i])) {
            ok = 0;
        }
    }
    set<PII> st;
    for (int i = 1; i <= k; ++i) {
        st.insert({find(x[i]), find(y[i])});
        st.insert({find(y[i]), find(x[i])});
    }
    int q;
    cin >> q;
    if (!ok) {
        while (q--) {
            cout << "No" << endl;
        }
        return 0;
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        u = find(u);
        v = find(v);
        if (st.count({u, v}) || st.count({v, u})) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}