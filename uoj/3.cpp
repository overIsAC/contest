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

struct Edge {
    int u, v, a, b;
} e[N];

int n, m;
int vis[N];

int fa[N];
int w[N];

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

struct LCT {
    int ch[N][2], fa[N], rev[N], p[N];
    int get(int x) {
        return x == ch[fa[x]][1];
    }
    int isRoot(int x) {
        return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
    }
    void down(int x) {
        if (rev[x]) {
            swap(ch[x][0], ch[x][1]);
            if (ch[x][0]) {
                rev[ch[x][0]] ^= 1;
            }
            if (ch[x][1]) {
                rev[ch[x][1]] ^= 1;
            }
            rev[x] = 0;
        }
    }
    void up(int x) {
        p[x] = x;
        if (ch[x][0]) {
            if (w[p[x]] < w[p[ch[x][0]]]) {
                p[x] = p[ch[x][0]];
            }
        }
        if (ch[x][1]) {
            if (w[p[x]] < w[p[ch[x][1]]]) {
                p[x] = p[ch[x][1]];
            }
        }
    }
    void rotate(int x) {
        int y = fa[x], z = fa[y], chk = get(x);
        if (!isRoot(y)) {
            ch[z][get(y)] = x;
        }
        if (ch[x][!chk]) {
            fa[ch[x][!chk]] = y;
        }
        ch[y][chk] = ch[x][!chk];
        ch[x][!chk] = y;

        fa[y] = x;
        fa[x] = z;
        up(y);
        up(x);
    }

    void splay(int x) {
        static int stk[N], top;
        stk[top = 1] = x;
        for (int y = x; !isRoot(y); y = fa[y]) {
            stk[++top] = fa[y];
        }
        while (top) {
            down(stk[top--]);
        }
        for (int f; f = fa[x], !isRoot(x); rotate(x)) {
            if (!isRoot(f)) {
                if (get(x) == get(f)) {
                    rotate(f);
                } else {
                    rotate(x);
                }
            }
        }
    }
    int access(int x) {
        int y = 0;
        while (x) {
            splay(x);
            ch[x][1] = y;
            up(x);
            y = x;
            x = fa[x];
        }
        return y;
    }
    void makeRoot(int x) {
        rev[access(x)] ^= 1;
    }
    void link(int x, int y) {
        makeRoot(x);
        splay(x);
        fa[x] = y;
    }
    void cut(int x, int y) {
        makeRoot(x);
        access(y);
        splay(y);
        assert(ch[y][0] == x);
        assert(fa[x] == y);
        ch[y][0] = 0;
        fa[x] = 0;
        up(y);
    }
} lct;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        e[i] = {u, v, a, b};
    }
    sort(e + 1, e + m + 1, [](Edge &a, Edge &b) {
        return a.a < b.a;
    });

    for (int i = 1; i <= n + m; ++i) {
        lct.p[i] = i;
    }

    for (int i = n + 1; i <= n + m; ++i) {
        w[i] = e[i - n].b;
    }
    int ans = 1e9;
    int mx = 0;

    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }

    for (int i = 1; i <= m; ++i) {
        auto [u, v, a, b] = e[i];
        if (find(u) == find(v)) {
            continue;
        }
        fa[find(u)] = find(v);
        vis[i] = 1;
        lct.link(u, i + n);
        lct.link(v, i + n);

        if (find(1) == find(n)) {
            mx = a;
            lct.makeRoot(1);
            lct.makeRoot(n);
            lct.splay(n);
            ans = min(ans, mx + w[lct.p[n]]);
            break;
        }
    }

    if (ans > 1e7) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= m; ++i) {
        if (vis[i]) {
            continue;
        }
        auto [u, v, a, b] = e[i];
        if (find(u) != find(v)) {
            mx = max(mx, a);
            fa[find(u)] = find(v);
            lct.link(u, i + n);
            lct.link(v, i + n);
            continue;
        }
        lct.makeRoot(u);
        lct.makeRoot(v);
        lct.splay(v);
        int p = lct.p[v];
        if (w[p] <= b) {
            continue;
        }
        lct.cut(e[p - n].u, p);
        lct.cut(e[p - n].v, p);
        lct.link(u, i + n);
        lct.link(v, i + n);
        mx = max(mx, a);
        lct.makeRoot(1);
        lct.makeRoot(n);
        lct.splay(n);
        ans = min(ans, mx + w[lct.p[n]]);
    }

    cout << ans << endl;

    return 0;
}