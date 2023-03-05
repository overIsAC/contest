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

int n, q, a[N];
int cnt[N * 50], root[N], ls[N * 50], rs[N * 50];
int id;
int temp[N];

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * q % mod;
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

void up(int rt) {
    if (!ls[rt] || !rs[rt]) {
        cnt[rt] = 0;
    } else {
        cnt[rt] = min(cnt[ls[rt]], cnt[rs[rt]]);
    }
}

void update(int &rt, int l, int r, int p, int v) {
    if (!rt) {
        rt = ++id;
    }
    cnt[rt] += v;
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    if (p <= mid) {
        update(ls[rt], l, mid, p, v);
    } else {
        update(rs[rt], mid + 1, r, p, v);
    }
    up(rt);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        int v = a[i];
        for (int j = 2; j * j <= v; ++j) {
            if (v % j == 0) {
                int c = 0;
                while (v % j == 0) {
                    v /= j;
                    ++c;
                }
                update(root[j], 1, n, i, c);
            }
        }
        if (v > 1) {
            update(root[v], 1, n, i, 1);
        }
    }
    LL ans = 1;
    for (int i = 1; i <= 2e5; ++i) {
        temp[i] = qpow(i, cnt[root[i]]);
        ans = ans * temp[i] % mod;
    }
    while (q--) {
        int p, v;
        cin >> p >> v;
        for (int i = 2; i * i <= v; ++i) {
            if (v % i == 0) {
                int c = 0;
                while (v % i == 0) {
                    v /= i;
                    ++c;
                }
                ans = ans * qpow(temp[i], mod - 2) % mod;
                update(root[i], 1, n, p, c);
                temp[i] = qpow(i, cnt[root[i]]);
                ans = ans * temp[i] % mod;
            }
        }
        if (v > 1) {
            ans = ans * qpow(temp[v], mod - 2) % mod;
            update(root[v], 1, n, p, 1);
            temp[v] = qpow(v, cnt[root[v]]);
            ans = ans * temp[v] % mod;
        }
        cout << ans << endl;
    }

    return 0;
}