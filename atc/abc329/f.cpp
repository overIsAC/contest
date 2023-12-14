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
set<int> st[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        int c;
        cin >> c;

        st[i].insert(c);
    }
    while (q--) {
        int u, v;
        cin >> u >> v;

        if (st[u].size() > st[v].size()) {
            swap(st[u], st[v]);
        }
        for (auto& i : st[u]) {
            st[v].insert(i);
        }
        st[u].clear();
        cout << st[v].size() << endl;
    }
    return 0;
}