#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

set<int> st[N];
int id[N], p[N], rid[N];
int n, q;
int tot;

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        st[i].insert(i);
        id[i] = i;
        rid[i] = i;
        p[i] = i;
    }
    tot = n;
    while (q--) {
        int op, x, y;
        cin >> op >> x;
        if (op == 1) {
            cin >> y;
            if (st[rid[x]].size() < st[rid[y]].size()) {
                swap(id[rid[x]], id[rid[y]]);
                swap(rid[x], rid[y]);
            }
            for (auto &i : st[rid[y]]) {
                st[rid[x]].insert(i);
                p[i] = rid[x];
            }
            st[rid[y]].clear();
        } else if (op == 2) {
            ++tot;
            p[tot] = rid[x];
            st[rid[x]].insert(tot);
        } else {
            cout << id[p[x]] << endl;
        }
    }
    return 0;
}