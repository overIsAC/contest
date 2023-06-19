#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, k, a[N];
int pow10[22];

int calc(int n) {
    int len = 0;
    while (n) {
        ++len;
        n /= 10;
    }
    return len;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    LL ans = 0;
    map<int, int> mp[22];
    for (int i = 1; i <= n; ++i) {
        LL p = 10 % k;
        for (int j = 1; j <= 10; ++j) {
            ++mp[j][(k - p * a[i] % k) % k];
            p = p * 10 % k;
        }
    }

    pow10[0] = 1;
    for (int i = 1; i <= 11; ++i) {
        pow10[i] = (LL)pow10[i - 1] * 10 % k;
    }
    for (int i = 1; i <= n; ++i) {
        int len = calc(a[i]);
        if (mp[len].count(a[i] % k)) {
            ans += mp[len][a[i] % k];
        }
        if (((LL)pow10[len] * a[i] + a[i]) % k == 0) {
            --ans;
        }
    }
    cout << ans << endl;
    return 0;
}