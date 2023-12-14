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

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

int n, m, a, x[N], y[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> a;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> y[i];
    }
    sort(y + 1, y + m + 1);
    for (int i = 1; i <= n; ++i) {
        if (x[i] == a) {
            continue;
        }
        auto p = lower_bound(y + 1, y + m + 1, x[i]) - y;
        if (x[i] < a) {
            --p;
            if (1 <= p && p <= m) {
                a = x[i];
            } else {
                a = y[p];
            }
        } else {
            if (1 <= p && p <= m) {
                a = x[i];
            } else {
                a = y[p];
            }
        }
    }
    cout << a << endl;

    return 0;
}

/*
1 1 3
1
2

*/