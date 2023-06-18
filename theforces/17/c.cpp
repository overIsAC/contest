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

int n, a[N];
LL st[N];
int p[N];
int t;
LL pre[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i <= 300; ++i) {
        if (p[i]) {
            continue;
        }
        for (int j = i; j <= 300; j += i) {
            p[j] = 1;
            int k = j;
            while (k % i == 0) {
                st[j] ^= 1LL << t;
                k /= i;
            }
        }
        ++t;
    }
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        map<LL, int> mp;
        ++mp[0];
        LL ans = 0;
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] ^ st[a[i]];
            ans += mp[pre[i]];
            ++mp[pre[i]];
        }
        cout << ans << endl;
    }
    return 0;
}