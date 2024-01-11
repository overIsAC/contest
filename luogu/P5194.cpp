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

int n;
LL c, a[N];
LL suf[N];

LL ans;

void dfs(int p, LL sum) {
    if (sum > c) {
        return;
    }
    ans = max(ans, sum);
    if (sum + suf[p] <= c) {
        ans = max(ans, sum + suf[p]);
    }
    if (sum + suf[p] <= ans) {
        return;
    }

    if (p == n + 1) {
        return;
    }

    dfs(p + 1, sum);
    dfs(p + 1, sum + a[p]);
}

int main() {
    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    while (n && a[n] > c) {
        --n;
    }
    if (!n) {
        cout << 0 << endl;
        return 0;
    }

    reverse(a + 1, a + n + 1);
    for (int i = n; i >= 1; --i) {
        suf[i] = suf[i + 1] + a[i];
    }
    dfs(1, 0);

    cout << ans << endl;

    return 0;
}