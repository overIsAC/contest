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

LL ans;
LL a, b, r;

void dfs(int p, int limit, LL dif) {
    if (p < 0) {
        ans = min(ans, abs(dif));
        return;
    }
    LL di = LLONG_MAX;
    int up = limit ? (r >> p & 1) : 1;
    for (int i = 0; i <= up; ++i) {
        LL xoa = a >> p & 1;
        LL xob = b >> p & 1;
        xoa ^= i;
        xob ^= i;
        di = min(di, abs(dif * 2 + xoa - xob));
    }
    for (int i = 0; i <= up; ++i) {
        LL xoa = a >> p & 1;
        LL xob = b >> p & 1;
        xoa ^= i;
        xob ^= i;
        if (di == abs(dif * 2 + xoa - xob)) {
            dfs(p - 1, limit && up == i, dif * 2 + xoa - xob);
            if (xoa == xob) {
                break;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b >> r;
        ans = LLONG_MAX;
        dfs(61, 1, 0);
        cout << ans << endl;
    }
    return 0;
}