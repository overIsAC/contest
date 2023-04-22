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

int n, m, k;
int p[N], r[N];
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        cin >> p[i];
        cnt[p[i]] = 1;
    }
    for (int i = 1; i <= k; ++i) {
        cin >> r[i];
    }
    sort(r + 1, r + k + 1);
    k = unique(r + 1, r + k + 1) - r - 1;
    int temp = m;

    auto add = [&](int p, int v) {
        for (int i = p; i <= n; i += p) {
            temp -= !!cnt[i];
            cnt[i] += v;
            temp += !!cnt[i];
        }
    };

    int ans = 1e9;

    for (int i = 1, j = 1; i <= k; ++i) {
        add(r[i], 1);
        while (temp == n) {
            ans = min(ans, r[i] - r[j]);
            add(r[j], -1);
            ++j;
        }
        // cout << i << ' ' << j << ' ' << r[i] << ' ' << r[j] << ' ' << temp << endl;
    }
    if (ans == 1e9) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}