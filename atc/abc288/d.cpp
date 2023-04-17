#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

LL tr[11][N];
int n, a[N], b[N], k, q, l, r;

void add(LL *tr, int p, int v) {
    for (; p <= n; p += p & -p) {
        tr[p] += v;
    }
}

LL ask(LL *tr, int p) {
    LL ans = 0;
    for (; p; p -= p & -p) {
        ans += tr[p];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i] - a[i - 1];
        add(tr[i % k], i, b[i]);
    }
    cin >> q;
    while (q--) {
        cin >> l >> r;
        bool ok = true;
        for (int i = 0; i < k; ++i) {
            LL v = ask(tr[i], r) - ask(tr[i], l);
            if ((r + 1) % k == i) {
                continue;
            }
            // cout << " " << v << endl;
            if (l % k == i) {
                v += a[l];
            }
            // cout << r << ' ' << (r + 1) % k << ' ' << i << ' ' << v << endl;
            if (v) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}

/*

6 4
-16 4 21 21 37 17
1
1 6
*/