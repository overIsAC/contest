#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 998244353;
const int N = 3 + 1e6;

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n % 2) {
            ans = ans * q % mod;
        }
        q = q * q % mod;
        n /= 2;
    }
    return ans;
}

vector<pair<LL, LL>> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (LL i = 1, j = 3; i <= 2e9; i = j, j = j * 2 + 1) {
        a.push_back({i, j - 1});
    }

    LL n, m;
    cin >> n >> m;
    LL ans = 1;

    for (int i = 0; i < a.size(); ++i) {
        auto [L, R] = a[i];
        if (R < n || n + m - 1 < L) {
            continue;
        }
        L = max(L, n);
        R = min(R, n + m - 1);

        LL t = (1 - qpow(1 << (i + 1), mod - 2) + mod) % mod;
        t = qpow(t, R - L + 1);

        ans = ans * t % mod;
    }

    cout << ans << endl;

    return 0;
}