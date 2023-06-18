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

int n, k, a[N];
int dp[N][2];
LL pre[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        if (k >= n) {
            cout << "Alice" << endl;
            continue;
        }
        for (int i = n - k + 1; i <= n; ++i) {
            dp[i][0] = 1;
            dp[i][1] = 1;
        }
        for (int i = n - k; i >= 1; --i) {
            
        }
    }

    return 0;
}