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
const int N = 3 + 1e6;

int n, r;
LL k, a[N];
LL pre[N];
LL p[N];

int ok(LL v) {
    LL t = 0;
    for (int i = 1; i <= n; ++i) {
        int L = max(1, i - r), R = min(n, i + r);
        t -= p[L - 1];
        LL c = pre[R] - pre[L - 1];
        c
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> r >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    LL l = 1, r = 2e18;
    while (l < r) {
        LL mid = l + r + 1 >> 1;
        if (ok(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << r << endl;
    return 0;
}