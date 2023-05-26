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
const int N = 3 + 1e6;

int n, m;
int p[N], d[N];
LL dp[N];
vector<int> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    for (int i = 1; i <= m; ++i) {
        a.push_back(m / i);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    dp[m] = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto &j : a) {
            dp[j / d[i]] = max(dp[j / d[i]], dp[j] + (LL)j * p[i]);
        }
    }
    LL ans = 0;
    for (auto &i : dp) {
        ans = max(i, ans);
    }
    cout << ans << endl;
    return 0;
}