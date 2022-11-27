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

struct Node {
    int l, r;
    int max, v[11];
} tr[N << 2];

int p[11][N];
char s[N];
int n, q;

void up(Node &rt, const Node &l, const Node &r) {
    rt.l = l.l;
    rt.r = r.r;
    rt.max = max(l.max, r.max);
    for (int i = 2; i <= 10; ++i) {
        rt.v[i] = ((LL)l.v[i] * p[i][r.r - r.l + 1] + r.v[i]) % mod;
    }
}

void build(int k, int l, int r) {
    if (l == r) {
        tr[k].l = tr[k].r = r;
        tr[k].max = s[r] - '0';
        for (int i = 2; i <= 10; ++i) {
            tr[k].v[i] = s[r] - '0';
        }
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    up(tr[k], tr[lson], tr[rson]);
}

Node query(int k, int l, int r) {
    if (l <= tr[k].l && tr[k].r <= r) {
        return tr[k];
    }
    int mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid && mid < r) {
        Node temp;
        up(temp, query(lson, l, r), query(rson, l, r));
        return temp;
    }
    if (l <= mid) {
        return query(lson, l, r);
    } else {
        return query(rson, l, r);
    }
}

void update(int k, int p, int v) {
    if (tr[k].l == tr[k].r) {
        tr[k].max = v;
        for (int i = 2; i <= 10; ++i) {
            tr[k].v[i] = v;
        }
        return;
    }
    int mid = tr[k].l + tr[k].r >> 1;
    if (p <= mid) {
        update(lson, p, v);
    } else {
        update(rson, p, v);
    }
    up(tr[k], tr[lson], tr[rson]);
}

int main() {
    for (int i = 2; i <= 10; ++i) {
        p[i][0] = 1;
        for (int j = 1; j < N; ++j) {
            p[i][j] = (LL)p[i][j - 1] * i % mod;
        }
    }
    cin >> n >> q;
    cin >> s + 1;
    build(1, 1, n);
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            update(1, x, y);
        } else {
            auto ans = query(1, x, y);
            cout << ans.v[max(2, ans.max + 1)] << endl;
        }
    }
    return 0;
}