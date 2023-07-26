#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int N = 3 + 2e5;

struct TreeNode {
    int l, r;
    int a, b;
} tr[N << 2];

char s[N];
int n, q;

void up(TreeNode &rt, TreeNode l, TreeNode r) {
    rt.a += l.a + r.a;
    rt.b = l.b;
    if (l.a % 2) {
        rt.b -= r.b;
    } else {
        rt.b += r.b;
    }
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    if (l == r) {
        if (s[r] == 'A') {
            ++tr[k].a;
        } else {
            ++tr[k].b;
        }
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
    int mid = l + r >> 1;
    if (l <= mid && mid < r) {
        TreeNode ans;
        up(ans, query(lson, l, r), query(rson, l, r));
        return ans;
    }
    if (l <= mid) {
        return query(lson, l, r);
    } else {
        return query(rson, l, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    cin >> s + 1;

    build(1, 1, n);
    
    int ans = 0;
    while (q--) {
        int l, r;
        string x;
        cin >> l >> r >> x;
        int reall = min((ans ^ l) % n + 1, (ans ^ r) % n + 1);
        int realr = max((ans ^ l) % n + 1, (ans ^ r) % n + 1);
        l = reall;
        r = realr;

    }
    return 0;
}