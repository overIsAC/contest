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

struct TreeNode {
    int l, r;
    int min;
} tr[N << 2];

int n, a[N];

void up(int k) {
    tr[k].min = min(tr[lson].min, tr[rson].min);
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    if (l == r) {
        tr[k].min = a[r];
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    up(k);
}

int query(int k, int l, int r) {
    if (l <= tr[k].l && tr[k].r <= r) {
        return tr[k].min;
    }
    int mid = tr[k].l + tr[k].r >> 1;
    int ans = INT_MAX;
    if (l <= mid) {
        ans = min(ans, query(lson, l, r));
    }
    if (r > mid) {
        ans = min(ans, query(rson, l, r));
    }
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n);
    int t = a[n];
    map<int, vector<int>> mp;
    for (int i = n; i >= 1; --i) {
        t = max(t, a[i]);
        mp[t].push_back(i);
    }
    for (auto &[x, y] : mp) {
        reverse(y.begin(), y.end());
    }
    t = a[1];
    for (int i = 1; i + 1 <= n - 1; ++i) {
        t = max(t, a[i]);
        if (t > a[i + 1]) {
            continue;
        }
        int L = i + 1, R = n - 1;
        while (L < R) {
            int mid = L + R + 1 >> 1;
            if (query(1, i + 1, mid) > t) {
                L = mid;
            } else {
                R = mid - 1;
            }
        }
        if (query(1, i + 1, R) > t) {
            ++R;
        }
        if (R >= n) {
            continue;
        }

        if (query(1, i + 1, R) != t) {
            continue;
        }
        if (!mp.count(t)) {
            continue;
        }

        auto &ve = mp[t];
        auto p = upper_bound(ve.begin(), ve.end(), R);
        if (p == ve.end()) {
            continue;
        }
        if (query(1, i + 1, *p - 1) != t) {
            continue;
        }
        cout << "Yes" << endl;
        cout << i << ' ' << *p - 1 - i << ' ' << n - *p + 1 << endl;
        return;
    }
    cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}