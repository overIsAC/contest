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

int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int sum = accumulate(a + 1, a + n + 1, 0);
    int ans = 1e9, cnt = 0;
    for (int i = 1; i < n; ++i) {
        cnt += a[i];
        ans = min(ans, abs(cnt - (sum - cnt)));
    }
    cout << ans << endl;
    return 0;
}