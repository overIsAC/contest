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
const int N = 3 + 222;

int good[16200 + 111];
char s[N];
int a[N], n;
LL dp[N][16200 + 111];

int ini(int x) {
    set<int> st;
    auto f = [&](int x) {
        int ans = 0;
        while (x) {
            ans += (x % 10) * (x % 10);
            x /= 10;
        }
        return ans;
    };

    while (x != 1) {
        if (st.count(x)) {
            return 0;
        }
        st.insert(x);
        x = f(x);
    }
    return 1;
}

LL dfs(int p, int limit, LL sum) {
    if (!p) {
        return good[sum];
    }
    if (!limit && dp[p][sum] >= 0) {
        return dp[p][sum];
    }
    LL ans = 0;
    int up = limit ? a[p] : 9;
    for (int i = 0; i <= up; ++i) {
        ans += dfs(p - 1, limit && i == up, sum + i * i);
    }
    ans %= mod;
    if (!limit) {
        dp[p][sum] = ans;
    }
    return ans;
}

LL solve() {
    memset(dp, -1, sizeof(dp));
    return dfs(n, 1, 0);
}

int main() {
    for (int i = 1; i <= 16200; ++i) {
        good[i] = ini(i);
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> s + 1;
        n = strlen(s + 1);
        for (int i = 1; i <= n; ++i) {
            a[i] = s[n - i + 1] - '0';
        }
        --a[1];
        for (int i = 1; i <= n; ++i) {
            if (a[i] < 0) {
                a[i] += 10;
                a[i + 1] -= 1;
            } else {
                break;
            }
        }
        while (n > 1 && a[n] == 0) {
            --n;
        }
        db(n);
        db(a[n]);
        LL ans = mod - solve();
        cin >> s + 1;
        n = strlen(s + 1);
        for (int i = 1; i <= n; ++i) {
            a[i] = s[n - i + 1] - '0';
        }
        db(n);
        db(a[n]);
        ans = (ans + solve()) % mod;
        cout << ans << endl;
    }
    return 0;
}