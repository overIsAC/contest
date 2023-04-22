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

int n, m;
int a[N], b[N];
vector<PII> ve[N];
map<int, int> mp;

struct Node {
    int l, r, v;
} tr[N << 2];

void build(int k, int l, int r) {
    tr[k].v = 0;
    tr[k].l = l;
    tr[k].r = r;
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}

void update(int k, int l, int r, int v) {
    if (l <= tr[k].l && tr[k].r <= r) {
        tr[k].v = max(tr[k].v, v);
        return;
    }
    int mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid) {
        update(lson, l, r, v);
    }
    if (r > mid) {
        update(rson, l, r, v);
    }
}

void query(int k, int v) {
    v = max(tr[k].v, v);
    if (tr[k].l == tr[k].r) {
        cout << ' ' << v;
        return;
    }
    query(lson, v);
    query(rson, v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, Case = 0;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i];
        }

        build(1, 1, m);

        for (int i = 1; i <= m; ++i) {
            ve[i].clear();
        }
        mp.clear();
        for (int i = 1; i <= n; ++i) {
            mp[a[i]] = max(mp[a[i]], b[i]);
        }
        for (auto& i : mp) {
            if (i.first <= m) {
                ve[i.first].push_back(i);
            } else {
                tr[1].v = max(tr[1].v, i.second);
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (auto& j : ve[i]) {
                update(1, i - j.first + 1, i, j.second);
                if (i + 2 * j.first <= m) {
                    ve[i + 2 * j.first].push_back(j);
                } else {
                    int L = i + j.first + 1, R = i + 2 * j.first;
                    R = min(m, R);
                    if (L <= R) {
                        update(1, L, R, j.second);
                    }
                }
            }
            ve[i].clear();
        }

        cout << "Case #" << ++Case << ":";
        query(1, 0);
        cout << endl;
    }
    return 0;
}