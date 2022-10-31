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
const int N = 3 + 2e5;

int n, m, a[N], p[N];
map<PII, int> mp1[2], mp2[2];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    }
    int u = 0, v = 0;
    for (int i = p[m] - 1; i; --i) {
        if (a[i] < i) {
            ++u;
        } else {
            --v;
        }
        mp1[p[m] - i & 1][{u, v}] += 1;
    }
    u = v = 0;
    for (int i = p[m] + 1; i <= n; ++i) {
        if (a[i] < i) {
            ++u;
        } else {
            --v;
        }
        mp2[p[m] - i & 1][{u, v}] += 1;
    }
    for (int i=0; i <= 1; ++i) {
        for (int j= 0; j <= 1; ++j) {
            for (auto &k : mp1[i]) {
                
            }
        }
    }

    cout << ans << endl;

    return 0;
}