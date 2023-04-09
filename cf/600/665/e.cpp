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
const int N = 3 + 1e6;

int n, a[N], k;
int tr[N * 30][2], cnt[N * 30], id;
LL ans;

void insert(int v) {
    int rt = 0;
    for (int i = 29; i >= 0; --i) {
        int &p = tr[rt][v >> i & 1];
        if (!p) {
            p = ++id;
        }
        rt = p;
        ++cnt[rt];
    }
}

void query(int rt, int p, int v) {
    if (p < 0) {
        ans += cnt[rt];
        return;
    }
    int vv = v >> p & 1;
    int kk = k >> p & 1;
    for (int i = 0; i <= 1; ++i) {
        if ((vv ^ i) == kk) {
            if (tr[rt][i]) {
                query(tr[rt][i], p - 1, v);
            }
        } else if ((vv ^ i) > kk) {
            ans += cnt[tr[rt][i]];
        }
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    insert(0);
    int pre = 0;
    for (int i = 1; i <= n; ++i) {
        pre ^= a[i];
        query(0, 29, pre);
        insert(pre);
    }
    cout << ans << endl;
    return 0;
}