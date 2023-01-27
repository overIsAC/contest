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

int n, m;
char s[N];

struct Tree {
    struct TreeNode {
        int l, r;
        int lazy, value;
        void up(TreeNode &l, TreeNode &r) {
            value = l.value + r.value;
        }
        void down(TreeNode &l, TreeNode &r) {
            if (lazy != -1) {
                l.lazy = lazy;
                r.lazy = lazy;
                l.value = lazy * (l.r - l.l + 1);
                r.value = lazy * (r.r - r.l + 1);
                lazy = -1;
            }
        }
    } node[N << 2];
    void update(int k, int l, int r, int v) {
        if (l <= node[k].l && node[k].r <= r) {
            node[k].value = v * (node[k].r - node[k].l + 1);
            node[k].lazy = v;
            return;
        }
        node[k].down(node[lson], node[rson]);
        int mid = node[k].l + node[k].r >> 1;
        if (l <= mid) {
            update(lson, l, r, v);
        }
        if (r > mid) {
            update(rson, l, r, v);
        }
        node[k].up(node[lson], node[rson]);
    }
    int query(int k, int l, int r) {
        if (l <= node[k].l && node[k].r <= r) {
            return node[k].value;
        }
        node[k].down(node[lson], node[rson]);
        int mid = node[k].l + node[k].r >> 1, ans = 0;
        if (l <= mid) {
            ans += query(lson, l, r);
        }
        if (r > mid) {
            ans += query(rson, l, r);
        }
        return ans;
    }
} tr[26];

void build(int k, int l, int r) {
    for (int i = 0; i < 26; ++i) {
        tr[i].node[k] = {l, r, 0, -1};
    }
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    cin >> n >> m;
    cin >> s + 1;
    build(1, 1, n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            tr[j].update(1, i, i, s[i] == j + 'a');
        }
    }
    while (m--) {
        int l, r;
        int cnt[26];
        cin >> l >> r;
        int p = -1, c = 0;
        for (int i = 0; i < 26; ++i) {
            cnt[i] = tr[i].query(1, l, r);
            if (cnt[i] & 1) {
                p = i;
                ++c;
            }
        }
        if (c > 1) {
            continue;
        }
        for (int i = 0; i < 26; ++i) {
            tr[i].update(1, l, r, 0);
        }
        if (c == 1) {
            --cnt[p];
            for (int i = 0; i < 26; ++i) {
                tr[i].update(1, (l + r) / 2, (l + r) / 2, i == p);
            }
        }
        for (int i = 0; i < 26; ++i) {
            int c = cnt[i] / 2;
            if (!c) {
                continue;
            }
            tr[i].update(1, l, l + c - 1, 1);
            tr[i].update(1, r - c + 1, r, 1);
            l += c;
            r -= c;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (tr[j].query(1, i, i)) {
                cout << (char)(j + 'a');
                break;
            }
        }
    }
    return 0;
}