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

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, m;
PII a[N];

int main() {
    cin >> n >> m;
    LL total = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
        total += a[i].first;
    }
    sort(a + 1, a + n + 1, [&](const PII& a, const PII& b) {
        return a.first - a.second > b.first - b.second;
    });
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (total <= m) {
            break;
        }
        ++ans;
        total = total - a[i].first + a[i].second;
    }
    if (total > m) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}