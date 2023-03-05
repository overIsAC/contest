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

int get(int x) {
    int ans = 1;
    while (x % 2 == 0) {
        ans *= 2;
        x /= 2;
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int mn = 1e9;
    for (int i = 1; i <= n; ++i) {
        mn = min(get(a[i]), mn);
    }

    for (int i = 1; i <= n; ++i) {
        a[i] /= mn;
    }

    int sum = 0, p = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        if (a[i] & 1) {
            p = i;
        }
    }

    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = sum; j >= a[i]; --j) {
            if (dp[j - a[i]]) {
                dp[j] = 1;
            }
        }
    }
    if (sum % 2 || !dp[sum / 2]) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
        cout << p << endl;
    }
    return 0;
}