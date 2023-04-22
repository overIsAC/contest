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

vector<int> ve[26];
LL dp[N];
int n;
char s[N];

int main() {
    cin >> s + 1;
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        ve[s[i] - 'a'].push_back(i);
    }
    LL ans = 0;
    for (int i = 0; i < 26; ++i) {
        if (ve[i].size()) {
            ++dp[ve[i][0]];
        }
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] %= mod;
        ans += dp[i];
        for (int j = 0; j < 26; ++j) {
            auto p = lower_bound(ve[j].begin(), ve[j].end(), i + 2);
            if (p == ve[j].end()) {
                continue;
            }
            dp[*p] += dp[i];
        }
    }
    ans = ans % mod;
    cout << ans << endl;
    return 0;
}