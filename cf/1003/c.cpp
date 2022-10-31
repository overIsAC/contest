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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, k, a[N];
int pre[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + k - 1; j <= n; ++j) {
            ans = max(ans, (double)(pre[j] - pre[i - 1]) / (j - i + 1));
        }
    }
    cout << fixed << setprecision(11) << ans << endl;
    return 0;
}