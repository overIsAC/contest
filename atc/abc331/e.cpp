#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using ULL = unsigned long long;

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
const int N = 3 + 1e6;

int n, m, l;
PII a[N], b[N];
set<PII> st;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> l;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i].first;
        b[i].second = i;
    }
    while (l--) {
        int c, d;
        cin >> c >> d;
        st.insert({c, d});
    }
    sort(a + 1, a + n + 1, greater<PII>());
    sort(b + 1, b + m + 1, greater<PII>());
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (st.count({a[i].second, b[j].second})) {
                continue;
            }
            ans = max(ans, a[i].first + b[j].first);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}