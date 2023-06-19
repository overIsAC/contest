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
const int N = 3 + 1e5;

int main() {
    LL a, b, c, d;
    cin >> a >> b >> c >> d;
    LL q[] = {a, b, c};
    sort(q, q + 3);
    LL ans = 0;
    if (q[1] - q[0] < d) {
        ans += d - (q[1] - q[0]);
    }
    if (q[2] - q[1] < d) {
        ans += d - (q[2] - q[1]);
    }
    cout << ans << endl;
    return 0;
}