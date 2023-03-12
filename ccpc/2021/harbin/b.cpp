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

int solve(int v) {
    int ans = 0;
    int last = 0, cnt[201] = {};
    for (int i = 1; i <= n; ++i) {
        if (a[i] + 1 > v || a[i] + 100 < v) {
            continue;
        }
        if (cnt[v - a[i]] > last) {
            ++ans;
            last = i;
        } else {
            cnt[a[i]] = i;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 2; i <= 200; ++i) {
        ans = max(ans, solve(i));
    }
    cout << ans * 2 << endl;
    return 0;
}