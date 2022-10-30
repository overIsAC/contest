#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 2e5;

int n, m;
char s[22];
int a[N];
LL dp[1 << 18];
bool vis[N];
vector<int> ve[1 << 18];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s);
        int &v = a[i];
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'o') v |= 1 << j;
        }
        vis[v] = true;
    }
    const int up = 1 << m;
    for (int i = 0; i < up; ++i) {
        const int v = (up - 1) ^ i;
        if (vis[0]) ve[i].push_back(0);
        for (int j = v; j; j = (j - 1) & v) {
            if (vis[j]) ve[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; ++i) {
        LL sum = 0;
        const int &v = a[i];
        for (auto &j : ve[v]) {
            sum += dp[j];
        }
        sum += 1;
        sum %= mod;
        dp[v] += sum;
        if (dp[v] >= mod) dp[v] -= mod;
    }
    LL ans = 0;
    for (int i = 0; i < up; ++i) {
        ans += dp[i];
    }
    printf("%lld\n", ans % mod);
    return 0;
}