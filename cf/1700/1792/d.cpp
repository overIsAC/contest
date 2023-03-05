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
const int N = 3 + 5e4;

int n, m, a[N][12];

int tr[N * 12][12], tot, val[N * 12];
int p[12];

void insert(int *a) {
    int rt = 0;
    for (int i = 1; i <= m; ++i) {
        int &p = tr[rt][a[i]];
        if (!p) {
            p = ++tot;
        }
        rt = p;
    }
}

void update(int *a)  {
    int rt = 0;
    for (int i = 1; i <= m; ++i) {
        p[a[i]] = i;
    }
    for (int i = 1; i <= m; ++i) {
        int &pp = tr[rt][p[i]];
        // cout << "update " << pp << ' ' << p[i] << endl;
        if (!pp) {
            // cout << "--------" << endl;
            return;
        }
        rt = pp;
        // cout << " updateval: " << rt << ' ' << val[rt] << ' ' << i << endl;
        val[rt] = max(val[rt], i);
    }
    // cout << " |||--------" << endl;
}

int query(int *a) {
    int rt = 0;
    int ans = 0;
    // cout << "-------- query --------" << endl;
    for (int i = 1; i <= m; ++i) {
        rt = tr[rt][a[i]];
        ans = max(ans, val[rt]);
        // cout << i << ' ' << ans << ' ' << rt << ' ' << a[i] << ' ' << val[rt] << endl;
    }
    // cout << "-------- query --------" << endl;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i <= tot; ++i) {
            memset(tr[i], 0, sizeof(tr[i]));
            val[i] = 0;
        }
        tot = 0;

        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> a[i][j];
            }
        }

        for (int i = 1; i <= n; ++i) {
            insert(a[i]);
        }
        for (int i = 1; i <= n; ++i) {
            update(a[i]);
        }
        for (int i = 1; i <= n; ++i) {
            cout << query(a[i]) << ' ';
        }
        cout << endl;
    }
    return 0;
}