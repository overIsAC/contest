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
const int N = 3 + 1e5;

int n, a[N], b[N];
LL m, u;

int main() {
    cin >> n >> m >> u;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        LL o = m, cnt = 0;
        for (int j = i; j <= n; ++j) {
            o -= a[j];
            if (o < 0) {
                break;
            }
            cnt += b[j];
            if (cnt > u) {
                break;
            }
            ans = max(ans, j - i + 1);
        }
    }
    cout << ans << endl;
    return 0;
}