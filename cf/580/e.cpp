#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using ULL = unsigned long long;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

struct Node {
    int l, r;
    ULL f;
    int tag;
} tr[N << 2];

int n, m, k;
char s[N];
ULL p[N];
ULL f[N][10];

void up(Node &rt, const Node &l, const Node &r) {
    rt.f = (l.f * p[r.r - r.l + 1] + r.f) % mod;
    rt.l = l.l;
    rt.r = r.r;
}

void down(int k) {
    if (tr[k].tag != -1) {
        tr[lson].f = f[tr[lson].r - tr[lson].l + 1][tr[k].tag];
        tr[rson].f = f[tr[rson].r - tr[rson].l + 1][tr[k].tag];
        tr[lson].tag = tr[k].tag;
        tr[rson].tag = tr[k].tag;
        tr[k].tag = -1;
    }
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    tr[k].tag = -1;
    if (l == r) {
        tr[k].f = s[r];
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    up(tr[k], tr[lson], tr[rson]);
}

void update(int k, int l, int r, int v) {
    if (l <= tr[k].l && tr[k].r <= r) {
        tr[k].tag = v;
        tr[k].f = f[tr[k].r - tr[k].l + 1][v];
        return;
    }
    down(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid) update(lson, l, r, v);
    if (r > mid) update(rson, l, r, v);
    up(tr[k], tr[lson], tr[rson]);
}

Node query(int k, int l, int r) {
    if (l > r) return {l, r, 0ULL, 0};
    if (l <= tr[k].l && tr[k].r <= r) {
        return tr[k];
    }
    down(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid && mid < r) {
        Node ans;
        up(ans, query(lson, l, r), query(rson, l, r));
        return ans;
    }
    if (l <= mid) return query(lson, l, r);
    return query(rson, l, r);
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", s + 1);

    for (char i = '0'; i <= '9'; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[j][i - '0'] = (f[j - 1][i - '0'] * 131 + i) % mod;
        }
    }
    0 [p] = 1;
    for (int i = 1; i <= n; ++i) {
        i[p] = (i - 1)[p] * 131 % mod;
    }

    build(1, 1, n);

    int q = m + k;
    while (q--) {
        int op, l, r, c;
        scanf("%d%d%d%d", &op, &l, &r, &c);
        if (op == 1) {
            update(1, l, r, c);
        } else {
            int p = r - l + 1 - c;
            if (query(1, l, l + p - 1).f == query(1, r - p + 1, r).f) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
    return 0;
}