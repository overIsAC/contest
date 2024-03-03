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
const int N = 3 + 1e5;

int main() {
    map<int, int> mp;
    int n;
    cin >> n;
    LL ans = 0;
    int zero = 0;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (a == 0) {
            ans += i - 1;
            ++zero;
            continue;
        }
        ans += zero;
        for (int j = 2; j * j <= a; ++j) {
            while (a % (j * j) == 0) {
                a /= j * j;
            }
        }
        ans += mp[a]++;
    }
    cout << ans << endl;
    return 0;
}