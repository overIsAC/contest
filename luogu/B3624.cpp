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

int n, l, r, a[N];
int ans;

void dfs(int p, int sum) {
    if (sum > r) {
        return;
    }
    if (p == n + 1) {
        if (l <= sum && sum <= r) {
            ++ans;
        }
        return;
    }
    dfs(p + 1, sum);
    dfs(p + 1, sum + a[p]);
}

int main() {
    cin >> n >> l >> r;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}