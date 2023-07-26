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
const int N = 3 + 3e5;

int n, m;
int p[N];
char s[N];
LL c[N];

struct TreeNode {
    int l, r;
    LL v;
} tr[N << 2];

void up(int k) {
    tr[k].v = max(tr[lson].v, tr[rson].v);
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}

void update(int k, int p, int v) {
    if (tr[k].l == tr[k].r) {
        if (tr[k].v == -1) {
            tr[k].v = 0;
        }
        tr[k].v += v;
        if (tr[k].v == 0) {
            tr[k].v = -1;
        }
        return;
    }
    int mid = tr[k].l + tr[k].r >> 1;
    if (p <= mid) {
        update(lson, p, v);
    } else {
        update(rson, p, v);
    }
    up(k);
}

LL query(int k, int l, int r) {
    if (l <= tr[k].l && tr[k].r <= r) {
        return tr[k].v;
    }
    int mid = tr[k].l + tr[k].r >> 1;
    LL ans = 0;
    if (l <= mid) {
        ans = max(ans, query(lson, l, r));
    }
    if (r > mid) {
        ans = max(ans, query(rson, l, r));
    }
    return ans;
}

namespace Tree {
vector<int> edge[N];
int sz[N], top[N], fa[N], son[N], dfn[N], d[N], id;

void addEdge(int u, int v) {
    edge[u].push_back(v);
}

void dfs1(int x) {
    sz[x] = 1;
    for (auto &y : edge[x]) {
        fa[y] = x;
        d[y] = d[x] + 1;
        dfs1(y);
        sz[x] += sz[y];
        if (sz[son[x]] < sz[y]) {
            son[x] = y;
        }
    }
}

void dfs2(int x, int topf) {
    top[x] = topf;
    dfn[x] = ++id;
    if (son[x]) {
        dfs2(son[x], topf);
    }
    for (auto &y : edge[x]) {
        if (y == son[x]) {
            continue;
        }
        dfs2(y, y);
    }
}

}  // namespace Tree

namespace ACMC {
int tr[N][26], fail[N], id = 1;
int insert(char *s) {
    int rt = 1;
    int n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        int &p = tr[rt][s[i] - 'a'];
        if (!p) {
            p = ++id;
        }
        rt = p;
    }
    return rt;
}
void build() {
    queue<int> q;
    for (int i = 0; i < 26; ++i) {
        if (tr[0][i]) {
            q.push(tr[0][i]);
        }
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < 26; ++i) {
            if (tr[x][i]) {
                fail[tr[x][i]] = tr[fail[x]][i];
                q.push(tr[x][i]);
                Tree::addEdge(x, tr[x][i]);
            } else {
                tr[x][i] = tr[fail[x]][i];
            }
        }
    }
}
}  // namespace ACMC

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s + 1;
        p[i] = ACMC::insert(s);
    }
    ACMC::build();
    Tree::dfs1(1);
    Tree::dfs2(1, 1);
    while (m--) {
        int i, x, op;
        cin >> op;
        if (op == 1) {
            cin >> i >> x;
            update(1, Tree::dfn[p[i]], -c[i]);
            c[i] = x;
            update(1, Tree::dfn[p[i]], c[i]);
        } else {
            cin >> s + 1;
            LL ans = -1;
            int rt = 1, n = strlen(s + 1);

            for (int i = 1; i <= n; ++i) {
                while (rt && !ACMC::tr[rt][s[i] - 'a']) {
                    rt = ACMC::fail[rt];
                }
                if (!rt) {
                    rt = 1;
                    continue;
                }
                int p = ACMC::tr[rt][s[i] - 'a'];
                if (!p) {
                    break;
                }

                int t = p;

                while (t) {
                    ans = max(ans, query(1, Tree::dfn[Tree::top[t]], Tree::dfn[t]));
                    t = Tree::fa[Tree::top[t]];
                }

                rt = p;
            }

            cout << ans << endl;
        }
    }
    return 0;
}