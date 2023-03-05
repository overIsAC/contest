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

int n, a[N], b[N];
int p[N], q[N];

LL calc(LL len) {
    return len * (len - 1) / 2 + len;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        p[a[i]] = i;
        q[b[i]] = i;
    }
    int L1 = p[1], R1 = p[1], L2 = q[1], R2 = q[1];
    LL ans = 1;
    ans += calc(n - max(R1, R2));
    ans += calc((min(L1, L2) - 1));
    ans += calc(abs(p[1] - q[1]) - 1);
    for (int i = 2; i <= n; ++i) {
        int L = min(L1, L2), R = max(R1, R2);
        if (!(L <= p[i] && p[i] <= R) && !(L <= q[i] && q[i] <= R)) {
            if (p[i] > R && q[i] > R) {
                ans += (LL)(min(p[i], q[i]) - R) * L;
            } else if (p[i] < L && q[i] < L) {
                ans += (LL)(L - max(p[i], q[i])) * (n - R + 1);
            } else {
                int LL = p[i], RR = q[i];
                if (LL > RR) {
                    swap(LL, RR);
                }
                ans += (long long)(RR - R) * (L - LL);
            }
        }
        L1 = min(L1, p[i]);
        R1 = max(R1, p[i]);
        L2 = min(L2, q[i]);
        R2 = max(R2, q[i]);
    }
    cout << ans << endl;

    return 0;
}