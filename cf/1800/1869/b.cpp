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

struct Node {
    LL x, y;
} p[N];

LL d[N];
int n, k, a, b;

void solve() {
    cin >> n >> k >> a >> b;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    memset(d, 0x3f, sizeof(d));
    d[a] = 0;
    for (int i = 1; i <= k; ++i) {
        d[i] = min(d[i], abs(p[i].x - p[a].x) + abs(p[i].y - p[a].y));
    }
    LL minv = d[1];
    for (int i = 1; i <= k; ++i) {
        minv = min(minv, d[i]);
    }
    for (int i = 1; i <= k; ++i) {
        d[b] = min(d[b], minv + abs(p[i].x - p[b].x) + abs(p[i].y - p[b].y));
    }
    d[b] = min(d[b], abs(p[b].x - p[a].x) + abs(p[b].y - p[a].y));
    cout << d[b] << '\n';
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