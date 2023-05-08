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

int main() {
    LL n;
    cin >> n;
    map<LL, int> mp;
    for (LL i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ++mp[i];
            n /= i;
        }
    }
    if (n > 1) {
        ++mp[n];
    }
    int ans = 0;
    for (auto &i : mp) {
        for (int j = 1; j <= i.second; i.second -= j, ++j) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}