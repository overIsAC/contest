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

int n, a[N], d;
int b[N];

int main() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        LL L = b[i], R = b[i] + d;
        auto get = [&](int p) {
            LL ans = a[p];
            ans = max(ans, L);
            ans = min(ans, R);
            return ans;
        };
        LL t = 0;
        for (int j = 2; j <= n; ++j) {
            t += abs(get(j) - get(j - 1));
        }
        ans = max(ans, t);

        L = b[i] - d;
        R = b[i];
        t = 0;
        for (int j = 2; j <= n; ++j) {
            t += abs(get(j) - get(j - 1));
        }
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}