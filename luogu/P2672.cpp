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

struct Node {
    int x, y, id;
} a[N];

struct TreeNode {
    int l, r;
    LL value, lazy;
} tr[N << 2];

int n;

void down(int k) {
    if (tr[k].lazy) {
        tr[lson].value += tr[k].value;
        tr[lson].lazy += tr[k].lazy;
        tr[rson].value += tr[k].value;
        tr[rson].lazy += tr[k].lazy;
        tr[k].lazy = 0;
    }
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    if (l == r) {
        tr[k].value = a[r].x * 2;
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    tr[k].value = max(tr[lson].value, tr[rson].value);
}

void update(int k, int l, int r, int value) {
    if (l <= tr[k].l && tr[k].r <= r) {
        tr[k].value += value;
        tr[k].lazy += value;
        return;
    }
    down(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid) {
        update(lson, l, r, value);
    }
    if (r > mid) {
        update(rson, l, r, value);
    }
    tr[k].value = max(tr[lson].value, tr[rson].value);
}

LL query(int k, int l, int r) {
    if (l <= tr[k].l && tr[k].r <= r) {
        return tr[k].value;
    }
    down(k);
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

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].x;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].y;
    }
    sort(a + 1, a + n + 1, [](Node& a, Node& b) {
        if (a.x == b.x) {
            return a.y < b.y;
        }
        return a.x < b.x;
    });
    for (int i = 1; i <= n; ++i) {
        a[i].id = i;
    }

    build(1, 1, n);

    sort(a + 1, a + n + 1, [](Node& a, Node& b) {
        return a.y < b.y;
    });

    for (int i = n; i >= 1; --i) {
        update(1, max(a[i].id, i), n, a[i].y);
        cout << query(1, 1, n) << endl;

        cout << "********" << endl;
        for (int j = 1; j <= n; ++j) {
            cout << j << ' ' << query(1, j, j) << endl;
        }
    }

    return 0;
}