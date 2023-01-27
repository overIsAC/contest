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

int n, a[N];
int pre[N];

struct Cartesian {
    int ls[N], rs[N];
    int stk[N], top;
    void build() {
        for (int i = 0; i <= n; ++i) {
            ls[i] = rs[i] = 0;
        }
        top = 0;
        for (int i = 1; i <= n; ++i) {
            int oldTop = top;
            while (top && a[stk[top]] < a[i]) {
                --top;
            }
            if (top < oldTop) {
                ls[i] = stk[top + 1];
            }
            rs[stk[top]] = i;
            stk[++top] = i;
        }
    }
} tr1 = {};

struct Trie {
    int ch[N * 31][2], cnt[N * 31];
    int id, root[N];
    void insert(int p, int u, int &v, int val) {
        v = ++id;
        cnt[v] = cnt[u] + 1;
        ch[v][0] = ch[u][0];
        ch[v][1] = ch[u][1];
        if (p < 0) {
            return;
        }
        int o = val >> p & 1;
        insert(p - 1, ch[u][o], ch[v][o], val);
    }
    void build() {
        for (int i = 0; i <= id; ++i) {
            ch[i][0] = 0;
            ch[i][1] = 0;
            cnt[i] = 0;
        }
        id = 0;
        for (int i = 0; i <= n + 1; ++i) {
            root[i] = 0;
        }
        for (int i = 1; i <= n + 1; ++i) {
            insert(29, root[i - 1], root[i], pre[i - 1]);
        }
    }
    int query(int p, int u, int v, int val) {
        if (p < 0) {
            return 0;
        }
        int o = val >> p & 1;
        if (cnt[ch[v][o ^ 1]] - cnt[ch[u][o ^ 1]] > 0) {
            return query(p - 1, ch[u][o ^ 1], ch[v][o ^ 1], val) | (1 << p);
        }
        return query(p - 1, ch[u][o], ch[v][o], val);
    }
    int query(int l, int r, int x) {
        ++l;
        ++r;
        return query(29, root[l - 1], root[r], x);
    }
} tr2 = {};

int ans;

void dfs(int x, int l, int r) {
    if (!x || l >= r) {
        return;
    }
    if (x - l < r - x) {
        for (int i = l; i <= x; ++i) {
            if (x + 1 <= r) {
                ans = max(ans, tr2.query(x + 1, r, a[x] ^ pre[i - 1]));
            }
            ans = max(ans, a[x] ^ pre[x] ^ pre[i - 1]);
        }
    } else {
        for (int i = x; i <= r; ++i) {
            if (l <= x - 1) {
                ans = max(ans, tr2.query(l - 1, x - 1, a[x] ^ pre[i]));
            }
            ans = max(ans, a[x] ^ pre[i] ^ pre[x - 1]);
        }
    }
    dfs(tr1.ls[x], l, x - 1);
    dfs(tr1.rs[x], x + 1, r);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pre[i] = pre[i - 1] ^ a[i];
        }
        tr1.build();
        tr2.build();

        ans = 0;
        dfs(tr1.rs[0], 1, n);
        cout << ans << '\n';
    }
    return 0;
}