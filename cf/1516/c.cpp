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

int n, a[N];
int dp[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
    }
    if (sum & 1) {
        cout << 0 << endl;
        return;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = sum; j >= a[i]; --j) {
            if (dp[j - a[i]]) {
                dp[j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] % 2) {
        } else {
            if (!dp[(sum - a[i]) / 2]) {
                ok = true;
            }
        }
    }
    return 0;
}