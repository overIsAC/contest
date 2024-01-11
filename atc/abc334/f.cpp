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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 2e5;

int k, n;
int sx, sy, x[N], y[N];
long double dp[N];
long double pre[N];

long double dist(int x1, int y1, int x2, int y2) {
    return sqrtl((LL)(x1 - x2) * (x1 - x2) + (LL)(y1 - y2) * (y1 - y2));
}

int main() {
    cin >> n >> k;
    cin >> sx >> sy;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }

    x[0] = sx;
    y[0] = sy;
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + dist(x[i - 1], x[i], y[i - 1], y[i]);
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = 9e18;
    }
    set<pair<long double, int>> st;
    for (int i = 1; i <= n; ++i) {
        st.insert({dp[i - 1] + dist(x[i - 1], sx, y[i - 1], sy) +
                       dist(x[i], sx, y[i], sy) - pre[i],
                   i});
        while (st.size() && i - st.begin()->second + 1 > k) {
            st.erase(st.begin());
        }
        dp[i] = pre[i] + st.begin()->first;
    }
    cout << fixed << setprecision(10) << dist(x[n], sx, y[n], sy) + dp[n]
         << endl;
    return 0;
}