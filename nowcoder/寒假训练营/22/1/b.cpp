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
char s[N];

struct TreeNode {
    int l, r;
    int v[3][3];
    TreeNode() { memset(v, -0x3f, sizeof(v)); }
} tr[N << 2];

void up(TreeNode &rt, const TreeNode &l, const TreeNode &r) {
    rt.l = l.l;
    rt.r = r.r;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (l.v[i][j] < -1e9) continue;
            for (int k = 0; k < 3; ++k) {
                if (r.v[j][k] < -1e9) continue;
                rt.v[i][k] = l.v[i][j] + r.v[j][k];
            }
        }
    }
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    if (l == r) {
        int dif = 0;
        if (s[r] == 'W') {
            dif = 1;
        }
        if (s[r] == 'L') {
            dif = -1;
        }
        for (int i = 0; i < 3; ++i) {
            if (dif == -1 && i == 0) {
                tr[k].v[0][0] = 0;
            } else {
                tr[k].v[i][(dif + i + 3) % 3] = dif;
            }
        }
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    up(tr[k], tr[lson], tr[rson]);
}

TreeNode query(int k, int l, int r) {
    if (l <= tr[k].l && tr[k].r <= r) {
        return tr[k];
    }
    int mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid && mid < r) {
        TreeNode ans;
        up(ans, query(lson, l, r), query(rson, l, r));
        return ans;
    }
    if (l <= mid) {
        return query(lson, l, r);
    }
    return query(rson, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    cin >> s + 1;
    build(1, 1, n);
    while (q--) {
        int l, r, s;
        cin >> l >> r >> s;
        auto temp = query(1, l, r);
        for (int i = 0; i < 3; ++i) {
            if (temp.v[s % 3][i] < -1e9) {
                continue;
            }
            cout << s + temp.v[s % 3][i] << endl;
        }
    }
    return 0;
}