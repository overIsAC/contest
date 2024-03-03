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

const int mod = 7 + 1e4;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, m, a[N], b[N];
map<int, vector<int>> mp;

LL calc(vector<int>& ve) {
    LL ans = 0;
    int cnt[2] = {};
    LL sum1[2] = {};
    LL sum2[2] = {};
    LL sum3[2] = {};
    for (int& i : ve) {
        ans += (LL)cnt[i % 2] * a[i] % mod * i;
        ans += sum1[i % 2];
        ans += sum2[i % 2] * i;
        ans += sum3[i % 2] * a[i];

        ans %= mod;

        cnt[i % 2] += 1;
        sum1[i % 2] = (sum1[i % 2] + (LL)i * a[i]) % mod;
        sum2[i % 2] = (sum2[i % 2] + a[i]) % mod;
        sum3[i % 2] = (sum3[i % 2] + i) % mod;
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        mp[b[i]].push_back(i);
    }

    LL ans = 0;
    for (auto& [u, v] : mp) {
        ans += calc(v);
    }
    cout << ans % mod;
    return 0;
}