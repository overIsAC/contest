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
int m, p1, s1, s2;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> m >> p1 >> s1 >> s2;

    a[p1] += s1;

    LL cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += (LL)(m - i) * a[i];
    }
    LL ans = 1e18;
    int p = 0;
    for (int i = 1; i <= n; ++i) {
        if (ans > abs(cnt + (LL)(m - i) * s2)) {
            p = i;
            ans = abs(cnt + (LL)(m - i) * s2);
        }
    }
    cout << p << endl;
    return 0;
}