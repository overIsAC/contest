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

int n, a[N];
int tr[N * 31][2], cnt[N * 31], id;
int root[N];

void insert(int p, int u, int &v, int a) {
    v = ++id;
    cnt[v] = cnt[u] + 1;
    if (p < 0) {
        return;
    }
    tr[v][0] = tr[u][0];
    tr[v][1] = tr[u][1];
    insert(p - 1, tr[u][a >> p & 1], tr[v][a >> p & 1], a);
}

int query(int p, int u, int v) {
    if (p < 0) {
        return 0;
    }
    if (cnt[tr[v][1]] - cnt[tr[u][1]]) {
        return query(p - 1, tr[v][1], tr[u][1]) | (1 << p);
    } else {
        return query(p - 1, tr[v][0], tr[u][0]);
    }
}

void solve() {
    for (int i = 0; i <= id; ++i) {
        tr[i][0] = tr[i][1] = cnt[i] = 0;
    }
    id = 0;
    for (int i = 0; i <= n; ++i) {
        root[i] = 0;
    }

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        insert(29, root[i - 1], root[i], a[i]);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        set<int> st;
        int u = root[l - 1], v = root[r];
        int ans = 0;
        for (int i = 29; i >= 0; --i) {
            int x = 0, y = 0;
            for (auto &j : st) {
                if (j >> i & 1) {
                    ++x;
                } else {
                    ++y;
                }
            }
            if (tr[v][1]) {
                x += cnt[tr[v][1]] - cnt[tr[u][1]];
            }
            if (tr[v][0]) {
                y += cnt[tr[v][0]] - cnt[tr[u][0]];
            }
            if (y >= 2) {
                for (auto it = st.begin(); it != st.end();) {
                    if (*it >> i & 1) {
                        it = st.erase(it);
                    } else {
                        ++it;
                    }
                }
                u = tr[u][0];
                v = tr[v][0];
            } else {
                ans |= 1 << i;
                if (y == 1) {
                    if (tr[v][0] && cnt[tr[v][0]] - cnt[tr[u][0]]) {
                        st.insert(query(i - 1, tr[u][0], tr[v][0]));
                    }
                }
                u = tr[u][1];
                v = tr[v][1];
            }
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}