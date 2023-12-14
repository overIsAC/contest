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
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, k, a[N];
int pre[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    LL ans = 0;
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        pre[i] = (pre[i - 1] + a[i]) % k;

        ++mp[pre[i - 1]];
        ans += mp[pre[i]];
    }
	cout << ans << endl;
    return 0;
}
/*

2 3
1 2

*/