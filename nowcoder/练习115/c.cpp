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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 5e5;

struct TreeNode {
    int l, r;
    int pl[201], pr[201];
    int lazy;
    double ans;
} tr[N * 2];

int n, a[N], q;

double calc(int ai, int i, int aj, int j) {
    return fabs(1.0 * (ai - aj) / (i - j));
}

void up(TreeNode &rt, const TreeNode &l, const TreeNode &r) {
    rt.ans = max(l.ans, r.ans);
    rt.l = l.l;
    rt.r = r.r;
    if (rt.r - rt.l <= 400) {
        for (int i = 0; i <= 200; ++i) {
            for (int j = 0; j <= 200; ++j) {
                if (l.pl[i] < 1e9 && r.pl[i] < 1e9) {
                    rt.ans = max(rt.ans, calc(i, l.pl[i], j, r.pl[j]));
                }
                if (l.pl[i] < 1e9 && r.pr[i] > -1e9) {
                    rt.ans = max(rt.ans, calc(i, l.pl[i], j, r.pr[j]));
                }
                if (l.pr[i] > -1e9 && r.pl[i] < 1e9) {
                    cout << "**** " << i << ' ' << j << ' ' << l.pr[i] << ' ' << r.pl[i] << endl;
                    rt.ans = max(rt.ans, calc(i, l.pr[i], j, r.pl[j]));
                }
                if (l.pr[i] > -1e9 && r.pr[i] > -1e9) {
                    rt.ans = max(rt.ans, calc(i, l.pr[i], j, r.pr[j]));
                }
            }
        }
        for (int i = 0; i <= 200; ++i) {
            rt.pl[i] = min(l.pl[i], r.pl[i]);
            rt.pr[i] = max(l.pr[i], r.pr[i]);
        }
    }
}

int temp[201];

void add(TreeNode &rt, int v) {
    for (int i = 0; i <= 200; ++i) {
        temp[i] = 1e9;
    }
    for (int i = 0; i <= 200; ++i) {
        if (rt.pl[i] < 1e9) {
            temp[i + v] = rt.pl[i];
        }
    }
    memcpy(rt.pl, temp, sizeof(temp));
    for (int i = 0; i <= 200; ++i) {
        temp[i] = -1e9;
    }
    for (int i = 0; i <= 200; ++i) {
        if (rt.pr[i] > -1e9) {
            temp[i + v] = rt.pr[i];
        }
    }
    memcpy(rt.pr, temp, sizeof(temp));

    rt.lazy += v;
}

void down(int k) {
    if (tr[k].lazy) {
        add(tr[lson], tr[k].lazy);
        add(tr[rson], tr[k].lazy);
        tr[k].lazy = 0;
    }
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    if (l == r) {
        for (int i = 0; i <= 200; ++i) {
            tr[k].pl[i] = 1e9;
            tr[k].pr[i] = -1e9;
        }
        tr[k].pl[a[r] + 100] = r;
        tr[k].pr[a[r] + 100] = r;
        tr[k].ans = 0;
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    up(tr[k], tr[lson], tr[rson]);
}

void update(int k, int l, int r, int v) {
    if (l <= tr[k].l && tr[k].r <= r) {
        add(tr[k], v);
        return;
    }
    down(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid) {
        update(lson, l, r, v);
    }
    if (r > mid) {
        update(rson, l, r, v);
    }
    up(tr[k], tr[lson], tr[rson]);
    cout << tr[k].pr[100 + 2] << ' ' << tr[k].pl[100 + 1] << endl;
    cout << tr[k].l << ' ' << tr[k].r << ' ' << tr[k].ans << endl;
    cout << calc(102, tr[k].pr[100 + 2], 101, tr[k].pl[100 + 1]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n);
    cout << fixed << setprecision(10) << tr[1].ans << '\n';
    cout << "----------------" << endl;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        update(1, l, r, x);
        cout << fixed << setprecision(10) << tr[1].ans << '\n';
    }
    return 0;
}