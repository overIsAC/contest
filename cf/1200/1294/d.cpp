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
const int N = 3 + 1e6;

set<int> st;
int q, x, ans;

int fa[N * 2];
int vis[N * 2];

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

int main() {
    for (int i = 0; i < N * 2; ++i) {
        fa[i] = i;
    }
    cin >> q >> x;
    while (q--) {
        int v;
        cin >> v;
        v %= x;
        v = find(v);
        // db(v);
        if (v < N) {
            vis[v] = 1;
            fa[v] = v + x;
        }
        while (vis[ans]) {
            ++ans;
        }
        // db(ans);
        cout << ans << '\n';
    }
    return 0;
}