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
const int N = 3 + 1e5;

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * q;
        n >>= 1;
        q = q * q;
    }
    return ans;
}

int main() {
    LL n, p;
    cin >> n >> p;
    map<LL, int> mp;
    for (LL i = 2; i * i <= p; ++i) {
        while (p % i == 0) {
            ++mp[i];
            p /= i;
        }
    }
    if (p > 1) {
        ++mp[p];
    }
    LL ans = 1;
    int flag = 0;
    for (auto &i : mp) {
        if (i.second >= n) {
            flag = 1;
        }
        ans *= qpow(i.first, i.second / n);
    }
    if (!flag) {
        ans = 1;
    }
    cout << ans << endl;

    return 0;
}